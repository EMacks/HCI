#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>
#include <QSqlError>
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
bool makeConnection()
{
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

void pickQuery(QString s)
{
    QSqlQuery query;
    query.exec(s);
    while(query.next())
    {
        int id=query.value(0).toInt();
        QString text=query.value(1).toString();
        qDebug()<<id<<": "<<text;
    }
}

bool DOTHIS()
{
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

#endif
