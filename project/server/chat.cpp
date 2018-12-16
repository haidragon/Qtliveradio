#include "chat.h"

Chat::Chat(const QString& username, const QString& roomName, int flag, QTcpSocket* socket)
    :username(username), roomName(roomName),flag(flag), socket(socket)
{


}

Chat::Chat()
{

}

QString Chat::getUserName()const
{
    return username;
}

QString Chat::getRoomName()const
{
    return roomName;
}

int Chat::getFlag ()const
{
    return flag;
}

QTcpSocket* Chat::getSocket ()const
{
    return socket;
}
