#include "typing.h"
#include <QKeyEvent>

Typing::Typing(QWidget * parent) : QLineEdit(parent) {
   time = new QTime();
   time->start();
}

void Typing::keyPressEvent(QKeyEvent * event) {
   key.push_back(event->key());
   press.push_back(time->elapsed());
   release.resize(press.size());
   QLineEdit::keyPressEvent(event);
}

void Typing::keyReleaseEvent(QKeyEvent * event) {
   int i;
   for(i = key.size()- 1; i >= 0; --i) {
      if(event->key() == key[i])
	 break;
   }
   if(i >= 0)
      release[i] = time->elapsed();
   QLineEdit::keyPressEvent(event);
}
