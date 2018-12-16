#ifndef SOCKETMANAGER_H
#define SOCKETMANAGER_H

#include"clientsocket.h"
#include<QMutex>
#include<vector>
using namespace std;

class SocketManager
{
public:
    static SocketManager* getInstance();
    void insertSocket(ClientSocket *cs);
    vector<ClientSocket*> getAllSocket()const;
private:
    vector<ClientSocket*> sockets;
    static SocketManager* instance;
    static QMutex mutex;
    SocketManager();
};

#endif // SOCKETMANAGER_H
