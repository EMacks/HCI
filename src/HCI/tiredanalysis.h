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
   
   int addKeyFeature(KeyFeatures a);
   int addKeyFeature(const QVector<long long> &k, 
		     const QVector<long long> &p,
		     const QVector<long long> &r);

  private:
   void determine(const int &latest);
   qreal numMistakes;
   QVector<KeyFeatures> data;
   KeyFeatures *result;
};

#endif
