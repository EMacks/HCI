//*****************************************************************************
// CPSC 3770 Human Computer Interaction
// Prof: Kevin Grant
// by: Erin Mackey and Camara Lerner
// implementation file for Database
//*****************************************************************************
#include "database.h"
#include <iostream>
#include "info.h"

Database::Database(QWidget* parent) : QWidget(parent) {}

bool Database::makeConnection() {
   QStringList drivers = QSqlDatabase::drivers();
   QSqlDatabase db=QSqlDatabase::addDatabase(DATABASE);
   db.setHostName(HOST_NAME);
   db.setPort(PORT);
   db.setDatabaseName(DATABASE_NAME);
   db.setUserName(USERNAME);
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

void Database::getEverything(int expected[6], int result[2]) {
  QSqlQuery query;
  QString search = "select t.ID, t.username, t.emoID, t.typingID, t.inputStringID, tt.NumMistakes, tt.NumEvents, tt.diG_1D2D_min, tt.diG_1D2D_max, tt.diG_1D2D_std, tt.diG_1D2D_mean, tt.diG_1Dur_min, tt.diG_1Dur_max, tt.diG_1Dur_std, tt.diG_1Dur_mean, tt.diG_1KeyLat_min, tt.diG_1KeyLat_max, tt.diG_1KeyLat_std, tt.diG_1KeyLat_mean, tt.diG_2Dur_min, tt.diG_2Dur_max, tt.diG_2Dur_std, tt.diG_2Dur_mean, tt.diG_Dur_min, tt.diG_Dur_max, tt.diG_Dur_std, tt.diG_Dur_mean, tt.diG_NumEvents_min, tt.diG_NumEvents_max, tt.diG_NumEvents_std, tt.diG_NumEvents_mean, tt.triG_1D2D_min, tt.triG_1D2D_max, tt.triG_1D2D_std, tt.triG_1D2D_mean, tt.triG_1Dur_min, tt.triG_1Dur_max, tt.triG_1Dur_std, tt.triG_1Dur_mean, tt.triG_1KeyLat_min, tt.triG_1KeyLat_max, tt.triG_1KeyLat_std, tt.triG_1KeyLat_mean, tt.triG_2D3D_min, tt.triG_2D3D_max, tt.triG_2D3D_std, tt.triG_2D3D_mean, tt.triG_2Dur_min, tt.triG_2Dur_max, tt.triG_2Dur_std, tt.triG_2Dur_mean, tt.triG_2KeyLat_min, tt.triG_2KeyLat_max, tt.triG_2KeyLat_std, tt.triG_2KeyLat_mean, tt.triG_3Dur_min, tt.triG_3Dur_max, tt.triG_3Dur_std, tt.triG_3Dur_mean, tt.triG_Dur_min, tt.triG_Dur_max, tt.triG_Dur_std, tt.triG_Dur_mean, tt.triG_NumEvents_min, tt.triG_NumEvents_max, tt.triG_NumEvents_std, tt.triG_NumEvents_mean, et.Happy, et.Sad, et.Angry, et.Frustrated, et.Relaxed, et.Focused, et.Overwhelmed, et.Confident, et.Hesitant, et.Stressed, et.Excited, et.Distracted, et.Bored, et.Tired, et.Nervous from Test t, TypingTest tt, EmotionTest et, User u where t.username=u.username and t.emoID = et.ID and t.typingID=tt.ID and t.username!='hello' and t. username!='prof';";
  query.exec(search);
  QList<Everything> e;
  while(query.next()) {
    agree emo[15] = {(agree)query.value(67).toInt(), 
		     (agree)query.value(68).toInt(),
		     (agree)query.value(69).toInt(), 
		     (agree)query.value(70).toInt(),
		     (agree)query.value(71).toInt(), 
		     (agree)query.value(72).toInt(),
		     (agree)query.value(73).toInt(), 
		     (agree)query.value(74).toInt(),
		     (agree)query.value(75).toInt(), 
		     (agree)query.value(76).toInt(),
		     (agree)query.value(77).toInt(), 
		     (agree)query.value(78).toInt(),
		     (agree)query.value(79).toInt(),
		     (agree)query.value(80).toInt(),
		     (agree)query.value(81).toInt()};
    result[emo[13]]++;
    Everything a(query.value(0).toInt(), query.value(2).toInt(), 
		 query.value(3).toInt(), query.value(4).toInt(), 
		 query.value(1).toString(),
		 KeyFeatures(query.value(5).toInt(), 0, 0, 
			     query.value(6).toInt(),
			     Features(query.value(7).toInt(),
				      query.value(8).toInt(), 
				      query.value(9).toDouble(), 
				      query.value(10).toDouble()),
			     Features(query.value(11).toInt(),
				      query.value(12).toInt(), 
				      query.value(13).toDouble(), 
				      query.value(14).toDouble()),
			     Features(query.value(15).toInt(),
				      query.value(16).toInt(), 
				      query.value(17).toDouble(), 
				      query.value(18).toDouble()),
			     Features(query.value(19).toInt(),
				      query.value(20).toInt(), 
				      query.value(21).toDouble(), 
				      query.value(22).toDouble()), 
			     Features(query.value(23).toInt(),
				      query.value(24).toInt(), 
				      query.value(25).toDouble(), 
				      query.value(26).toDouble()), 
			     Features(query.value(27).toInt(),
				      query.value(28).toInt(), 
				      query.value(29).toDouble(), 
				      query.value(30).toDouble()), 
			     Features(query.value(31).toInt(),
				      query.value(32).toInt(), 
				      query.value(33).toDouble(), 
				      query.value(34).toDouble()), 
			     Features(query.value(35).toInt(),
				      query.value(36).toInt(), 
				      query.value(37).toDouble(), 
				      query.value(38).toDouble()), 
			     Features(query.value(39).toInt(),
				      query.value(40).toInt(), 
				      query.value(41).toDouble(), 
				      query.value(42).toDouble()), 
			     Features(query.value(43).toInt(),
				      query.value(44).toInt(), 
				      query.value(45).toDouble(), 
				      query.value(46).toDouble()), 
			     Features(query.value(47).toInt(),
				      query.value(48).toInt(), 
				      query.value(49).toDouble(), 
				      query.value(50).toDouble()), 
			     Features(query.value(51).toInt(),
				      query.value(52).toInt(), 
				      query.value(53).toDouble(), 
				      query.value(54).toDouble()), 
			     Features(query.value(55).toInt(),
				      query.value(56).toInt(), 
				      query.value(57).toDouble(), 
				      query.value(58).toDouble()),
 			     Features(query.value(59).toInt(),
				      query.value(60).toInt(), 
				      query.value(61).toDouble(), 
				      query.value(62).toDouble()),
			     Features(query.value(63).toInt(),
				      query.value(64).toInt(), 
				      query.value(65).toDouble(), 
				      query.value(66).toDouble())), emo);
   
    expected[a.emoTestTired()]++;
  }
}
