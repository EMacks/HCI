//*****************************************************************************
// CPSC 3770 Human Computer Interaction
// Prof: Kevin Grant
// by: Erin Mackey and Camara Lerner
// header file for TypingTest
//*****************************************************************************
#ifndef TYPINGTEST_H
#define TYPINGTEST_H

#include <QWidget>
#include <QPushButton>
#include "typing.h"
#include "analysis.h"

class QLabel;

class TypingTest : public QWidget {
   Q_OBJECT
  public:
   TypingTest(QWidget *parent=0);
  private:
   QLabel *explain;
   QLabel *text;
   Typing *write;
   Analysis analysis;

   public slots:
   void calculate(const QVector<int>&, const QVector<int>&,
		  const QVector<int>&);
};

#endif
