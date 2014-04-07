#include "database.h"

bool Database::makeConnection() {
   QStringList drivers = QSqlDatabase::drivers();
   qDebug() << drivers;
   QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
   db.setHostName("hci.c9od6skigiqx.us-west-2.rds.amazonaws.com");
   db.setPort(3306);
   db.setDatabaseName("HCI");
   db.setUserName("sqluser");
   db.setPassword("12curLING*$");
    
   return db.open();
}
void Database::pickQuery(QString s) {
    QSqlQuery query;
    query.exec(s);
    while(query.next())
    {
        int id=query.value(0).toInt();
        QString text=query.value(1).toString();
        qDebug()<<id<<": "<<text;
    }
}

bool Database::DOTHIS() {
   if(!makeConnection())
   {
      qDebug()<<"fail";
      return false;
   }
   else
   {
      qDebug()<<"pass";
   }
   return true;
}
