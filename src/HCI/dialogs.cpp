//*****************************************************************************
// CPSC 3770 Human Computer Interaction
// Prof: Kevin Grant
// by: Erin Mackey and Camara Lerner
// implementation file for MainWindow
//*****************************************************************************
#include "dialogs.h"

Dialogs::Dialogs(QWidget *parent) : QWidget(parent)
{
    emTest=new EmotionTest(this);
    tyTest=new TypingTest(this);

    //login->exec();
    emTest->exec();
    tyTest->show();
    
}

