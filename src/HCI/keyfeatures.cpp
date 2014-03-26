//*****************************************************************************
// CPSC 3770 Human Computer Interaction
// Prof: Kevin Grant
// by: Erin Mackey and Camara Lerner
// Implementation file for KeyFeatures
//*****************************************************************************

// you are currently looking at page 35

#include "keyfeatures.h"
#include <cmath>
#include <cstdlib>
#include <algorithm>

KeyFeatures::KeyFeatures(QVector<int>& key, QVector<int>& press,
			 QVector<int>& release) {

  calculate(key, press, release);
}
KeyFeatures::KeyFeatures(int numM, int diG_n, int triG_n, int numE,
			 Features dG_1D2D, Features dG_1Dur, Features dG_KeyLat,
			 Features dG_2Dur, Features dG_Dur,
			 Features dG_NumEvents, Features trG_1D2D,
			 Features trG_1Dur, Features trG_1KeyLat,
			 Features trG_2D3D, Features trG_2Dur,
			 Features trG_2KeyLat, Features trG_3Dur,
			 Features trG_Dur, Features trG_NumEvents) :
   numMistakes(numM), diG_num(diG_n), triG_num(triG_n), numEvents(numE),
   diG_1D2D(dG_1D2D), diG_1Dur(dG_1Dur), diG_KeyLat(dG_KeyLat),
   diG_2Dur(dG_2Dur), diG_Dur(dG_Dur), diG_NumEvents(dG_NumEvents),
   triG_1D2D(trG_1D2D), triG_1Dur(trG_1Dur), triG_1KeyLat(trG_1KeyLat),
   triG_2D3D(trG_2D3D), triG_2Dur(trG_2Dur), triG_2KeyLat(trG_2KeyLat),
   triG_3Dur(trG_3Dur), triG_Dur(trG_Dur), triG_NumEvents(trG_NumEvents) {}

Features KeyFeatures::calcFeatures(QVector<int> a) {
  Features f;
  f.min = *std::min_element(a.begin(), a.end());
  f.max = *std::max_element(a.begin(), a.end());
   
  // calculate mean
  f.mean = 0;
  for(int i = 0; i < (int)a.size(); ++i) {
    f.mean += a[i];
  }
  f.mean /= a.size();

  // calculate standard deviation
  f.std = 0;
  for(int i = 0; i < (int)a.size(); ++i) {
    f.std = (a[i] - f.mean) * (a[i] - f.mean);
  }
  f.std = std::sqrt(f.std/a.size());
  f.size = a.size();
  return f;
}

void KeyFeatures::calculate(QVector<int>& key, QVector<int>& press,
			    QVector<int>& release) 
{
  numEvents = press.size() + release.size();
  
  QVector<int>* a = calc_2G_1D2D(press);
  diG_1D2D = calcFeatures(*a);
  delete a;
   
  a = calc_2G_1Dur(press, release);
  diG_1Dur = calcFeatures(*a);
  delete a;
   
  a = calc_2G_KeyLat(press, release);
  diG_KeyLat = calcFeatures(*a);
  delete a;
   
  a = calc_2G_2Dur(press, release);
  diG_2Dur = calcFeatures(*a);
  delete a;
   
  a = calc_2G_Dur(press, release);
  diG_Dur = calcFeatures(*a);
  delete a;
   
  a = calc_2G_NumEvents(press, release);
  diG_NumEvents = calcFeatures(*a);
  delete a;
   
  a = calc_3G_1D2D(press);
  triG_1D2D = calcFeatures(*a);
  delete a;

  a = calc_3G_1Dur(press, release);
  triG_1Dur= calcFeatures(*a);
  delete a;
   
  a = calc_3G_1KeyLat(press, release);
  triG_1KeyLat = calcFeatures(*a);
  delete a;
   
  a = calc_3G_2D3D(press);
  triG_2D3D = calcFeatures(*a);
  delete a;
   
  a = calc_3G_2Dur(press, release);
  triG_2Dur = calcFeatures(*a);
  delete a;

  a = calc_3G_2KeyLat(press, release);
  triG_2KeyLat = calcFeatures(*a);
  delete a;
   
  a = calc_3G_3Dur(press, release);
  triG_3Dur = calcFeatures(*a);
  delete a;
   
  a = calc_3G_Dur(press, release);
  triG_Dur = calcFeatures(*a);
  delete a;
   
  a = calc_3G_NumEvents(press, release);
  triG_NumEvents = calcFeatures(*a);
  delete a;

  numMistakes = calcNumMistakes(key);

}

int KeyFeatures::calcNumMistakes(QVector<int>& key) {
  int count = 0;
  for(int i = 0; i < key.size(); i++) {
    if(key[i] == Qt::Key_Delete || key[i] == Qt::Key_Backspace)
      count++;
  }
  return count;
}
// Qt::Key_Apostrophe >= here >= Qt::Key_Z

QVector<int>* KeyFeatures::calc_2G_1D2D(QVector<int>& press) {
   QVector<int> *a = new QVector<int>();
   for(int i = 0; i < press.size() - 1; i++) {
    (*a).push_back(press[i + 1] - press[i]);
   }
   return a;
}

QVector<int>* KeyFeatures::calc_2G_1Dur(QVector<int>& press,
					QVector<int>& release) {
  QVector<int> *a = new QVector<int>();
   for(int i = 0; i < press.size() - 1; i++) {
    (*a).push_back(release[i] - press[i]);
   }
   return a;
}

 QVector<int>* KeyFeatures::calc_2G_KeyLat(QVector<int>& press,
					  QVector<int>& release) {
  QVector<int> *a = new QVector<int>();
  for(int i = 0; i < press.size() - 1; i++) {
    (*a).push_back(press[i+1] - release[i]);
  }
  return a;
}

 QVector<int>* KeyFeatures::calc_2G_2Dur(QVector<int>& press,
					QVector<int>& release) {
  QVector<int> *a = new QVector<int>();
  for(int i = 0; i < press.size() - 1; i++) {
     (*a).push_back(release[i + 1] - press[i + 1]);
  }
  return a;
}

 QVector<int>* KeyFeatures::calc_2G_Dur(QVector<int>& press,
				       QVector<int>& release) {
   QVector<int> *a = new QVector<int>();
   for(int i = 0; i < press.size() - 1; i++) {
    (*a).push_back(release[i + 1] - press[i]);
   }
   return a;
}

 QVector<int>* KeyFeatures::calc_2G_NumEvents(QVector<int>& press,
					     QVector<int>& release) {
  QVector<int>::iterator it, it2;
  QVector<int> *a = new QVector<int>();
  int i = 0;
  for(it = press.begin(), it2 = release.begin(); i < (int)press.size()-1;
      ++i, ++it, ++it2) {
    int count = 0;
    int maxTime = std::max(*std::max_element(it, it+2),
			   *std::max_element(it2, it2+2));
    int minTime = std::min(*std::min_element(it, it+2),
			   *std::min_element(it2, it2+2));
    for(int j = 0; j < (int)press.size();j++) {
      if(press[j] <= maxTime && press[j] >= minTime)
	count++;
      if(release[j] <= maxTime && release[j] >= minTime)
	count++;
    }
    (*a).push_back(count);
  }
  return a;
}

 QVector<int>* KeyFeatures::calc_3G_1D2D(QVector<int>& press) {
   QVector<int> *a = new QVector<int>();
   for(int i = 0; i < press.size() - 2; i++) {
    (*a).push_back(press[i + 1] - press[i]);
   }
   return a;
}

QVector<int>* KeyFeatures::calc_3G_1Dur(QVector<int>& press,
					QVector<int>& release) {
   QVector<int> *a = new QVector<int>();
   for(int i = 0; i < press.size() - 2; i++) {
    (*a).push_back(release[i] - press[i]);
   }
   return a;
}

QVector<int>* KeyFeatures::calc_3G_1KeyLat(QVector<int>& press,
					   QVector<int>& release) {
   QVector<int> *a = new QVector<int>();
   for(int i = 0; i < press.size() - 2; i++) {
    (*a).push_back(press[i + 1] - release[i]);
   }
   return a;
}

 QVector<int>* KeyFeatures::calc_3G_2D3D(QVector<int>& press) {
   QVector<int> *a = new QVector<int>();
   for(int i = 0; i < press.size() - 2; i++) {
     (*a).push_back(press[i + 1] - press[i]);
   }
   return a;
 }

QVector<int>* KeyFeatures::calc_3G_2Dur(QVector<int>& press,
					QVector<int>& release) {
   QVector<int> *a = new QVector<int>();
   for(int i = 0; i < press.size() - 2; i++) {
    (*a).push_back(release[i + 1] - press[i + 1]);
   }
   return a;
}

QVector<int>* KeyFeatures::calc_3G_2KeyLat(QVector<int>& press,
					   QVector<int>& release) {
   QVector<int> *a = new QVector<int>();
   for(int i = 0; i < press.size() - 2; i++) {
    (*a).push_back(press[i + 2] - release[i+1]);
   }
   return a;
}

 QVector<int>* KeyFeatures::calc_3G_3Dur(QVector<int>& press,
					QVector<int>& release) {
   QVector<int> *a = new QVector<int>();
   for(int i = 0; i < press.size() - 2; i++) {
      (*a).push_back(release[i + 2] - press[i + 2]);
   }
   return a;
}

QVector<int>* KeyFeatures::calc_3G_Dur(QVector<int>& press,
				       QVector<int>& release) {
   QVector<int> *a = new QVector<int>();
   for(int i = 0; i < press.size() - 2; i++) {
    (*a).push_back(release[i + 2] - press[i]);
   }
   return a;
}

QVector<int>* KeyFeatures::calc_3G_NumEvents(QVector<int>& press,
					     QVector<int>& release) {
   QVector<int>::iterator it, it2;
   QVector<int> *a = new QVector<int>();
   int i = 0;
   for(it = press.begin(), it2 = release.begin(); i < (int)press.size()-2;
       ++i, ++it, ++it2) {
      int count = 0;
      int maxTime = std::max(*std::max_element(it, it+3),
			     *std::max_element(it2, it2+3));
      int minTime = std::min(*std::min_element(it, it+3),
			     *std::min_element(it2, it2+3));
      for(int j = 0; j < (int)press.size();j++) {
	 if(press[j] <= maxTime && press[j] >= minTime)
	    count++;
	 if(release[j] <= maxTime && release[j] >= minTime)
	    count++;
      }
      (*a).push_back(count);
   }
   return a;
}
