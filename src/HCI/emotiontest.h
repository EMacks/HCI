//*****************************************************************************
// CPSC 3770 Human Computer Interaction
// Prof: Kevin Grant
// by: Erin Mackey and Camara Lerner
// header file for EmotionTest
//*****************************************************************************
#ifndef EMOTIONTEST_H
#define EMOTIONTEST_H

#include <QWidget>
#include <QList>
#include <QRadioButton>
#include <QGridLayout>
#include <QPushButton>
#include "emotionrank.h"

class EmotionTest : public QWidget
{
   Q_OBJECT
      
public:
   EmotionTest(QWidget *p=0);
public slots:
   void findChecked();
   
private:
   QList<EmotionRank*> emotions;
   QPushButton *submit;
   
};

#endif
