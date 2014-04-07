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

class Dialogs : public QWidget
{
    Q_OBJECT
    
public:
    Dialogs(QWidget *parent = 0);
private:
    Login *login;
    EmotionTest *emTest;
    TypingTest *tyTest;
};

#endif 
