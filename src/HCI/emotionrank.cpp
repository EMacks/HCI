#include "emotionrank.h"

EmotionRank::EmotionRank(QString em,QWidget *p){
    QGridLayout *layout;
    QLabel *label=new QLabel(em);
    layout->addWidget(label);

    radios.append(new QRadioButton("Strongly Agree",this));
    radios.append(new QRadioButton("Agree",this));
    radios.append(new QRadioButton("Neutral",this));
    radios.append(new QRadioButton("Disagree",this));
    radios.append(new QRadioButton("Strongly Disagree",this));
    for(int i=0;i<radios.length();i++){
        layout->addWidget(radios.at(i),0,i+1,1,1);
    }
    setLayout(layout);
}
