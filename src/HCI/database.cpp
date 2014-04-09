//*****************************************************************************
// CPSC 3770 Human Computer Interaction
// Prof: Kevin Grant
// by: Erin Mackey and Camara Lerner
// implementation file for Database
//*****************************************************************************
#include "database.h"
#include "password.h"
#include <iostream>

Database::Database(QWidget* parent) : QWidget(parent) {}

bool Database::makeConnection() {
   QStringList drivers = QSqlDatabase::drivers();
   QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
   db.setHostName("hci.c9od6skigiqx.us-west-2.rds.amazonaws.com");
   db.setPort(3306);
   db.setDatabaseName("HCI");
   db.setUserName("sqluser");
   db.setPassword(PASSWORD);
    
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

void Database::getQuote(int a) {
  QSqlQuery query;
  QString sql = QString("select text from InputString where ID=\'%1\'").arg(a);
  inputStringID=a;
  query.exec(sql);
  query.next();
  QString quote = query.value(0).toString();
  emit setQuote(quote);
}

void Database::login(const QString& username, const QString& password) {
   // do database stuff to check if the username and password are a valid combination
  QSqlQuery query;
  QString sql=QString("select password from User where username=\'%1\';").arg(username);
  this->username = username;
  if(query.exec(sql)) {
    if(query.next()) {
      QString pass = query.value(0).toString();
      emit acceptLogin(pass==password);
    } else
      emit acceptLogin(false);
  } else  
    emit acceptLogin(false);
}

void Database::Emotions(const QList<EmotionRank*>& emo) {
   // if the database accepts the information
   QSqlQuery query;   
   QString search = QString("select max(ID) from EmotionTest");
   query.exec(search);
   emoID = 0;
   while(query.next()) 
     emoID = query.value(0).toInt();
   emoID++;
   QString sql = QString("insert into EmotionTest values(%0, %1, %2, %3, %4, %5, %6, %7, %8, %9, %10, %11, %12, %13, %14, %15)").arg(emoID).arg(emo[0]->findChecked()).arg(emo[1]->findChecked()).arg(emo[2]->findChecked()).arg(emo[3]->findChecked()).arg(emo[4]->findChecked()).arg(emo[5]->findChecked()).arg(emo[6]->findChecked()).arg(emo[7]->findChecked()).arg(emo[8]->findChecked()).arg(emo[9]->findChecked()).arg(emo[10]->findChecked()).arg(emo[11]->findChecked()).arg(emo[12]->findChecked()).arg(emo[13]->findChecked()).arg(emo[14]->findChecked());
   emit acceptEmotions(query.exec(sql));
}

void Database::Typing(const KeyFeatures& feat) {
   // if the database accepts the information
   QSqlQuery query;
   QString search = "select max(ID) from TypingTest";
   query.exec(search);
   typingID = 0;
   while(query.next()) {
      typingID = query.value(0).toInt();
   }
   typingID++;
   QString sql = QString("insert into TypingTest values(%0, %1, %2, %3, %4, %5, %6, %7, %8, %9, %10, %11, %12, %13, %14, %15, %16, %17, %18, %19, %20, %21, %22, %23, %24, %25, %26, %27, %28, %29, %30, %31, %32, %33, %34, %35, %36, %37, %38, %39, %40, %41, %42, %43, %44, %45, %46, %47, %48, %49, %50, %51, %52, %53, %54, %55, %56, %57, %58, %59, %60, %61, %62)").arg(typingID).arg(feat.access_numMistakes()).arg(feat.access_2G_num()).arg(feat.access_2G_1D2D().min).arg(feat.access_2G_1D2D().max).arg(feat.access_2G_1D2D().std).arg(feat.access_2G_1D2D().mean).arg(feat.access_2G_1Dur().min).arg(feat.access_2G_1Dur().max).arg(feat.access_2G_1Dur().std).arg(feat.access_2G_1Dur().mean).arg(feat.access_2G_KeyLat().min).arg(feat.access_2G_KeyLat().max).arg(feat.access_2G_KeyLat().std).arg(feat.access_2G_KeyLat().mean).arg(feat.access_2G_2Dur().min).arg(feat.access_2G_2Dur().max).arg(feat.access_2G_2Dur().std).arg(feat.access_2G_2Dur().mean).arg(feat.access_2G_Dur().min).arg(feat.access_2G_Dur().max).arg(feat.access_2G_Dur().std).arg(feat.access_2G_Dur().mean).arg(feat.access_2G_NumEvents().min).arg(feat.access_2G_NumEvents().max).arg(feat.access_2G_NumEvents().std).arg(feat.access_2G_NumEvents().mean).arg(feat.access_3G_1D2D().min).arg(feat.access_3G_1D2D().max).arg(feat.access_3G_1D2D().std).arg(feat.access_3G_1D2D().mean).arg(feat.access_3G_1Dur().min).arg(feat.access_3G_1Dur().max).arg(feat.access_3G_1Dur().std).arg(feat.access_3G_1Dur().mean).arg(feat.access_3G_1KeyLat().min).arg(feat.access_3G_1KeyLat().max).arg(feat.access_3G_1KeyLat().std).arg(feat.access_3G_1KeyLat().mean).arg(feat.access_3G_2D3D().min).arg(feat.access_3G_2D3D().max).arg(feat.access_3G_2D3D().std).arg(feat.access_3G_2D3D().mean).arg(feat.access_3G_2Dur().min).arg(feat.access_3G_2Dur().max).arg(feat.access_3G_2Dur().std).arg(feat.access_3G_2Dur().mean).arg(feat.access_3G_2KeyLat().min).arg(feat.access_3G_2KeyLat().max).arg(feat.access_3G_2KeyLat().std).arg(feat.access_3G_2KeyLat().mean).arg(feat.access_3G_3Dur().min).arg(feat.access_3G_3Dur().max).arg(feat.access_3G_3Dur().std).arg(feat.access_3G_3Dur().mean).arg(feat.access_3G_Dur().min).arg(feat.access_3G_Dur().max).arg(feat.access_3G_Dur().std).arg(feat.access_3G_Dur().mean).arg(feat.access_3G_NumEvents().min).arg(feat.access_3G_NumEvents().max).arg(feat.access_3G_NumEvents().std).arg(feat.access_3G_NumEvents().mean);

   emit acceptTyping(query.exec(sql));
}

void Database::previousTyping() {
   QList<KeyFeatures> prev;
   // find the previous tests relating to the user in the database
   QSqlQuery query;
   QString sql = QString("select min(diG_1D2D_min), max(diG_1D2D_max), min(diG_1Dur_min), max(diG_1Dur_max), min(diG_1KeyLat_min), max(diG_1KeyLat_max), min(diG_2Dur_min), max(diG_2Dur_max), min(diG_Dur_min), max(diG_Dur_max), min(diG_NumEvents_min), max(diG_NumEvents_max), min(triG_1D2D_min), max(triG_1D2D_max), min(triG_1Dur_min), max(triG_1Dur_max), min(triG_1KeyLat_min), max(triG_1KeyLat_max), min(triG_2D3D_min), max(triG_2D3D_max), min(triG_2Dur_min), max(triG_2Dur_max), min(triG_2KeyLat_min), max(triG_2KeyLat_max), min(triG_3Dur_min), max(triG_3Dur_max), min(triG_Dur_min), max(triG_Dur_max), min(triG_NumEvents_min), max(triG_NumEvents_max) from TypingTest TT, Test T where TT.ID = T.typingID and T.username = \'%1\'").arg(username);
   query.exec(sql);
   while(query.next()) {
     KeyFeatures a;
     a.set_2G_1D2D(Features(query.value(0).toInt(), 
			    query.value(1).toInt()));
     a.set_2G_1Dur(Features(query.value(2).toInt(),
			    query.value(3).toInt()));
     a.set_2G_KeyLat(Features(query.value(4).toInt(), 
			       query.value(5).toInt()));
     a.set_2G_2Dur(Features(query.value(6).toInt(),
			    query.value(7).toInt()));
     a.set_2G_Dur(Features(query.value(8).toInt(),
			   query.value(9).toInt()));
     a.set_2G_NumEvents(Features(query.value(10).toInt(),
				 query.value(11).toInt()));
     a.set_3G_1D2D(Features(query.value(12).toInt(),
			    query.value(13).toInt()));
     a.set_3G_1Dur(Features(query.value(14).toInt(),
			    query.value(15).toInt()));
     a.set_3G_1KeyLat(Features(query.value(16).toInt(), 
			       query.value(17).toInt()));
     a.set_3G_2D3D(Features(query.value(18).toInt(),
			    query.value(19).toInt()));
     a.set_3G_2Dur(Features(query.value(20).toInt(),
			    query.value(21).toInt()));
     a.set_3G_2KeyLat(Features(query.value(22).toInt(), 
			       query.value(23).toInt()));
     a.set_3G_3Dur(Features(query.value(24).toInt(),
			    query.value(25).toInt()));
     a.set_3G_Dur(Features(query.value(26).toInt(),
			   query.value(27).toInt()));
     a.set_3G_NumEvents(Features(query.value(28).toInt(),
				 query.value(29).toInt()));
     prev.append(a);
   }
   emit previousTypingResults(prev);
}

void Database::makeTest() {
   // if the database accepts the information
   QSqlQuery query;
   int ID = 0;
   QString search = "select max(ID) from Test";
   query.exec(search);
   while(query.next()) {
     ID = query.value(0).toInt();
   }
   ID++;
   QString sql = QString("insert into Test values(%0, \'%1\', %2, %3, now(), %5)").arg(ID).arg(username).arg(emoID).arg(typingID).arg(inputStringID);
   query.exec(sql);
   
}
