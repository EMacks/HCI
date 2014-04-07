//*****************************************************************************
// CPSC 3770 Human Computer Interaction
// Prof: Kevin Grant
// by: Erin Mackey and Camara Lerner
// header file for Login
//*****************************************************************************
#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QLineEdit>
#include "database.h"

class Login : public QDialog {
   Q_OBJECT
  public:
   Login(QWidget *parent=0);
  signals:
   void info(const QString& username, const QString& password);
  public slots:
   void returnInfo();
   void acceptedInfo(bool);
  private:
   QLineEdit *username;
   QLineEdit *password;
   QPushButton *submit;
};

#endif
