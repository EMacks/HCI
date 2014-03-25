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
  int min, max, size;
};

class KeyFeatures {
   
  public:
   KeyFeatures(QVector<int>& k, QVector<int>& p, QVector<int>& r);
  KeyFeatures(int numM, int diG_n, int triG_n, int numE, Features dG_1D2D,
	      Features dG_1Dur, Features dG_KeyLat, Features dG_2Dur,
	      Features dG_Dur, Features dG_NumEvents, Features trG_1D2D,
	      Features trG_1Dur, Features trG_1KeyLat, Features trG_2D3D,
	      Features trG_2Dur, Features trG_2KeyLat, Features trG_3Dur,
	      Features trG_Dur, Features trG_NumEvents);
   KeyFeatures() {}
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
   const int& access_numMistakes() { return numMistakes; }
   const int& access_2G_num() { return diG_num; }
   const int& access_3G_num() { return triG_num; }

   void set_2G_1D2D(const Features &a) { diG_1D2D = a;}
   void set_2G_1Dur(const Features &a) { diG_1Dur = a;}
   void set_2G_KeyLat(const Features &a) { diG_KeyLat = a;}
   void set_2G_2Dur(const Features &a) { diG_2Dur = a;}
   void set_2G_Dur(const Features &a) { diG_Dur = a;}
   void set_2G_NumEvents(const Features &a) { diG_NumEvents = a;}
   void set_3G_1D2D(const Features &a) { triG_1D2D = a;}
   void set_3G_1Dur(const Features &a) { triG_1Dur = a;}
   void set_3G_1KeyLat(const Features &a) { triG_1KeyLat = a;}
   void set_3G_2D3D(const Features &a) { triG_2D3D = a;}
   void set_3G_2Dur(const Features &a) { triG_2Dur = a;}
   void set_3G_2KeyLat(const Features &a) {triG_2KeyLat = a;}
   void set_3G_3Dur(const Features &a) { triG_3Dur = a;}
   void set_3G_Dur(const Features &a) { triG_Dur = a;}
   void set_3G_NumEvents(const Features &a) { triG_NumEvents = a;}
   void set_numMistakes(const int &a) { numMistakes = a; }
   void set_2G_num(const int &a) { diG_num = a; }
   void set_3G_num(const int &a) { triG_num = a; }
   
 private:
   void calculate();
   int calcNumMistakes();
   Features calcFeatures(QVector<int> a);
   QVector<int>* calc_2G_1D2D();
   QVector<int>* calc_2G_1Dur();
   QVector<int>* calc_2G_KeyLat();
   QVector<int>* calc_2G_2Dur();
   QVector<int>* calc_2G_Dur();
   QVector<int>* calc_2G_NumEvents();
   QVector<int>* calc_3G_1D2D();
   QVector<int>* calc_3G_1Dur();
   QVector<int>* calc_3G_1KeyLat();
   QVector<int>* calc_3G_2D3D();
   QVector<int>* calc_3G_2Dur();
   QVector<int>* calc_3G_2KeyLat();
   QVector<int>* calc_3G_3Dur();
   QVector<int>* calc_3G_Dur();
   QVector<int>* calc_3G_NumEvents();
   
   int numMistakes, diG_num, triG_num, numEvents;
   Features diG_1D2D, diG_1Dur, diG_KeyLat, diG_2Dur, diG_Dur,
      diG_NumEvents, triG_1D2D, triG_1Dur, triG_1KeyLat, triG_2D3D, triG_2Dur,
      triG_2KeyLat, triG_3Dur, triG_Dur, triG_NumEvents;
   QVector<int> key, press, release;
};


#endif
