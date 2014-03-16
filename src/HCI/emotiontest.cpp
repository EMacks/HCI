//*****************************************************************************
// CPSC 3770 Human Computer Interaction
// Prof: Kevin Grant
// by: Erin Mackey and Camara Lerner
// Implementation file for EmotionTest
//*****************************************************************************
#include "emotiontest.h"

EmotionTest::EmotionTest(QWidget *p) : QWidget(p) {
   QGridLayout *layout=new QGridLayout();
   submit = new QPushButton("Submit", this);
   emotions.append(new EmotionRank("Happy", this));
   emotions.append(new EmotionRank("Sad", this));
   emotions.append(new EmotionRank("Angry", this));
   emotions.append(new EmotionRank("Frustrated", this));
   emotions.append(new EmotionRank("Relaxed", this));
   emotions.append(new EmotionRank("Focused", this));
   emotions.append(new EmotionRank("Overwhelmed", this));
   emotions.append(new EmotionRank("Confident", this));
   emotions.append(new EmotionRank("Hesitant", this));
   emotions.append(new EmotionRank("Stressed", this));
   emotions.append(new EmotionRank("Excited", this));
   emotions.append(new EmotionRank("Distracted", this));
   emotions.append(new EmotionRank("Bored", this));
   emotions.append(new EmotionRank("Tired", this));
   emotions.append(new EmotionRank("Nervous", this));
   
   for(int i=0;i<emotions.length();i++){
      layout->addWidget(emotions.at(i),i,0,1,1);
   }
   layout->addWidget(submit, emotions.length(), 0, 1, 1);
   setLayout(layout);
}
