//*****************************************************************************
// CPSC 3770 Human Computer Interaction
// Prof: Kevin Grant
// by: Erin Mackey and Camara Lerner
// implementation file for Login
//*****************************************************************************
#include "login.h"
#include <QLabel>
#include <QString>
#include <QVBoxLayout>
#include <QHBoxLayout>

Login::Login(QWidget *parent) : QDialog(parent) {
   QLabel u(QString("username: "), 0);
   QLabel p(QString("password: "), 0);
   username = new QLineEdit();
   password = new QLineEdit();
   password->setEchoMode(QLineEdit::Password);
   QHBoxLayout user, passwd;
   user.addWidget(&u);
   user.addWidget(username);
   passwd.addWidget(&p);
   passwd.addWidget(password);
   QVBoxLayout layout;
   layout.addLayout(&user);
   layout.addLayout(&passwd);
   setLayout(&layout);
   
}
