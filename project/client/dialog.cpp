#include "dialog.h"
#include "ui_dialog.h"
#include<QMessageBox>
#include"roommanager.h"

/*
函数功能：构造函数
参数：ClientSocket *cs, QTcpSocket *socket, user_t user, QWidget *parent
返回值：无
*/
Dialog::Dialog(ClientSocket *cs, QTcpSocket *socket, user_t user, QWidget *parent) :
    cs(cs), socket(socket),
    user(user), QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    this->setStyleSheet ("background-image:url(:/image/image/pic2.png)");
    ui->chatroom->setStyleSheet ("background-image:url(:/image/image/skin.jpg)");
    ui->exit_btn->setFlat (true);
    ui->roomlist_btn->setFlat (true);
    ui->destory->setFlat (true);
    QPixmap flash(":/image/image/icon/flash.jpg");
    QPixmap close(":/image/image/icon/close.png");
    QPixmap exit(":/image/image/icon/exit.png");
    ui->roomlist_btn->setIcon (flash);
    ui->roomlist_btn->setIconSize (QSize(20,20));
    ui->exit_btn->setIcon (close);
    ui->exit_btn->setIconSize (QSize(35,35));
    ui->destory->setIcon (exit);
    ui->destory->setIconSize (QSize(35,35));

    QString str = "当前用户：";
    str += QString::fromLocal8Bit(user.username);
    QListWidgetItem *item = new QListWidgetItem(QIcon(":/image/image/user/user.jpg"),
                                                str, ui->user);
    item->setTextColor(QColor(Qt::blue));
    ui->user->setFont(QFont("Timers", 12 , QFont::Bold));
    ui->user->setStyleSheet ("background-image:url()");
    ui->user->setFrameShape(QListWidget::NoFrame);

    ui->user->setIconSize(QSize(80,80));
    ui->user->addItem(item);
    //显示聊天室列表
    showRoomName();
    QObject::connect (cs, SIGNAL(sigRoomName(user_t)),
                      this, SLOT(onsigRoomName(user_t)));
    //刷新聊天室
    QObject::connect (cs, SIGNAL(sigRoomList(user_t)),
                      this, SLOT(onsigRoomList(user_t)));

}

/*
函数功能：析构函数
参数：无
返回值：无
*/
Dialog::~Dialog()
{
    delete ui;
    RoomManager *rm = RoomManager::getInstance ();
    delete rm;
}



/*
函数功能：显示聊天室列表
参数：无
返回值：无
*/
void Dialog::showRoomName()
{
    user.type = ROOMNAME;
    socket->write((char*)&user, sizeof(user));
}

/*
函数功能：关闭窗口
参数：QCloseEvent*
返回值：无
*/
void Dialog::closeEvent (QCloseEvent *)
{
    user.type = EXIT;
    socket->write ((char*)&user, sizeof(user_t));
    QMessageBox::information(this, "提醒", "感谢您的使用，欢迎下次再来");
}

/*
函数功能：刚进入房间时显示列表
参数：user_t user
返回值：无
*/
void Dialog::onsigRoomName(user_t user)
{
    if((user.flag != UP)&&(user.flag != MASTER)){
        return;
    }
    QString roomName = QString::fromLocal8Bit (user.username);
    QListWidgetItem *item = new QListWidgetItem(QIcon(":/image/image/user/room1.jpg"), roomName, ui->chatroom);
    ui->chatroom->setIconSize(QSize(36,36));
    ui->chatroom->addItem (item);

}

/*
函数功能：双击进入房间
参数：QListWidgetItem *item
返回值：无
*/
void Dialog::on_chatroom_itemDoubleClicked(QListWidgetItem *item)
{
    QString qitem = item->text ();
    RoomManager *rm = RoomManager::getInstance ();
    if(rm->findRoom (qitem)){
        QMessageBox::warning (this, "警告", "不可重复进入房间");
        return;
    }
    rm->insertRoom (qitem);
    QByteArray ba_item = qitem.toLatin1 ();
    char* master = ba_item.data ();
    QString username = QString::fromLocal8Bit(user.username);
    if(qitem == username){
        user.flag = MASTER;  //代表是房主
    }
    strncpy(user.roomName, master, 20);
    QString str = "欢迎来到聊天室：";
    str += qitem;
    strncpy(user.roomName, master,20);
    chatroom = new ChatRoom(cs, socket, qitem, user, this);
    chatroom->setWindowTitle (str);
    chatroom->show();
}

/*
函数功能：切换按钮
参数：无
返回值：无
*/
void Dialog::on_destory_clicked()
{
    QMessageBox::StandardButton sb = QMessageBox::information (this, "提示",
                    "切换后将丢失当前用户信息，是否切换？", QMessageBox::Yes, QMessageBox::No);
    if(sb == QMessageBox::Yes){
        user.type = EXIT;
        socket->write ((char*)&user, sizeof(user_t));
        qDebug()<<"type = "<<user.type;
        QWidget *parent = this->parentWidget ();
        parent->show ();
        this->hide ();
    }
}

/*
函数功能：退出按钮
参数：无
返回值：无
*/
void Dialog::on_exit_btn_clicked()
{
    QMessageBox::StandardButton sb = QMessageBox::information (this, "提示",
                    "是否退出？", QMessageBox::Yes, QMessageBox::No);
    if(sb == QMessageBox::Yes){
        user.type = EXIT;
        socket->write ((char*)&user, sizeof(user_t));
        qDebug()<<"type = "<<user.type;
        this->close ();
    }
}

/*
函数功能：刷新房间列表
参数：无
返回值：无
*/
void Dialog::on_roomlist_btn_clicked()
{
    ui->chatroom->clear ();
    user.type = ROOMLIST;
    socket->write((char*)&user, sizeof(user));
}

/*
函数功能：显示房间列表
参数：QListWidgetItem *item
返回值：无
*/
void Dialog::onsigRoomList(user_t user)
{
    QString roomName = QString::fromLocal8Bit (user.roomName);
    QListWidgetItem *item = new QListWidgetItem(QIcon(":/image/image/user/room1.jpg"), roomName, ui->chatroom);
    ui->chatroom->setIconSize(QSize(36,36));
    ui->chatroom->addItem (item);
}

