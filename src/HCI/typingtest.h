//*****************************************************************************
// CPSC 3770 Human Computer Interaction
// Prof: Kevin Grant
// by: Erin Mackey and Camara Lerner
// header file for TypingTest
//*****************************************************************************
#ifndef TYPINGTEST_H
#define TYPINGTEST_H

#include <QDialog>
#include <QPushButton>
#include "typing.h"
#include "analysis.h"

class QLabel;

class TypingTest : public QDialog {
   Q_OBJECT
  public:
   TypingTest(QWidget *parent=0);
  private:
   QLabel *explain;
   QLabel *text;
   Typing *write;
   Analysis analysis;

  signals:
   void results(const KeyFeatures&);
   void findPrevious();
   
   public slots:
   void calculate(const QVector<int>&, const QVector<int>&,
		  const QVector<int>&);
   void acceptedInfo(bool);
   void inputKeyFeatures(const QList<KeyFeatures>&);
};

#endif
