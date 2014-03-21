//*****************************************************************************
// CPSC 3770 Human Computer Interaction
// Prof: Kevin Grant
// by: Erin Mackey and Camara Lerner
// header file for Typing
//*****************************************************************************
#ifndef TYPING_H
#define TYPING_H

#include <QLineEdit>
#include <QTime>

class QKeyEvent;

class Typing : QLineEdit {
   Q_OBJECT
  public:
   Typing(QWidget * parent=0);
  protected:
   virtual void keyPressEvent(QKeyEvent * event);
   virtual void keyReleaseEvent(QKeyEvent * event);
   
  private:
   QTime *time;
   QVector<int> key;
   QVector<int> press;
   QVector<int> release;
};

#endif
