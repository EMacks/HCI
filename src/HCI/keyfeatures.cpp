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

KeyFeatures::KeyFeatures(QVector<int>& k, QVector<int>& p,
			 QVector<int>& r) {
   key = k;
   press = p;
   release = r;

   calculate();
}

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
   
   return f;
}

void KeyFeatures::calculate() 
{
   calc_2G_1D2D();
   diG_1D2D = calcFeatures(*vdiG_1D2D);
   delete vdiG_1D2D;
   
   calc_2G_1Dur();
   diG_1Dur = calcFeatures(*vdiG_1Dur);
   delete vdiG_1Dur;
   
   calc_2G_KeyLat();
   diG_KeyLat = calcFeatures(*vdiG_KeyLat);
   delete vdiG_KeyLat;
   
   calc_2G_2Dur();
   diG_2Dur = calcFeatures(*vdiG_2Dur);
   delete vdiG_2Dur;
   
   calc_2G_Dur();
   diG_Dur = calcFeatures(*vdiG_Dur);
   delete vdiG_Dur;
   
   calc_2G_NumEvents();
   diG_NumEvents = calcFeatures(*vdiG_NumEvents);
   delete vdiG_NumEvents;
   
   calc_3G_1D2D();
   triG_1D2D = calcFeatures(*vtriG_1D2D);
   
   calc_3G_1Dur();
   triG_1Dur= calcFeatures(*vtriG_1Dur);
   delete vtriG_1Dur;
   
   calc_3G_1KeyLat();
   triG_1KeyLat = calcFeatures(*vtriG_1KeyLat);
   delete vtriG_1KeyLat;
   
   calc_3G_2D3D();
   triG_2D3D = calcFeatures(*vtriG_2D3D);
   delete vtriG_2D3D;
   
   calc_3G_2Dur();
   triG_2Dur = calcFeatures(*vtriG_2Dur);
   delete vtriG_2KeyLat;
   calc_3G_2KeyLat();
   triG_2KeyLat = calcFeatures(*vtriG_2KeyLat);
   delete vtriG_2KeyLat;
   
   calc_3G_3Dur();
   triG_3Dur = calcFeatures(*vtriG_3Dur);
   delete vtriG_3Dur;
   
   calc_3G_Dur();
   triG_Dur = calcFeatures(*vtriG_Dur);
   delete vtriG_Dur;
   
   calc_3G_NumEvents();
   triG_NumEvents = calcFeatures(*vtriG_NumEvents);
   delete vtriG_NumEvents;

   numMistakes = calcNumMistakes();

}

int KeyFeatures::calcNumMistakes() {
  int count = 0;
  for(int i = 0; i < key.size(); i++) {
    if(key[i] == Qt::Key_Delete || key[i] == Qt::Key_Backspace)
      count++;
  }
  return count;
}
// Qt::Key_Apostrophe >= here >= Qt::Key_Z

void KeyFeatures::calc_2G_1D2D() {
  for(int i = 0; i < key.size() - 1; i++) {
      (*vdiG_1D2D).push_back(press[i + 1] - press[i]);
  }
}

void KeyFeatures::calc_2G_1Dur() {
   for(int i = 0; i < key.size() - 1; i++) {
      (*vdiG_1Dur).push_back(release[i] - press[i]);
   }
}

void KeyFeatures::calc_2G_KeyLat() {
   for(int i = 0; i < key.size() - 1; i++) {
     (*vdiG_KeyLat).push_back(press[i+1] - release[i]);
  }
}

void KeyFeatures::calc_2G_2Dur() {
 for(int i = 0; i < key.size() - 1; i++) {
    (*vdiG_2Dur).push_back(release[i + 1] - press[i + 1]);
  }
}

void KeyFeatures::calc_2G_Dur() {
  for(int i = 0; i < key.size() - 1; i++) {
     (*vdiG_Dur).push_back(release[i + 1] - press[i]);
  }
}

void KeyFeatures::calc_2G_NumEvents() {
   QVector<int>::iterator it, it2;
   int i = 0;
   for(it = press.begin(), it2 = release.begin(); i < (int)key.size()-1;
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
      (*vdiG_NumEvents).push_back(count);
   }
}

void KeyFeatures::calc_3G_1D2D() {
  for(int i = 0; i < key.size() - 2; i++) {
     (*vtriG_1D2D).push_back(press[i + 1] - press[i]);
  }
}

void KeyFeatures::calc_3G_1Dur() {
  for(int i = 0; i < key.size() - 2; i++) {
     (*vtriG_1Dur).push_back(release[i] - press[i]);
  }
}

void KeyFeatures::calc_3G_1KeyLat() {
   for(int i = 0; i < key.size() - 2; i++) {
      (*vtriG_1KeyLat).push_back(press[i + 1] - release[i]);
   }
}

void KeyFeatures::calc_3G_2D3D() {
  for(int i = 0; i < key.size() - 2; i++) {
     (*vtriG_2D3D).push_back(press[i + 1] - press[i]);
  }
}

void KeyFeatures::calc_3G_2Dur() {
  for(int i = 0; i < key.size() - 2; i++) {
     (*vtriG_2Dur).push_back(release[i + 1] - press[i + 1]);
  }
}

void KeyFeatures::calc_3G_2KeyLat() {
  for(int i = 0; i < key.size() - 2; i++) {
     (*vtriG_2KeyLat).push_back(press[i + 2] - release[i+1]);
  }
}

void KeyFeatures::calc_3G_3Dur() {
  for(int i = 0; i < key.size() - 2; i++) {
     (*vtriG_3Dur).push_back(release[i + 2] - press[i + 2]);
  }
}

void KeyFeatures::calc_3G_Dur() {
  for(int i = 0; i < key.size() - 2; i++) {
     (*vtriG_Dur).push_back(release[i + 2] - press[i]);
  }
}

void KeyFeatures::calc_3G_NumEvents() {
   QVector<int>::iterator it, it2;
   int i = 0;
   for(it = press.begin(), it2 = release.begin(); i < (int)key.size()-2;
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
      (*vtriG_NumEvents).push_back(count);
   }
}
