#include "typingtest.h"
#include "quotes.cpp"
#include <cstdlib>
#include <QLabel>
#include <QVBoxLayout>
#include <iostream>
#include <time.h>

TypingTest::TypingTest(QWidget * parent) : QWidget(parent) {
   srand(time(NULL));
   explain = new QLabel("Please type the following:");
   text = new QLabel(QUOTES[rand() % 42]);
   text->setWordWrap(true);
   write = new Typing(text->text(), 0);
   submit = new QPushButton("Submit", 0);
   submit->setEnabled(false);
   connect(write,SIGNAL(finished(const QVector<long long>&,
				 const QVector<long long>&,
				 const QVector<long long>&)),
	   this, SLOT(calculate(const QVector<long long>&,
				const QVector<long long>&,
				const QVector<long long>&))); 
   connect(write, SIGNAL(close(bool)), submit, SLOT(setEnabled(bool)));
   connect(submit,SIGNAL(clicked()), write, SLOT(submit())); 
   QVBoxLayout *layout = new QVBoxLayout(this);
   layout->addWidget(explain);
   layout->addWidget(text);
   layout->addWidget(write);
   layout->addWidget(submit);

   setLayout(layout);
   
}

void TypingTest::calculate(const QVector<long long> &key,
			   const QVector<long long> &press,
			   const QVector<long long> &release) {
   int latest = 0;
   analysis.addKeyFeature(key, press, release);
   if(analysis.isTired(latest)) {
      std::cerr << "you are apparently tired" << std::endl;
   } else {
      std::cerr << "apparently you are not tired" << std::endl;
   }

}
