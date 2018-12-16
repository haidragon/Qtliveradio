#include "dbhelper.h"

DBHelper* DBHelper::instance = 0;

DBHelper* DBHelper::getInstance()
{
    if(instance == 0){
        instance = new DBHelper();
    }
    return instance;
}

DBHelper::DBHelper()
{
    db = QSqlDatabase::addDatabase("QSQLITE");

}

void DBHelper::createConn()
{
/*    db.setHostName("localhost");
    db.setDatabaseName("cyc");
    db.setUserName("root");
    db.setPassword("123");
*/
    db.setDatabaseName("user.db");
    db.open();
}
void DBHelper::destoryConn()
{
    db.close();
    db.removeDatabase("user.db");
}
