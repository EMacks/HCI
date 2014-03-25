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

   bool isTired();
   
   void calc2G_1D2D(const QVector<Features> &a, const int &latest);
   void calc2G_1Dur(const QVector<Features> &a, const int &latest);
   void calc2G_KeyLat(const QVector<Features> &a, const int &latest);
   void calc2G_2Dur(const QVector<Features> &a, const int &latest);
   void calc2G_Dur(const QVector<Features> &a, const int &latest);
   void calc2G_NumEvents(const QVector<Features> &a, const int &latest);
   void calc3G_1D2D(const QVector<Features> &a, const int &latest);
   void calc3G_1Dur(const QVector<Features> &a, const int &latest);
   void calc3G_1KeyLat(const QVector<Features> &a, const int &latest);
   void calc3G_2D3D(const QVector<Features> &a, const int &latest);
   void calc3G_2Dur(const QVector<Features> &a, const int &latest);
   void calc3G_2KeyLat(const QVector<Features> &a, const int &latest);
   void calc3G_3Dur(const QVector<Features> &a, const int &latest);
   void calc3G_Dur(const QVector<Features> &a, const int &latest);
   void calc3G_NumEvents(const QVector<Features> &a, const int &latest);
   void calcNumMistakes(const QVector<int> &a, const int &latest);
      
  private:
   Features calc(const QVector<Features> &a, const int &latest);
   Features diG_1D2D, diG_1Dur, diG_KeyLat, diG_2Dur, diG_Dur,
      diG_NumEvents, triG_1D2D, triG_1Dur, triG_1KeyLat, triG_2D3D, triG_2Dur,
      triG_2KeyLat, triG_3Dur, triG_Dur, triG_NumEvents;
   qreal numMistakes;
};

#endif
