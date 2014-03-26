#include "typing.h"
#include <QKeyEvent>
#include <iostream>

Typing::Typing(QString m, QWidget * parent) : QLineEdit(parent) {
   toMatch = m;
   time = new QTime();
   time->start();
}

void Typing::keyPressEvent(QKeyEvent * event) {
   key.push_back(event->key());
   press.push_back(time->elapsed());
   release.resize(press.size());
   //std::cout << "key pressed at: " << press[press.size()-1] << std::endl;
}

void Typing::keyReleaseEvent(QKeyEvent * event) {
   int tmp = time->elapsed();
   int i;
   for(i = key.size()- 1; i >= 0; --i) {
      if(event->key() == key[i])
	 break;
   }
   if(i >= 0) {
      release[i] = tmp;
      //std::cout << "released at: " << release[i] << std::endl;
   }
   QLineEdit::keyPressEvent(event);
   if(toMatch == text())
      emit finished(key, press, release);
}
