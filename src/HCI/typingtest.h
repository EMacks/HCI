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
#include "tiredanalysis.h"

class QLabel;

class TypingTest : public QWidget {
   Q_OBJECT
  public:
   TypingTest(QWidget *parent=0);
  private:
   QLabel *explain;
   QLabel *text;
   Typing *write;
   TiredAnalysis analysis;
   QPushButton *submit;
   public slots:
   void calculate(const QVector<long long>&, const QVector<long long>&,
		  const QVector<long long>&);
};

#endif
