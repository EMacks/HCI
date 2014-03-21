//*****************************************************************************
// CPSC 3770 Human Computer Interaction
// Prof: Kevin Grant
// by: Erin Mackey and Camara Lerner
// Implementation file for EmotionTest
//*****************************************************************************
#include "emotiontest.h"
#include <iostream>

typedef QList<EmotionRank*>::iterator iterER;

EmotionTest::EmotionTest(QWidget *p) : QDialog(p) {
   QGridLayout *layout=new QGridLayout();
   submit = new QPushButton("Submit", this);
   for(int i = 0; i < 15; i++) {
      emotions.append(new EmotionRank(emo[i], this));
   }
   int i =0;

   for(iterER it= emotions.begin(); it != emotions.end();i++, ++it){
      layout->addWidget(*it,i,0,1,1);
   }
   connect(submit, SIGNAL(clicked()), this, SLOT(findChecked()));  
   connect(submit, SIGNAL(clicked()), this, SLOT(close()));

   layout->addWidget(submit, emotions.length(), 0, 1, 1);
   setLayout(layout);
}

void EmotionTest::findChecked() {
   agree ans[15];
   int i =0;
   for(iterER it = emotions.begin(); it != emotions.end(); ++it, ++i) {
      ans[i] = (*it)->findChecked();
/*
  // how to access the answers from this information
  std::cerr << emo[i].toStdString() << " " << mapping[ans[i]].toStdString()
		<< std::endl;
*/
   }


}
