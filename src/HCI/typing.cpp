//*****************************************************************************
// CPSC 3770 Human Computer Interaction
// Prof: Kevin Grant
// by: Erin Mackey and Camara Lerner
// implementation file for Typing
//*****************************************************************************
#include "typing.h"
#include <QKeyEvent>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <QTextCursor>
#include <QMap>

QMap<int, QChar> check;

void dofill() {
   check[(int)Qt::Key_Enter] = QChar('\n');
   for(int i = 0; i < 10; i++)
      check[(int)(Qt::Key_0+i)] = QChar('0'+i);
   for(int i = 0; i < 26; i++)
      check[(int)(Qt::Key_A+i)] = QChar('a'+i);
   check[(int)Qt::Key_Space] = QChar(' ');
   check[(int)Qt::Key_Comma] = QChar(',');
   check[(int)Qt::Key_Minus] = QChar('-');
   check[(int)Qt::Key_Period] = QChar('.');
   check[(int)Qt::Key_Slash] = QChar('/');
   check[(int)Qt::Key_Apostrophe] = QChar('\'');
   check[(int)Qt::Key_Semicolon] = QChar(';');
 }

Typing::Typing(QString m, QWidget * parent) : QTextEdit(parent) {
   dofill();
   toMatch = m;
   for(int i = 0; i < toMatch.size(); i++) {
      if(toMatch[i] == '\n')
	 toMatch[i] = ' ';
   }
   QTextCursor textCursor = this->textCursor();
   textCursor.clearSelection();
   this->setTextCursor(textCursor);
   atChar = 0;
   time = new QTime();
   time->start();
}

void Typing::keyPressEvent(QKeyEvent * event) {
   key.push_back(event->key());
   press.push_back(time->elapsed());
   release.resize(press.size());
   if(key[key.size()-1] == Qt::Key_Backspace && atChar > 0
      && textBackgroundColor() != Qt::red) {
      atChar--;
   } else if(check.contains(key[key.size()-1])
	     && check[key[key.size()-1]] != toMatch[atChar]) {
      setTextBackgroundColor(Qt::red);
   } else if(check.contains(key[key.size()-1])){
      setTextBackgroundColor(Qt::transparent);
      atChar++;
   } else {
      setTextBackgroundColor(Qt::red);
   }
   QTextEdit::keyPressEvent(event);

   

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
   }
   if(toMatch == toPlainText()) {
      emit finished(key, press, release);
      setEnabled(false);
   }
}
