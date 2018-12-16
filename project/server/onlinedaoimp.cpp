#include "onlinedaoimp.h"
#include<QSqlQuery>
#include<QSqlError>
#include<QDebug>

OnlineDaoImp::OnlineDaoImp()
{

}

bool OnlineDaoImp::addOnline(QString& name)
{
    DBHelper *helper = DBHelper::getInstance();
    helper->createConn();
    QSqlQuery query;
    query.prepare("insert into online(name)values(:name);");
    query.bindValue(":name", name);
    bool ret = query.exec();
    if(ret == false){
        const QSqlError& error = query.lastError();
        qDebug() << error.text();
        helper->destoryConn();
        return false;
    }
    helper->destoryConn();
    return true;
}

char* OnlineDaoImp::findOnline(QString& name)
{
    DBHelper *helper = DBHelper::getInstance();
    helper->createConn();
    QSqlQuery query;
    query.exec("select name from online;");
    while(query.next()){
        QString username = query.value(0).toString();
        if(username == name){
            static char *pname = username.toLocal8Bit().data();
            helper->destoryConn();
            return pname;
        }
    }
    helper->destoryConn();
    return NULL;
}

bool OnlineDaoImp::delOnline(QString& name)
{
    DBHelper *helper = DBHelper::getInstance();
    helper->createConn();
    QSqlQuery query;
    query.prepare("delete from online where name = :name;");
    query.bindValue(":name", name);
    bool ret = query.exec();
    if(ret == false){
        const QSqlError& error = query.lastError();
        qDebug() << error.text();
        helper->destoryConn();
        return false;
    }
    helper->destoryConn();
    return true;
}

vector<QString> OnlineDaoImp::selectOnline()
{
    DBHelper *helper = DBHelper::getInstance();
    helper->createConn();
    QSqlQuery query;
    query.exec("select * from online;");
    while(query.next()){
        QString username = query.value(0).toString();
        onlines.push_back(username);
    }
    helper->destoryConn();
    return onlines;
}
