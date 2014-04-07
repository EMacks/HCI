//*****************************************************************************
// CPSC 3770 Human Computer Interaction
// Prof: Kevin Grant
// by: Erin Mackey and Camara Lerner
// implementation file for EmotionRank
//*****************************************************************************
#include "emotionrank.h"

typedef QList<QRadioButton*>::iterator iterR;


EmotionRank::EmotionRank(QString em,QWidget *p) : QWidget(p) {
   QGridLayout *layout = new QGridLayout();
   QLabel *label=new QLabel(em);
   layout->addWidget(label);
   
   for(int i = 0; i < 5; i++) {
      radios.append(new QRadioButton(mapping[i],this));
   }
   int i=0;
   for(iterR it = radios.begin(); it != radios.end(); ++it, ++i){
      layout->addWidget(*it,0,i+1,1,1);
      connect(*it, SIGNAL(clicked()), this, SIGNAL(pressed()));
   }
   setLayout(layout);
}

agree EmotionRank::findChecked() {
   for(iterR it = radios.begin(); it != radios.end(); ++it) {
      if((*it)->isChecked())
	 for(int i = 0; i < 5; i++) {
	    if(mapping[i] == (*it)->text())
	       return (agree)i;
	 }
   }
   return (agree)Nothing;
}
