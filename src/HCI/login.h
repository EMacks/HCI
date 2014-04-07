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
   
   private:
   QLineEdit *username;
   QLineEdit *password;

};

#endif
