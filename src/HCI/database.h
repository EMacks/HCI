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
   void makeTest();

  signals:
   void acceptLogin(bool);
   void acceptEmotions(bool);
   void acceptTyping(bool);
   void previousTypingResults(const QList<KeyFeatures>&);

   public slots:
   void login(const QString& username, const QString& password);
   void Emotions(const QList<EmotionRank*>&);
   void Typing(const KeyFeatures&);
   void previousTyping();

  private:
   QString username;
   int emoID, typingID, inputStringID;
};
#endif
