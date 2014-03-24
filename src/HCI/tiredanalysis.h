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
   
  private:
   Features diG_1D2D, diG_1Dur, diG_KeyLat, diG_2Dur, diG_Dur,
      diG_NumEvents, triG_1D2D, triG_1Dur, triG_1KeyLat, triG_2D3D, triG_2Dur,
      triG_2KeyLat, triG_3Dur, triG_Dur, triG_NumEvents;
   int NumMistakes;
};

#endif
