#include "database.h"

Database::Database(QWidget* parent) : QWidget(parent) {}

bool Database::makeConnection() {
   QStringList drivers = QSqlDatabase::drivers();
   QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
   db.setHostName("hci.c9od6skigiqx.us-west-2.rds.amazonaws.com");
   db.setPort(3306);
   db.setDatabaseName("HCI");
   db.setUserName("sqluser");
   db.setPassword("12curLING*$");
    
   return db.open();
}
void Database::pickQuery(QString s) {
    QSqlQuery query;
    query.exec(s);
    while(query.next())
    {
        int id=query.value(0).toInt();
        QString text=query.value(1).toString();
        qDebug()<<id<<": "<<text;
    }
}

void Database::login(const QString& username, const QString& password) {
   // do database stuff to check if the username and password are a valid combination
   emit acceptLogin(true);
}

void Database::Emotions(const QList<EmotionRank*>& emo) {
   // if the database accepts the information
   emit acceptEmotions(true);
}

void Database::Typing(const KeyFeatures& feat) {
   // if the database accepts the information
   emit acceptTyping(true);
}

void Database::previousTyping() {
   QList<KeyFeatures> a;
   // find the previous tests relating to the user in the database
   emit previousTypingResults(a);
}
