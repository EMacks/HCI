//*****************************************************************************
// CPSC 3770 Human Computer Interaction
// Prof: Kevin Grant
// by: Erin Mackey and Camara Lerner
// header file for MainWindow
//*****************************************************************************
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "emotiontest.h"
#include "typingtest.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
private:
    EmotionTest *emTest;
    TypingTest *tyTest;
};

#endif // MAINWINDOW_H
