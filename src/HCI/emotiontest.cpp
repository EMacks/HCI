//*****************************************************************************
// CPSC 3770 Human Computer Interaction
// Prof: Kevin Grant
// by: Erin Mackey and Camara Lerner
// Implementation file for EmotionTest
//*****************************************************************************
#include "emotiontest.h"

EmotionTest::EmotionTest(QWidget *p){
   QGridLayout *layout=new QGridLayout();
   emotions.append(new EmotionRank("Happy"));
   emotions.append(new EmotionRank("Sad"));
   emotions.append(new EmotionRank("Angry"));
   emotions.append(new EmotionRank("Frustrated"));
   emotions.append(new EmotionRank("Relaxed"));
   for(int i=0;i<emotions.length();i++){
      layout->addWidget(emotions.at(i),i,0,1,1);
   }
   setLayout(layout);
}
