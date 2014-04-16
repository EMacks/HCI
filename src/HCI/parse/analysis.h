//*****************************************************************************
// CPSC 3770 Human Computer Interaction
// Prof: Kevin Grant
// by: Erin Mackey and Camara Lerner
// header file for Analysis
//*****************************************************************************
#ifndef ANALYSIS_H
#define ANALYSIS_H

#include <Qt>
#include <QVector>
#include "keyfeatures.h"

class Analysis {
  public:
   Analysis();
   Analysis(const Analysis& a) {
     for(int i = 0; i < a.dataSize(); i++) 
       data.append(a.in_data(i));
   }
   bool isTired(const int &latest);
   
   int addKeyFeature(KeyFeatures a);
   int addKeyFeature(const QVector<int> &k, 
		     const QVector<long long> &p,
		     const QVector<long long> &r);
   KeyFeatures results(const int &latest);
   int dataSize() const { return data.size();}
   KeyFeatures in_data(int i) const {return data[i];}
  private:
   void determine(const int &latest);
   QVector<KeyFeatures> data;
   KeyFeatures *result;
};

#endif
