#ifndef CHATMANAGER_H
#define CHATMANAGER_H

#include"chat.h"
#include<QMutex>
#include<vector>
using namespace std;

class ChatManager
{
public:
    static ChatManager* getInstance();
    void insertChat(const Chat& chat);
    void eraseChat(const QString& name);
    vector<Chat> getAllChat()const;
private:
    static ChatManager* instance;
    ChatManager();
    vector<Chat> chatrooms;
    static QMutex mutex;
};

#endif // CHATMANAGER_H
