#ifndef USERDAOIMP_H
#define USERDAOIMP_H

#include"userdao.h"
#include"dbhelper.h"


class UserDaoImp : public UserDao
{
public:
    UserDaoImp();
    virtual bool addUser(user_t user);
    virtual user_t findUser(const QString& name);
};

#endif // USERDAOIMP_H
