//*****************************************************************************
// CPSC 3770 Human Computer Interaction
// Prof: Kevin Grant
// by: Erin Mackey and Camara Lerner
// implementation file for TypingTest
//*****************************************************************************
#include "typingtest.h"
#include "quotes.cpp"
#include <cstdlib>
#include <QLabel>
#include <QVBoxLayout>
#include <iostream>
#include <time.h>
#include <QMessageBox>

TypingTest::TypingTest(const QString& a, QWidget * parent) : QDialog(parent) {
  quote = a;
  explain = new QLabel("Please type the following:");
  text = new QLabel(quote);
  text->setWordWrap(true);
  write = new Typing(text->text(), 0);
  connect(write,SIGNAL(finished(const QVector<int>&,
				const QVector<long long>&,
				const QVector<long long>&)),
	  this, SLOT(calculate(const QVector<int>&,
			       const QVector<long long>&,
			       const QVector<long long>&))); 
  connect(this, SIGNAL(accepted()), this, SLOT(close()));
  QVBoxLayout *layout = new QVBoxLayout(this);
  layout->addWidget(explain);
  layout->addWidget(text);
  layout->addWidget(write);
  
  setLayout(layout);
}

void TypingTest::calculate(const QVector<int> &key,
			   const QVector<long long> &press,
			   const QVector<long long> &release) {
  emit findPrevious();
  int latest = analysis.dataSize();   
  analysis.addKeyFeature(key, press, release);
  if(analysis.isTired(latest)) {
    std::cerr << "you are apparently tired" << std::endl;
  } else {
    std::cerr << "apparently you are not tired" << std::endl;
  }
  emit results(analysis.results(latest));
}

void TypingTest::acceptedInfo(bool a) {
  if(a) {
    emit accepted();
  } else {
    QMessageBox::warning(this, tr("database connection problems"),
			 tr("The database is not able to accept the data"));
  }
}

void TypingTest::inputKeyFeatures(const QList<KeyFeatures>& a) {
  for(int i = 0; i < a.size(); i++)
    analysis.addKeyFeature(a[i]);
}
