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

}

void KeyFeatures::calc_2G_1D2D() {

}

void KeyFeatures::calc_2G_1Dur() {

}

void KeyFeatures::calc_2G_KeyLat() {

}

void KeyFeatures::calc_2G_2Dur() {

}

void KeyFeatures::calc_2G_Dur() {

}

void KeyFeatures::calc_2G_NumEvents() {

}

void KeyFeatures::calc_3G_1D2D() {

}

void KeyFeatures::calc_3G_1Dur() {

}

void KeyFeatures::calc_3G_1KeyLat() {

}

void KeyFeatures::calc_3G_2D3D() {

}

void KeyFeatures::calc_3G_2Dur() {

}

void KeyFeatures::calc_3G_2KeyLat() {

}

void KeyFeatures::calc_3G_3Dur() {

}

void KeyFeatures::calc_3G_Dur() {

}

void KeyFeatures::calc_3G_NumEvents() {

}
