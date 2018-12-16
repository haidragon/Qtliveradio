#ifndef ONLINEDAO_H
#define ONLINEDAO_H

#include"dbhelper.h"
#include"user.h"

class OnlineDao
{
public:
    OnlineDao();
    virtual ~OnlineDao();
    virtual bool addOnline(QString& name) = 0;
    virtual char* findOnline(QString& name) = 0;
    virtual bool delOnline(QString& name) = 0;
    virtual vector<QString> selectOnline() = 0;
};

#endif // ONLINEDAO_H
