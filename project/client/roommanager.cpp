#include "roommanager.h"

RoomManager* RoomManager::instance = 0;
QMutex RoomManager::mutex;


/*
函数功能：构造函数
参数：无
返回值：无
*/
RoomManager::RoomManager()
{

}


/*
函数功能：构造函数
参数：无
返回值：无
*/
RoomManager* RoomManager::getInstance()
{
    if(instance == 0){
        mutex.lock();
        if(instance == 0){
            instance = new RoomManager();
        }
        mutex.unlock();
    }
    return instance;
}


/*
函数功能：添加房间
参数：const QString& room
返回值：无
*/
void RoomManager::insertRoom(const QString& room)
{
    rooms.push_back (room);
}

/*
函数功能：删除房间
参数：const QString& room
返回值：无
*/
void RoomManager::eraseRoom(const QString& room)
{
    vector<QString>::iterator it;
    for(it = rooms.begin (); it != rooms.end (); ++it){
        QString curRoom = *it;
        if(curRoom == room){
            rooms.erase (it);
            break;
        }
    }
}


/*
函数功能：获取所有房间
参数：无
返回值：vector<QString>
*/
vector<QString> RoomManager::getAllRoom()const
{
    return rooms;
}


/*
函数功能：查找房间
参数：const QString& room
返回值：bool
*/
bool RoomManager::findRoom(const QString& room)
{
    vector<QString>::iterator it;
    for(it = rooms.begin (); it != rooms.end (); ++it){
        QString curRoom = *it;
        if(curRoom == room){
            return true;
        }
    }
    return false;
}
