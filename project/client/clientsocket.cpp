#include "clientsocket.h"
#include<string.h>
#include<QDebug>
#include"chatroom.h"


/*
函数功能：构造函数
参数：ClientSocket(QTcpSocket *socket, QObject *parent)
返回值：无
*/
ClientSocket::ClientSocket(QTcpSocket *socket, QObject *parent)
    : QObject(parent), socket(socket)
{
    //接收服务器返回的数据包，并执行相应的槽函数
    QObject::connect(socket, SIGNAL(readyRead()),
                     this, SLOT(onReadyRead()));
}


/*
函数功能：读取服务器返回来的协议包
参数：无
返回值：无
*/
void ClientSocket::onReadyRead()
{ 
    user_t user;
    memset(&user, 0, sizeof(user));
    while(socket->read((char*)&user, sizeof(user)) > 0){
        switch(user.type){
            case REG:   //注册
                emit sigReg(user);
            break;
            case LOGIN: //登录
                emit sigLogin(user);
            break;
            case ROOMNAME://刚进入时聊天列表
                emit sigRoomName(user);
            break;
            case ROOMLIST://刷新聊天室列表
                emit sigRoomList(user);
            break;
            case CHATNAME://刚进入聊天室时用户列表
                emit sigChatName(user);
            break;
            case CHATLIST://刷新用户列表
                emit sigChatList(user);
            break;
            case EXIT://退出客户端
                emit sigMasterExit(user);
            break;
            case TEXT://文字聊天
                emit sigChatText(user);
            break;
            case VIDEO://开启直播
                emit sigVideo(user);
            break;
            case UNVIDEO://关闭直播
                emit sigunVideo(user);
            break;
            case BS://弹幕
                emit sigBs(user);
            break;
        default:break;
        }
    }
}
