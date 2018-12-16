#include "clientsocket.h"
#include"socketmanager.h"
//#include"chatdaoimp.h"
#include"chatmanager.h"

QMutex ClientSocket::mutex1;
QMutex ClientSocket::mutex2;

ClientSocket::ClientSocket(QTcpSocket *socket, QObject *parent)
    : QObject(parent),socket(socket)
{
    QObject::connect(socket, SIGNAL(readyRead()),
                     this, SLOT(onReadyRead()));
}

ClientSocket::~ClientSocket(){
    UserDao *ud = new UserDaoImp();
    OnlineDao *od = new OnlineDaoImp();
    delete ud;
    delete od;
}


QTcpSocket* ClientSocket::getSocket ()const
{
    return socket;
}

//接收客户端发过来的协议包
void ClientSocket::onReadyRead()
{
    user_t user;
    memset(&user, 0, sizeof(user));
    while(socket->read((char*)&user, sizeof(user))> 0){
        switch(user.type){
            case REG:
                server_reg(user);       //注册
            break;
            case LOGIN:
                server_login (user);    //登录
            break;
            case EXIT:
                server_exit(user);    //用户下线
            break;
            case ROOMNAME:
                server_roomName(user);  //聊天室列表
            break;
            case ROOMLIST:
                server_roomList(user);  //刷新聊天室
            break;
            case CHATNAME:
                server_chatName (user); //用户列表
            break;
            case CHATLIST:
                server_chatList (user); //刷新用户列表
            break;
            case QUIT:
                server_quit(user);      //退出聊天室
            break;
            case TEXT:
                server_chatText (user);  //文字聊天
            break;
            case VIDEO:
                server_chatText (user);     //视频聊天
            break;
            case UNVIDEO:
                server_chatText (user);     //关闭视频
            break;
            case BS:
                server_chatText (user);     //弹幕聊天
            break;
            default:break;
        }
    }
}

//注册
void ClientSocket::server_reg(user_t user)
{
    UserDao *ud = new UserDaoImp();
    QString pname = QString::fromLocal8Bit(user.username);
    mutex1.lock();
    user_t myuser = ud->findUser(pname);
    mutex1.unlock();
    if(myuser.username[0] != '\0'){
        strcpy(user.data, "用户名已存在");
    }
    else{
        mutex1.lock();
        if(ud->addUser(user)){
            strcpy(user.data, "注册成功");
        }
        else{
            strcpy(user.data, "注册失败");
        }
        mutex1.unlock();
    }
    emit this->sigWrite(socket, user, sizeof(user));
}

//登录
void ClientSocket::server_login(user_t user)
{
    UserDao *ud = new UserDaoImp();
    QString pname = QString::fromLocal8Bit(user.username);
    OnlineDao *od = new OnlineDaoImp();
    mutex1.lock();
    user_t myuser = ud->findUser(pname);
    mutex1.unlock();
    if(myuser.username[0] == '\0'){
        strcpy(user.data, "用户名不存在");
    }
    else{
        if(strcmp(myuser.userpasswd, user.userpasswd) == 0){
            mutex2.lock();
            char *ptr = od->findOnline(pname);
            mutex2.unlock();
            if(ptr != NULL){
                strcpy(user.data, "该用户已在线");
            }
            else{
                mutex2.lock();
                od->addOnline(pname);
                mutex2.unlock();
                strcpy(user.data, "登陆成功");
                user.flag = UP;
            }
        }
        else{
            strcpy(user.data, "密码错误");
        }
    }
    emit this->sigWrite(socket, user, sizeof(user));
}

//用户下线
void ClientSocket::server_exit(user_t user)
{
    OnlineDao *od = new OnlineDaoImp();
    QString pname = QString::fromLocal8Bit(user.username);
    QString proom = QString::fromLocal8Bit(user.roomName);
    mutex2.lock();
    od->delOnline(pname);
    mutex2.unlock();
    if(user.flag == MASTER){    //当房主退出客户端时，通知房间里的其他人离开房间
        ChatManager *cm = ChatManager::getInstance();
        vector<Chat> rooms = cm->getAllChat();
        vector<Chat>::iterator it;
        for(it = rooms.begin(); it != rooms.end(); it++){
            Chat mychat = *it;
            if(mychat.getRoomName() == proom){
                QTcpSocket *every_socket = mychat.getSocket();
                emit this->sigWrite (every_socket, user, sizeof(user_t));
            }
        }
    }
}

//刚进入二级菜单时将用户名作为聊天室名发送给所有在线用户
void ClientSocket::server_roomName (user_t user)
{
    SocketManager *sockets = SocketManager::getInstance ();
    vector<ClientSocket*> clients = sockets->getAllSocket ();
    vector<ClientSocket*>::iterator it;
    for(it = clients.begin (); it != clients.end (); it++){
        ClientSocket *client = *it;
        QTcpSocket *every_socket = client->getSocket ();
        emit this->sigWrite (every_socket, user, sizeof(user_t));
    }
}

//刚进入聊天室时将用户名添加到所有聊天室内成员的聊天室列表
void ClientSocket::server_chatName (user_t user)
{
    QString username = QString::fromLocal8Bit (user.username);
    QString roomName = QString::fromLocal8Bit (user.roomName);
    Chat chat(username, roomName, user.flag, socket);
    ChatManager *cm = ChatManager::getInstance ();
    cm->insertChat (chat);
    vector<Chat> rooms = cm->getAllChat ();
    vector<Chat>::iterator it;
    for(it = rooms.begin (); it != rooms.end (); ++it){
        Chat mychat = *it;
        if(mychat.getRoomName () == roomName){
            QTcpSocket* every_socket = mychat.getSocket ();
            emit this->sigWrite (every_socket, user, sizeof(user_t));
        }
    }
}

//实现文字聊天
void ClientSocket::server_chatText (user_t user)
{
    QString roomName = QString::fromLocal8Bit (user.roomName);
    ChatManager *cm = ChatManager::getInstance ();
    vector<Chat> rooms = cm->getAllChat ();
    vector<Chat>::iterator it;
    for(it = rooms.begin (); it != rooms.end (); ++it){
        Chat chat = *it;
        if(chat.getRoomName () == roomName){
            user.flag = chat.getFlag ();
            QTcpSocket *every_socket = chat.getSocket ();
            emit this->sigWrite (every_socket, user, sizeof(user_t));
        }
    }
}


//刷新聊天室列表
 void ClientSocket::server_roomList(user_t user)
 {    
     OnlineDao *od = new OnlineDaoImp();
     vector<QString> v_name = od->selectOnline ();
     vector<QString>::iterator it;
     for(it = v_name.begin (); it != v_name.end (); ++it){
         QString q_name = *it;
         QByteArray ba_name = q_name.toLocal8Bit ();
         char* c_name = ba_name.data ();
         strncpy(user.roomName, c_name, 20);
         emit this->sigWrite (socket, user, sizeof(user_t));
     }
 }

//刷新聊天室用户列表
 void ClientSocket::server_chatList(user_t user)
 {
     QString roomName = QString::fromLocal8Bit (user.roomName);
     ChatManager *cm = ChatManager::getInstance ();
     vector<Chat> rooms = cm->getAllChat ();
     vector<Chat>::iterator it;
     for(it = rooms.begin (); it != rooms.end (); ++it){
         Chat chat = *it;
         if(chat.getRoomName () == roomName){
             QString qname = chat.getUserName ();
             QByteArray ba_name = qname.toLocal8Bit ();
             char *c_name = ba_name.data ();
             strncpy(user.chatname, c_name, 20);
             user.flag = chat.getFlag ();
             emit this->sigWrite (socket, user, sizeof(user_t));
         }
     }
}

 //退出聊天室处理
void ClientSocket::server_quit(user_t user)
{
    QString name = QString::fromLocal8Bit (user.username);
    ChatManager *cm = ChatManager::getInstance ();
    cm->eraseChat (name);
}
