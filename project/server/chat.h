#ifndef CHAT_H
#define CHAT_H

#include<QString>
#include<QTcpSocket>

class Chat
{
public:
    Chat(const QString& username, const QString& roomName, int flag, QTcpSocket* socket);
    Chat();
    QString getUserName()const;
    QString getRoomName()const;
    int getFlag()const;
    QTcpSocket* getSocket()const;
private:
    QString username;
    QString roomName;
    int flag;
    QTcpSocket *socket;

};

#endif // CHAT_H
