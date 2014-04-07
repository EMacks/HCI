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

class Database {
  public:
   bool makeConnection();
   void pickQuery(QString s);
   bool DOTHIS();
};
#endif
