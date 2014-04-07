//*****************************************************************************
// CPSC 3770 Human Computer Interaction
// Prof: Kevin Grant
// by: Erin Mackey and Camara Lerner
// header file for TiredAnalysis
//*****************************************************************************
#ifndef ANALYSIS_H
#define ANALYSIS_H

#include <Qt>
#include <QVector>
#include "keyfeatures.h"

class Analysis {
  public:
   Analysis();

   bool isTired(const int &latest);
   
   int addKeyFeature(KeyFeatures a);
   int addKeyFeature(const QVector<int> &k, 
		     const QVector<int> &p,
		     const QVector<int> &r);

  private:
   void determine(const int &latest);
   qreal numMistakes;
   QVector<KeyFeatures> data;
   KeyFeatures *result;
};

#endif
