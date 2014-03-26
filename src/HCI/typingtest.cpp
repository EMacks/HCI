#include "typingtest.h"
#include "quotes.cpp"
#include <cstdlib>
#include <QLabel>
#include <QVBoxLayout>
#include <iostream>

TypingTest::TypingTest(QWidget * parent) : QWidget(parent) {
   srand(time(NULL));
   explain = new QLabel("Please type the following:");
   text = new QLabel(QUOTES[rand() % 42]);
   text->setWordWrap(true);
   write = new Typing(text->text(), 0);

   connect(write,SIGNAL(finished(const QVector<int>&, const QVector<int>&,
				 const QVector<int>&)),
	   this, SLOT()); 

   QVBoxLayout *layout = new QVBoxLayout(this);
   layout->addWidget(explain);
   layout->addWidget(text);
   layout->addWidget(write);

   setLayout(layout);
   
}

void calculate(const QVector<int> &key, const QVector<int> &press,
	       const QVector<int> &release) {
   addKeyFeature(key, press, release);
   if(isTried(1)) {
      std::cerr << "you are apparently tired" << std::endl;
   } else {
      std::cerr << "apparently you are not tired" << std::endl;
   }

}
