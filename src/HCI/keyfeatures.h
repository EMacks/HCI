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
  long long min, max, size;
  Features() {}
  Features(const Features &a) {
    mean = a.mean;
    std = a.std;
    min = a.min;
    max = a.max;
    size = a.size;
  }
};

class KeyFeatures {
   
 public:
  KeyFeatures(const QVector<long long>& k, const QVector<long long>& p,
	      const QVector<long long>& r);
  KeyFeatures(long long numM, long long diG_n, long long triG_n, 
	      long long numE, Features dG_1D2D,
	      Features dG_1Dur, Features dG_KeyLat, Features dG_2Dur,
	      Features dG_Dur, Features dG_NumEvents, Features trG_1D2D,
	      Features trG_1Dur, Features trG_1KeyLat, Features trG_2D3D,
	      Features trG_2Dur, Features trG_2KeyLat, Features trG_3Dur,
	      Features trG_Dur, Features trG_NumEvents);
  KeyFeatures() {}
  void calculate(const QVector<long long>& key, 
		 const QVector<long long>& press, 
		 const QVector<long long>& release);
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
  const long long& access_numMistakes() { return numMistakes; }
  const long long& access_2G_num() { return diG_num; }
  const long long& access_3G_num() { return triG_num; }

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
  void set_numMistakes(const long long &a) { numMistakes = a; }
  void set_2G_num(const long long &a) { diG_num = a; }
  void set_3G_num(const long long &a) { triG_num = a; }

  void set_2G_1D2D_min(const long long &a) { diG_1D2D.min = a;}
  void set_2G_1Dur_min(const long long &a) { diG_1Dur.min = a;}
  void set_2G_KeyLat_min(const long long &a) { diG_KeyLat.min = a;}
  void set_2G_2Dur_min(const long long &a) { diG_2Dur.min = a;}
  void set_2G_Dur_min(const long long &a) { diG_Dur.min = a;}
  void set_2G_NumEvents_min(const long long &a) { diG_NumEvents.min = a;}
  void set_3G_1D2D_min(const long long &a) { triG_1D2D.min = a;}
  void set_3G_1Dur_min(const long long &a) { triG_1Dur.min = a;}
  void set_3G_1KeyLat_min(const long long &a) { triG_1KeyLat.min = a;}
  void set_3G_2D3D_min(const long long &a) { triG_2D3D.min = a;}
  void set_3G_2Dur_min(const long long &a) { triG_2Dur.min = a;}
  void set_3G_2KeyLat_min(const long long &a) {triG_2KeyLat.min = a;}
  void set_3G_3Dur_min(const long long &a) { triG_3Dur.min = a;}
  void set_3G_Dur_min(const long long &a) { triG_Dur.min = a;}
  void set_3G_NumEvents_min(const long long &a) { triG_NumEvents.min = a;}
   
  void set_2G_1D2D_max(const long long &a) { diG_1D2D.max = a;}
  void set_2G_1Dur_max(const long long &a) { diG_1Dur.max = a;}
  void set_2G_KeyLat_max(const long long &a) { diG_KeyLat.max = a;}
  void set_2G_2Dur_max(const long long &a) { diG_2Dur.max = a;}
  void set_2G_Dur_max(const long long &a) { diG_Dur.max = a;}
  void set_2G_NumEvents_max(const long long &a) { diG_NumEvents.max = a;}
  void set_3G_1D2D_max(const long long &a) { triG_1D2D.max = a;}
  void set_3G_1Dur_max(const long long &a) { triG_1Dur.max = a;}
  void set_3G_1KeyLat_max(const long long &a) { triG_1KeyLat.max = a;}
  void set_3G_2D3D_max(const long long &a) { triG_2D3D.max = a;}
  void set_3G_2Dur_max(const long long &a) { triG_2Dur.max = a;}
  void set_3G_2KeyLat_max(const long long &a) {triG_2KeyLat.max = a;}
  void set_3G_3Dur_max(const long long &a) { triG_3Dur.max = a;}
  void set_3G_Dur_max(const long long &a) { triG_Dur.max = a;}
  void set_3G_NumEvents_max(const long long &a) { triG_NumEvents.max = a;}
      
 private:
  long long calcNumMistakes(const QVector<long long>& key);
  void calcFeatures(QVector<long long> a, Features&);
  QVector<long long>* calc_2G_1D2D(const QVector<long long>& press);
  QVector<long long>* calc_2G_1Dur(const QVector<long long>& press,
				   const QVector<long long>& release);
  QVector<long long>* calc_2G_KeyLat(const QVector<long long>& press,
				     const QVector<long long>& release);
  QVector<long long>* calc_2G_2Dur(const QVector<long long>& press,
				   const QVector<long long>& release);
  QVector<long long>* calc_2G_Dur(const QVector<long long>& press,
				  const QVector<long long>& release);
  QVector<long long>* calc_2G_NumEvents(const QVector<long long>& press,
					const QVector<long long>& release);
  QVector<long long>* calc_3G_1D2D(const QVector<long long>& press);
  QVector<long long>* calc_3G_1Dur(const QVector<long long>& press,
				   const QVector<long long>& release);
  QVector<long long>* calc_3G_1KeyLat(const QVector<long long>& press,
				      const QVector<long long>& release);
  QVector<long long>* calc_3G_2D3D(const QVector<long long>& press);
  QVector<long long>* calc_3G_2Dur(const QVector<long long>& press,
				   const QVector<long long>& release);
  QVector<long long>* calc_3G_2KeyLat(const QVector<long long>& press,
				      const QVector<long long>& release);
  QVector<long long>* calc_3G_3Dur(const QVector<long long>& press,
				   const QVector<long long>& release);
  QVector<long long>* calc_3G_Dur(const QVector<long long>& press,
				  const QVector<long long>& release);
  QVector<long long>* calc_3G_NumEvents(const QVector<long long>& press,
					const QVector<long long>& release);
   
  long long numMistakes, diG_num, triG_num, numEvents;
  Features diG_1D2D, diG_1Dur, diG_KeyLat, diG_2Dur, diG_Dur,
    diG_NumEvents, triG_1D2D, triG_1Dur, triG_1KeyLat, triG_2D3D, triG_2Dur,
    triG_2KeyLat, triG_3Dur, triG_Dur, triG_NumEvents;
};


#endif
