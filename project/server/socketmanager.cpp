#include "socketmanager.h"

SocketManager* SocketManager::instance = 0;
QMutex SocketManager::mutex;

SocketManager::SocketManager()
{

}

SocketManager* SocketManager::getInstance ()
{
    if(instance == 0){
        mutex.lock();
        if(instance == 0){
            instance = new SocketManager();
        }
        mutex.unlock();
    }
    return instance;
}
void SocketManager::insertSocket(ClientSocket *cs)
{
    sockets.push_back (cs);
}

vector<ClientSocket*> SocketManager::getAllSocket()const
{
    return sockets;
}


