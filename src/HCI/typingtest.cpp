#include "typingtest.h"
#include <cstdlib>
#include <QLabel>
#include <QVBoxLayout>
#include "quotes.cpp"

TypingTest::TypingTest(QWidget * parent) : QWidget(parent) {
   srand(time(NULL));
   explain = new QLabel("Please type the following:");
   text = new QLabel(QUOTES[rand() % 42]);
   text->setWordWrap(true);

   write = new Typing();

   QVBoxLayout *layout = new QVBoxLayout(this);
   layout->addWidget(explain);
   layout->addWidget(text);
   layout->addWidget(write);

   setLayout(layout);
}
