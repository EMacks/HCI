#include "typingtest.h"
#include <cstdlib>
#include <QLabel>
#include "quotes.cpp"

TypingTest::TypingTest(QWidget * parent) : QWidget(parent) {
   srand(time(NULL));
   explain = new QLabel("Please type the following:");
   text = new QLabel(rand() % 42);
   write = new Typing();

   QVBoxLayout *layout = new QVBoxLayout(this);
   layout->addWidget(explain);
   layout->addWidget(text);
   layout->addWidget(write);

   setLayout(layout);
}
