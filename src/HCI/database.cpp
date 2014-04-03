#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>
#include <QSqlError>
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
bool createConnection()
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Driver={SQL Server Native Client 11.0};Server=tcp:l2ud2zp8th.database.windows.net,1433;Database=HCI_PROJECT;Encrypt=yes;Connection Timeout=30;");
    db.setUserName("sqluser@l2ud2zp8th");
    db.setPassword("12curLING*$");
    if (!db.open()) {
            qDebug()<<"Database Error: "<<db.lastError().text();
            return false;
        }
        return true;
}
void selectQuery(QString s)
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

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    if(!createConnection())
    {
        qDebug()<<"fail";
        return 1;
    }
    else
    {
        qDebug()<<"pass";
        selectQuery("SELECT * from InputString");
    }

    return 0;
}
