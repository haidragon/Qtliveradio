#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

#include <QObject>
#include<QTcpSocket>
#include"user.h"
#include"userdaoimp.h"
#include<QDebug>
#include"onlinedaoimp.h"
#include<QMutex>

class ClientSocket : public QObject
{
    Q_OBJECT
public:
    explicit ClientSocket(QTcpSocket *socket, QObject *parent = 0);
    ~ClientSocket();

    void server_reg(user_t user);
    void server_login(user_t user);
    void server_exit(user_t user);
    void server_roomName(user_t user);
    void server_chatName(user_t user);
    void server_roomList(user_t user);
    void server_chatList(user_t user);
    void server_chatText(user_t user);
    void server_quit(user_t user);

    QTcpSocket* getSocket()const;

private:
    QTcpSocket *socket;
    static QMutex mutex1;
    static QMutex mutex2;
signals:
    void sigWrite(QTcpSocket *socket, user_t user, int len);
public slots:
    void onReadyRead();
};

#endif // CLIENTSOCKET_H
