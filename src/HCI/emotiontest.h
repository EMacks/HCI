//*****************************************************************************
// CPSC 3770 Human Computer Interaction
// Prof: Kevin Grant
// by: Erin Mackey and Camara Lerner
// header file for EmotionTest
//*****************************************************************************
#ifndef EMOTIONTEST_H
#define EMOTIONTEST_H

#include <QWidget>
#include <QDialog>
#include <QList>
#include <QRadioButton>
#include <QGridLayout>
#include <QPushButton>
#include "emotionrank.h"

const QString emo[] = {"Happy", "Sad", "Angry", "Frustrated", "Relaxed",
		       "Focused", "Overwhelmed", "Confident", "Hesitant",
		       "Stressed", "Excited", "Distracted", "Bored", "Tired",
		       "Nervous"};

class EmotionTest : public QDialog
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
