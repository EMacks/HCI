//*****************************************************************************
// CPSC 3770 Human Computer Interaction
// Prof: Kevin Grant
// by: Erin Mackey and Camara Lerner
// implementation file for MainWindow
//*****************************************************************************
#include "dialogs.h"
#include <QLabel>
#include <QHBoxLayout>

Dialogs::Dialogs(QWidget *parent) : QWidget(parent)
{
   login=new Login(this);
   emTest=new EmotionTest(this);
   data = new Database(this);
   QLabel a("Thanks for participating", this);
   QHBoxLayout lay;
   lay.addWidget(&a);
   setLayout(&lay);
   
   if(data->makeConnection()) {

     // initializing the quote to be displayed in the typing test
     connect(this, SIGNAL(getQuote(int)), data, SLOT(getQuote(int)));
     connect(data, SIGNAL(setQuote(const QString&)), this,
	     SLOT(setQuote(const QString&)));

     srand(time(NULL));
     emit getQuote(rand() % 42);
    

      // checks the username and password combination
      connect(login, SIGNAL(info(const QString&, const QString&)),
	      data, SLOT(login(const QString&, const QString&)));
      // if the username and password are valid then closes dialog
      connect(data, SIGNAL(acceptLogin(bool)), login, 
	      SLOT(acceptedInfo(bool)));

      // moves onto the EmotionTest
      connect(login, SIGNAL(accepted()), emTest, SLOT(exec()));
      // giving the emotionTest results to the database
      connect(emTest, SIGNAL(results(const QList<EmotionRank*>&)),
	      data, SLOT(Emotions(const QList<EmotionRank*>&)));
      // if test results are put into the database then closes dialog
      connect(data, SIGNAL(acceptEmotions(bool)), emTest,
	      SLOT(acceptedInfo(bool)));
   
      // moves onto the TypingTest
      connect(emTest, SIGNAL(accepted()), tyTest, SLOT(exec()));

      //getting previous TypingTest results
      connect(tyTest, SIGNAL(findPrevious()), data, SLOT(previousTyping()));
      connect(data, SIGNAL(previousTypingResults(const QList<KeyFeatures>&)),
	      tyTest, SLOT(inputKeyFeatures(const QList<KeyFeatures>&)));
      
      
      //giving the TypingTest results to the database
      connect(tyTest, SIGNAL(results(const KeyFeatures&)), data,
	      SLOT(Typing(const KeyFeatures&)));
      // if test results are put into the database then closes dialog
      connect(data, SIGNAL(acceptTyping(bool)), tyTest,
	      SLOT(acceptedInfo(bool)));
      // closes everything
      connect(tyTest, SIGNAL(accepted()), data, SLOT(makeTest()));

      login->exec();

     }
}

void Dialogs::setQuote(const QString & a) {
  tyTest=new TypingTest(a, this);
}
