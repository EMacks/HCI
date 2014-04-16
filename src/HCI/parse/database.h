//*****************************************************************************
// CPSC 3770 Human Computer Interaction
// Prof: Kevin Grant
// by: Erin Mackey and Camara Lerner
// header file for Database
//*****************************************************************************
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
#include <QWidget>
#include <QList>

#include "keyfeatures.h"
#include "everything.h"
class Database : public QWidget {
   Q_OBJECT
  public:
   Database(QWidget* parent=0);
   bool makeConnection();
   void pickQuery(QString s);
   void getEverything(int expected[6], int result[2]);  

};
#endif
