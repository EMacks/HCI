//*****************************************************************************
// CPSC 3770 Human Computer Interaction
// Prof: Kevin Grant
// by: Erin Mackey and Camara Lerner
// header file for Database
//*****************************************************************************
#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>
#include <QSqlError>
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include <QWidget>

#include "emotionrank.h"
#include "keyfeatures.h"

class Database : public QWidget {
   Q_OBJECT
  public:
   Database(QWidget* parent=0);
   bool makeConnection();
   void pickQuery(QString s);
  
  signals:
   void acceptLogin(bool);
   void acceptEmotions(bool);
   void acceptTyping(bool);
   void previousTypingResults(const QList<KeyFeatures>&);
   void setQuote(const QString&);

   public slots:
   void login(const QString& username, const QString& password);
   void Emotions(const QList<EmotionRank*>&);
   void Typing(const KeyFeatures&);
   void previousTyping();
   void getQuote(int);
   void makeTest();
   
  private:
   QString username;
   int emoID, typingID, inputStringID;
};
#endif
