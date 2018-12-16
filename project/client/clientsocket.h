#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

#include <QObject>
#include<QTcpSocket>
#include"user.h"

class ClientSocket : public QObject
{
    Q_OBJECT
public:
    explicit ClientSocket(QTcpSocket *socket, QObject *parent = 0);

signals:
    void sigReg(user_t user);//注册
    void sigLogin(user_t user);//登录
    void sigRoomName(user_t user);//房间名
    void sigRoomList(user_t user);//房间列表
    void sigChatName(user_t user);//聊天室用户
    void sigChatList(user_t user);//聊天室用户列表
    void sigMasterExit(user_t user);//房主退出
    void sigChatText(user_t user);//文字聊天
    void sigVideo(user_t user);//视频
    void sigunVideo(user_t user);//关闭视频
    void sigBs(user_t user);//弹幕
public slots:
    void onReadyRead();//读取服务器发回来的信息
private:
    QTcpSocket *socket;
};

#endif // CLIENTSOCKET_H
