//*****************************************************************************
// CPSC 3770 Human Computer Interaction
// Prof: Kevin Grant
// by: Erin Mackey and Camara Lerner
// header file for EmotionRank
//*****************************************************************************
#ifndef EMOTIONRANK_H
#define EMOTIONRANK_H
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QRadioButton>

enum agree {StronglyAgree, Agree, Neutral, Disagree, StronglyDisagree, Nothing};
const QString mapping[] = {"Strongly Agree", "Agree", "Neutral", "Disagree", "Strongly Disagree", "Nothing"}; 

class EmotionRank: public QWidget{
    Q_OBJECT

public:
    EmotionRank(QString em="", QWidget *p=0);
    agree findChecked();

  signals:
    void pressed();
  private:
    QList<QRadioButton*> radios;
};

#endif
