#ifndef USERDAO_H
#define USERDAO_H

#include"user.h"
#include<QString>

class UserDao
{
public:
    UserDao();
    virtual ~UserDao();
    virtual bool addUser(user_t user) = 0;
    virtual user_t findUser(const QString& name) = 0;
};

#endif // USERDAO_H
