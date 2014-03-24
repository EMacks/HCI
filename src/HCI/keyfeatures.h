//*****************************************************************************
// CPSC 3770 Human Computer Interaction
// Prof: Kevin Grant
// by: Erin Mackey and Camara Lerner
// header file for KeyFeatures
//*****************************************************************************
#ifndef KEYFEATURES_H
#define KEYFEATURES_H

#include <Qt>
#include <QVector>
#include "features.h"

struct Features{
   qreal mean, std;
   int min, max;
};

class KeyFeatures {

  public:
   KeyFeatures(QVector<int>& k, QVector<int>& p, QVector<int>& r);
   const Features& access_2G_1D2D() { return diG_1D2D;}
   const Features& access_2G_1Dur() { return diG_1Dur;}
   const Features& access_2G_KeyLat() { return diG_KeyLat;}
   const Features& access_2G_2Dur() { return diG_2Dur;}
   const Features& access_2G_Dur() { return diG_Dur;}
   const Features& access_2G_NumEvents() { return diG_NumEvents;}
   const Features& access_3G_1D2D() { return triG_1D2D;}
   const Features& access_3G_1Dur() { return triG_1Dur;}
   const Features& access_3G_1KeyLat() { return triG_1KeyLat;}
   const Features& access_3G_2D3D() { return triG_2D3D;}
   const Features& access_3G_2Dur() { return triG_2Dur;}
   const Features& access_3G_2KeyLat() {return triG_2KeyLat;}
   const Features& access_3G_3Dur() { return triG_3Dur;}
   const Features& access_3G_Dur() { return triG_Dur;}
   const Features& access_3G_NumEvents() { return triG_NumEvents;}
  private:
   void calculate();
   int calcNumMistakes();
   Features calcFeatures(QVector<int> a);
   void calc_2G_1D2D();
   void calc_2G_1Dur();
   void calc_2G_KeyLat();
   void calc_2G_2Dur();
   void calc_2G_Dur();
   void calc_2G_NumEvents();
   void calc_3G_1D2D();
   void calc_3G_1Dur();
   void calc_3G_1KeyLat();
   void calc_3G_2D3D();
   void calc_3G_2Dur();
   void calc_3G_2KeyLat();
   void calc_3G_3Dur();
   void calc_3G_Dur();
   void calc_3G_NumEvents();
   
   int numMistakes;
   Features diG_1D2D, diG_1Dur, diG_KeyLat, diG_2Dur, diG_Dur,
      diG_NumEvents, triG_1D2D, triG_1Dur, triG_1KeyLat, triG_2D3D, triG_2Dur,
      triG_2KeyLat, triG_3Dur, triG_Dur, triG_NumEvents;
   QVector<int> key, press, release;
   QVector<int> *vdiG_1D2D, *vdiG_1Dur, *vdiG_KeyLat, *vdiG_2Dur, *vdiG_Dur,
      *vdiG_NumEvents, *vtriG_1D2D, *vtriG_1Dur, *vtriG_1KeyLat, *vtriG_2D3D,
      *vtriG_2Dur, *vtriG_2KeyLat, *vtriG_3Dur, *vtriG_Dur, *vtriG_NumEvents;
};


#endif
