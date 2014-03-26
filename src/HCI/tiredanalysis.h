//*****************************************************************************
// CPSC 3770 Human Computer Interaction
// Prof: Kevin Grant
// by: Erin Mackey and Camara Lerner
// header file for TiredAnalysis
//*****************************************************************************
#ifndef TIREDANALYSIS_H
#define TIREDANALYSIS_H

#include <Qt>
#include <QVector>
#include "keyfeatures.h"

class TiredAnalysis {
  public:
   TiredAnalysis();

   bool isTired(const int &latest);
   
   void calc2G_1D2D(const int &latest);
   void calc2G_1Dur(const int &latest);
   void calc2G_KeyLat(const int &latest);
   void calc2G_2Dur(const int &latest);
   void calc2G_Dur(const int &latest);
   void calc2G_NumEvents(const int &latest);
   void calc3G_1D2D(const int &latest);
   void calc3G_1Dur(const int &latest);
   void calc3G_1KeyLat(const int &latest);
   void calc3G_2D3D(const int &latest);
   void calc3G_2Dur(const int &latest);
   void calc3G_2KeyLat(const int &latest);
   void calc3G_3Dur(const int &latest);
   void calc3G_Dur(const int &latest);
   void calc3G_NumEvents(const int &latest);
   void calcNumMistakes(const int &latest);

   int addKeyFeature(KeyFeatures a) { data.push_back(a);
      return data.size() - 1; }
   int addKeyFeature(const QVector<long long> &k, const QVector<long long> &p,
		     const QVector<long long> &r) {
      data.push_back(KeyFeatures(k,p,r)); return data.size() - 1; }

  private:
   void determine(const int &latest);
   Features calc(const QVector<Features> &a, const int &latest);
   qreal numMistakes;
   QVector<KeyFeatures> data;
   KeyFeatures *result;
};

#endif
