#ifndef EVERYTHING_H
#define EVERYTHING_H

#include <QWidget>
#include "keyfeatures.h"
#include "analysis.h"
#include <iostream>

const QString emo[] = {"Happy", "Sad", "Angry", "Frustrated", "Relaxed",
                       "Focused", "Overwhelmed", "Confident", "Hesitant",
                       "Stressed", "Excited", "Distracted", "Bored", "Tired",
                       "Nervous"};
enum agree {StronglyAgree, Agree, Neutral, Disagree, StronglyDisagree, 
	    Nothing};
const QString agreement[] = {"Strongly Agree", "Agree", "Neutral", "Disagree",
			     "Strongly Disagree", "Nothing"}; 


class Everything: public QWidget {
  Q_OBJECT
 public:
  Everything(QWidget *parent=0) : QWidget(parent) {}
 Everything(int id, int e_id, int t_id, int is_id, QString user, 
	    KeyFeatures a, agree emot[15], QWidget * parent=0) : 
  QWidget(parent), ID(id), emoID(e_id), typingID(t_id), inputStringID(is_id), 
    username(user) {
      data.addKeyFeature(a);
      for(int i = 0; i < 15; i++) {
	emotion[i] = emot[i];
      }
      determine();
    }
 Everything(const Everything& e, QWidget *parent=0) :  QWidget(parent), ID(e.id()), 
    emoID(e.emoid()), typingID(e.typingid()), inputStringID(inputstringid()),
    username(e.user()),
    data(d()) {
    for(int i = 0; i < 15; i++) {
      emotion[i] = emoTest(i);
    }
  }
  int id() const {return ID;}
  int emoid() const {return emoID;}
  int typingid() const {return typingID;}
  int inputstringid() const {return inputStringID;}
  QString user() const {return username;}
  Analysis d() const {return data;}
  agree emoTest(int i) const {return emotion[i];}
  agree emoTestTired() const { return emotion[13]; }
  bool result() const { return tired; }
 private:
  void determine();
  int ID, emoID, typingID, inputStringID;
  QString username;
  Analysis data;
  agree emotion[15];
  bool tired;
};

#endif
