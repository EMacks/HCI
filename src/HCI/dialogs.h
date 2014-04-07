//*****************************************************************************
// CPSC 3770 Human Computer Interaction
// Prof: Kevin Grant
// by: Erin Mackey and Camara Lerner
// header file for MainWindow
//*****************************************************************************
#ifndef DIALOGS_H
#define DIALOGS_H

#include <QMainWindow>
#include "emotiontest.h"
#include "typingtest.h"
#include "login.h"
#include "database.h"


class Dialogs : public QWidget
{
    Q_OBJECT
    
public:
    Dialogs(QWidget *parent = 0);
 signals:
    void getQuote(int);
    public slots:
    void setQuote(const QString&);

private:
    Login *login;
    EmotionTest *emTest;
    TypingTest *tyTest;
    Database *data;
};

#endif 
