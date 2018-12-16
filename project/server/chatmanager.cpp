#include "chatmanager.h"


ChatManager *ChatManager::instance = 0;
QMutex ChatManager::mutex;

ChatManager::ChatManager()
{

}


ChatManager* ChatManager::getInstance()
{
    if(instance == 0){
        mutex.lock();
        if(0 == instance){
            instance = new ChatManager();
        }
        mutex.unlock();
    }
    return instance;
}
void ChatManager::insertChat(const Chat& chat)
{
    chatrooms.push_back (chat);
}

void ChatManager::eraseChat(const QString& name)
{
    vector<Chat>::iterator it;
    for(it = chatrooms.begin (); it != chatrooms.end (); ++it){
        Chat chat = *it;
        if(chat.getUserName () == name){
            chatrooms.erase (it);
            break;
        }
    }
}


vector<Chat> ChatManager::getAllChat()const
{
    return chatrooms;
}
