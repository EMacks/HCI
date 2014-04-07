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
#include <QPushButton>
#include <QMessageBox>

Login::Login(QWidget *parent) : QDialog(parent) {
   QLabel *u = new QLabel(QString("username: "), this);
   QLabel *p = new QLabel(QString("password: "), this);
   username = new QLineEdit(this);
   password = new QLineEdit(this);
   submit = new QPushButton("login", this);
   password->setEchoMode(QLineEdit::Password);
   QHBoxLayout *user = new QHBoxLayout(), *passwd = new QHBoxLayout();
   user->addWidget(u);
   user->addWidget(username);
   passwd->addWidget(p);
   passwd->addWidget(password);
   QVBoxLayout *layout = new QVBoxLayout();
   layout->addLayout(user);
   layout->addLayout(passwd);
   layout->addWidget(submit);
   setLayout(layout);

   connect(submit, SIGNAL(clicked()), this, SLOT(returnInfo()));
   connect(this, SIGNAL(accepted()), this, SLOT(close()));
}

void Login::returnInfo() {
   emit info(username->text(), password->text());
}

void Login::acceptedInfo(bool a) {
   if(a) {
      emit accepted();
   } else {
      QMessageBox::warning(this, tr("Invalid Login"),
			   tr("Wrong Username and Password combination"));
   }
}
