#include "userdaoimp.h"
#include<string.h>
#include<QSqlQuery>
#include<QDebug>
#include<QSqlError>

UserDaoImp::UserDaoImp()
{

}

bool UserDaoImp::addUser(user_t user)
{
    //将网络编码转化为本地unicode编码
    QString qname = QString::fromLocal8Bit(user.username);
    QString qpasswd = QString::fromLocal8Bit(user.userpasswd);

    DBHelper *helper = DBHelper::getInstance();
    helper->createConn();
    QSqlQuery query;
    query.prepare(
          "insert into tb_user(name, passwd)values(:name, :passwd);");
    query.bindValue(":name", qname);
    query.bindValue(":passwd", qpasswd);
    bool ret = query.exec();
    if(ret ==false){
        const QSqlError& error = query.lastError();
        qDebug() << error.text();
        helper->destoryConn();
        return false;
    }
    helper->destoryConn();
    return true;
}

user_t UserDaoImp::findUser(const QString& name)
{
    user_t user;
    DBHelper *helper = DBHelper::getInstance();
    helper->createConn();
    QSqlQuery query;
    query.exec("select name, passwd from tb_user;");
    while(query.next()){
        QString username = query.value(0).toString();
        QString userpasswd = query.value(1).toString();
        if(name == username){
            char* pname = username.toLocal8Bit().data();
            char* ppasswd = userpasswd.toLocal8Bit().data();
            strncpy(user.username, pname, 20);
            strncpy(user.userpasswd, ppasswd, 20);
            helper->destoryConn();
            return user;
        }
    }
    helper->destoryConn();
    strcpy(user.username, "");
    return user;
}
