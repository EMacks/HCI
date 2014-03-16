//*****************************************************************************
// CPSC 3770 Human Computer Interaction
// Prof: Kevin Grant
// by: Erin Mackey and Camara Lerner
// Implementation file for EmotionTest
//*****************************************************************************
#include "emotiontest.h"

typedef QList<EmotionRank*>::iterator iterER;

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
   int i =0;
   for(iterER it= emotions.begin(); it != emotions.end();i++, ++it){
      layout->addWidget(*it,i,0,1,1);
   }
   connect(submit, SIGNAL(clicked()), this, SLOT(findChecked()));  
   layout->addWidget(submit, emotions.length(), 0, 1, 1);
   setLayout(layout);
}

void EmotionTest::findChecked() {
   for(iterER it = emotions.begin(); it != emotions.end(); ++it) {
      agree ans = (*it)->findChecked();
   }
}
