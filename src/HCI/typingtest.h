//*****************************************************************************
// CPSC 3770 Human Computer Interaction
// Prof: Kevin Grant
// by: Erin Mackey and Camara Lerner
// header file for TypingTest
//*****************************************************************************
#ifndef TYPINGTEST_H
#define TYPINGTEST_H

#include <QWidget>

class TypingTest : QWidget {
   Q_OBJECT
   public:
   TypingTest(QWidget * parent);
   private:
   Typing *write;

};

#endif
