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
    QSqlDatabase db=QSqlDatabase::addDatabase("QPSQL");
    //db.setHostName("hci.ccmrejgq3bfa.us-west-2.rds.amazonaws.com");
    db.setHostName("");
    db.setPort(5432);
    db.setDatabaseName("HCI");
    db.setUserName("sqluser");
    db.setPassword("password123");

    return db.open();
//   db.setDatabaseName("Driver={SQL Server Native Client 10.0};Server=tcp:l2ud2zp8th.database.windows.net,1433;Database=HCI_PROJECT;Encrypt=yes;Connection Timeout=30;");
/*    db.setUserName("sqluser@l2ud2zp8th");
    db.setPassword("12curLING*$");
*/
    if (!db.open()) {
            qDebug()<<"Database Error: "<<db.lastError().text();
            return false;
        }
        return true;
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
        //pickQuery("SELECT * from InputString");
    }
    return true;
}

#endif
