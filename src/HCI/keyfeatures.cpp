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

KeyFeatures::KeyFeatures(const QVector<long long>& key,
			 const QVector<long long>& press,
			 const QVector<long long>& release) {

  calculate(key, press, release);
}
KeyFeatures::KeyFeatures(long long numM, long long diG_n, long long triG_n,
			 long long numE,
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

void KeyFeatures::calcFeatures(QVector<long long> a, Features & f) {
  for(int i = 0; i < a.size(); i++) {
    if(a[i] < f.min)
      f.min = a[i]; 
    if(a[i] > f.max)
      f.max = a[i];
  }
  
  // calculate mean
  f.mean = 0;
  for(int i = 0; i < (int)a.size(); ++i) {
    f.mean += (qreal)(a[i] - f.min) / (f.max - f.min);
  }
  f.mean /= a.size();
  
  // calculate standard deviation
  f.std = 0;
  for(int i = 0; i < (int)a.size(); ++i) {
    f.std = ((qreal)(a[i] - f.min)/(f.max - f.min) - f.mean)
      * ((qreal)(a[i] - f.min)/(f.max -f.min) - f.mean);
  }
  f.std = std::sqrt(f.std/a.size());
  f.size = a.size();
}

void KeyFeatures::calculate(const QVector<long long>& key,
			    const QVector<long long>& press,
			    const QVector<long long>& release) 
{
  numEvents = press.size() + release.size();
  
  QVector<long long>* a = calc_2G_1D2D(press);
  calcFeatures(*a, diG_1D2D);
  delete a;
   
  a = calc_2G_1Dur(press, release);
  calcFeatures(*a, diG_1Dur);
  delete a;
   
  a = calc_2G_KeyLat(press, release);
  calcFeatures(*a, diG_KeyLat);
  delete a;
   
  a = calc_2G_2Dur(press, release);
  calcFeatures(*a, diG_2Dur);
  delete a;
   
  a = calc_2G_Dur(press, release);
  calcFeatures(*a, diG_Dur);
  delete a;
   
  a = calc_2G_NumEvents(press, release);
  calcFeatures(*a, diG_NumEvents);
  delete a;
   
  a = calc_3G_1D2D(press);
  calcFeatures(*a, triG_1D2D);
  delete a;

  a = calc_3G_1Dur(press, release);
  calcFeatures(*a, triG_1Dur);
  delete a;
   
  a = calc_3G_1KeyLat(press, release);
  calcFeatures(*a, triG_1KeyLat);
  delete a;
   
  a = calc_3G_2D3D(press);
  calcFeatures(*a, triG_2D3D);
  delete a;
   
  a = calc_3G_2Dur(press, release);
  calcFeatures(*a, triG_2Dur);
  delete a;

  a = calc_3G_2KeyLat(press, release);
  calcFeatures(*a, triG_2KeyLat);
  delete a;
   
  a = calc_3G_3Dur(press, release);
  calcFeatures(*a, triG_3Dur);
  delete a;
   
  a = calc_3G_Dur(press, release);
  calcFeatures(*a, triG_Dur);
  delete a;
   
  a = calc_3G_NumEvents(press, release);
  calcFeatures(*a, triG_NumEvents);
  delete a;

  numMistakes = calcNumMistakes(key);

}

long long KeyFeatures::calcNumMistakes(const QVector<long long>& key) {
  long long count = 0;
  for(int i = 0; i < key.size(); i++) {
    if(key[i] == Qt::Key_Delete || key[i] == Qt::Key_Backspace)
      count++;
  }
  return count;
}
// Qt::Key_Apostrophe >= here >= Qt::Key_Z

QVector<long long>* KeyFeatures::calc_2G_1D2D(const QVector<long long>& press) {
   QVector<long long> *a = new QVector<long long>();
   for(int i = 0; i < press.size() - 1; i++) {
    (*a).push_back(press[i + 1] - press[i]);
   }
   return a;
}

QVector<long long>* KeyFeatures::calc_2G_1Dur(const QVector<long long>& press,
					      const QVector<long long>&
					      release) {
  QVector<long long> *a = new QVector<long long>();
   for(int i = 0; i < press.size() - 1; i++) {
    (*a).push_back(release[i] - press[i]);
   }
   return a;
}

QVector<long long>* KeyFeatures::calc_2G_KeyLat(const QVector<long long>& press,
						const QVector<long long>&
						release) {
  QVector<long long> *a = new QVector<long long>();
  for(int i = 0; i < press.size() - 1; i++) {
    (*a).push_back(press[i+1] - release[i]);
  }
  return a;
}

QVector<long long>* KeyFeatures::calc_2G_2Dur(const QVector<long long>& press,
					      const QVector<long long>&
					      release) {
  QVector<long long> *a = new QVector<long long>();
  for(int i = 0; i < press.size() - 1; i++) {
     (*a).push_back(release[i + 1] - press[i + 1]);
  }
  return a;
}

 QVector<long long>* KeyFeatures::calc_2G_Dur(const QVector<long long>& press,
					      const QVector<long long>&
					      release) {
   QVector<long long> *a = new QVector<long long>();
   for(int i = 0; i < press.size() - 1; i++) {
    (*a).push_back(release[i + 1] - press[i]);
   }
   return a;
}

QVector<long long>* KeyFeatures::calc_2G_NumEvents(const QVector<long long>&
						   press,
						   const QVector<long long>&
						   release) {
   QVector<long long> *a = new QVector<long long>();
   for(int i = 0; i < press.size()-1; ++i) {
      long long count = 0;
      long long maxTime = press[i], minTime = press[i];
      for(int j = i; j < i+2; j++) {
	 if(press[j] < minTime)
	    minTime = press[j];
	 if(press[j] > maxTime)
	    maxTime = press[j];
	 if(release[j] < minTime)
	    minTime = release[j];
	 if(release[j] > maxTime)
	    maxTime = release[j];
      }
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

QVector<long long>* KeyFeatures::calc_3G_1D2D(const QVector<long long>& press)
{
   QVector<long long> *a = new QVector<long long>();
   for(int i = 0; i < press.size() - 2; i++) {
    (*a).push_back(press[i + 1] - press[i]);
   }
   return a;
}

QVector<long long>* KeyFeatures::calc_3G_1Dur(const QVector<long long>& press,
					      const QVector<long long>&
					      release) {
   QVector<long long> *a = new QVector<long long>();
   for(int i = 0; i < press.size() - 2; i++) {
    (*a).push_back(release[i] - press[i]);
   }
   return a;
}

QVector<long long>* KeyFeatures::calc_3G_1KeyLat(const QVector<long long>&
						 press,
						 const QVector<long long>&
						 release) {
   QVector<long long> *a = new QVector<long long>();
   for(int i = 0; i < press.size() - 2; i++) {
    (*a).push_back(press[i + 1] - release[i]);
   }
   return a;
}

 QVector<long long>* KeyFeatures::calc_3G_2D3D(const QVector<long long>& press) {
   QVector<long long> *a = new QVector<long long>();
   for(int i = 0; i < press.size() - 2; i++) {
     (*a).push_back(press[i + 1] - press[i]);
   }
   return a;
 }

QVector<long long>* KeyFeatures::calc_3G_2Dur(const QVector<long long>& press,
					      const QVector<long long>&
					      release) {
   QVector<long long> *a = new QVector<long long>();
   for(int i = 0; i < press.size() - 2; i++) {
    (*a).push_back(release[i + 1] - press[i + 1]);
   }
   return a;
}

QVector<long long>* KeyFeatures::calc_3G_2KeyLat(const QVector<long long>&
						 press,
						 const QVector<long long>&
						 release) {
   QVector<long long> *a = new QVector<long long>();
   for(int i = 0; i < press.size() - 2; i++) {
    (*a).push_back(press[i + 2] - release[i+1]);
   }
   return a;
}

 QVector<long long>* KeyFeatures::calc_3G_3Dur(const QVector<long long>& press,
					       const QVector<long long>&
					       release) {
   QVector<long long> *a = new QVector<long long>();
   for(int i = 0; i < press.size() - 2; i++) {
      (*a).push_back(release[i + 2] - press[i + 2]);
   }
   return a;
}

QVector<long long>* KeyFeatures::calc_3G_Dur(const QVector<long long>& press,
					     const QVector<long long>&
					     release) {
   QVector<long long> *a = new QVector<long long>();
   for(int i = 0; i < press.size() - 2; i++) {
    (*a).push_back(release[i + 2] - press[i]);
   }
   return a;
}

QVector<long long>* KeyFeatures::calc_3G_NumEvents(const QVector<long long>&
						   press,
						   const QVector<long long>&
						   release) {
   QVector<long long> *a = new QVector<long long>();
   for(int i = 0; i < (int)press.size()-2; ++i) {
      long long count = 0;
      long long maxTime = press[i], minTime = press[i];
      for(int j = i; j < i+3; j++) {
	 if(press[j] < minTime)
	    minTime = press[j];
	 if(press[j] > maxTime)
	    maxTime = press[j];
	 if(release[j] < minTime)
	    minTime = release[j];
	 if(release[j] > maxTime)
	    maxTime = release[j];
      }
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
