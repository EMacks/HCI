//*****************************************************************************
// CPSC 3770 Human Computer Interaction
// Prof: Kevin Grant
// by: Erin Mackey and Camara Lerner
// header file for Typing
//*****************************************************************************
#ifndef TYPING_H
#define TYPING_H

#include <QTextEdit>
#include <QTime>
#include <QMouseEvent>

class QKeyEvent;

class Typing : public QTextEdit {
   Q_OBJECT
  public:
   Typing(QString m="", QWidget * parent=0);
  protected:
   virtual void keyPressEvent(QKeyEvent * event);
   virtual void keyReleaseEvent(QKeyEvent * event);

  signals:
   void finished(const QVector<int>&, const QVector<int>&, const QVector<int>&);

 protected:
   virtual void mousePressEvent(QMouseEvent*) {}
   virtual void mouseMoveEvent(QMouseEvent*) {}
   virtual void mouseReleaseEvent(QMouseEvent*) {}
   virtual void grabMouse() {}
   
  private:
   QString toMatch;
   QTime *time;
   int atChar;
   QVector<int> key;
   QVector<int> press;
   QVector<int> release;
};

#endif
