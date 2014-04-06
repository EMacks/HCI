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

class Typing : public QLineEdit {
   Q_OBJECT
  public:
   Typing(QString m="", QWidget * parent=0);
  protected:
   virtual void keyPressEvent(QKeyEvent * event);
   virtual void keyReleaseEvent(QKeyEvent * event);

  signals:
   void finished(const QVector<long long>&, const QVector<long long>&, const QVector<long long>&);
   void close(bool);

   public slots:
   void submit();
   
  private:
   QString toMatch;
   QTime *time;
   QVector<long long> key;
   QVector<long long> press;
   QVector<long long> release;
};

#endif
