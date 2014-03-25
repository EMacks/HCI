#include "tiredanalysis.h"
#include <climits>
#include <cmath>
#include <cstdlib>

TiredAnalysis::TiredAnalysis() {
   result = new KeyFeatures();
}

// make sure everything is already normalized
bool TiredAnalysis::isTired() {
   if((*result).access_2G_1D2D().mean <= 0.049) 
      if((*result).access_3G_1Dur().mean <= 0.037) 
	 if((*result).access_2G_1Dur().std <=0.017) 
	    if((*result).access_3G_1Dur().mean <= 0.035)
	       if((*result).access_2G_1Dur().std <=0.015)
		  if((*result).access_3G_1D2D().std <=0.024)
		     return true;
		  else
		     return false;
	       else
		  return false;
	    else
	       return false;
	 else
	    return false;
      else 
	 return false;
   else 
      if((*result).access_2G_2Dur().mean <= 0.284)
	 if((*result).access_3G_NumEvents().mean <= 0)
	    if((*result).access_2G_KeyLat().mean <= 0.069)
	       if((*result).access_2G_1D2D().mean <= 0.055)
		  return false;
	       else
		  return true;
	    else
	       return false;
	 else
	    if((*result).access_3G_1D2D().mean <= 0.144)
	       if(numMistakes <= 7)
		  if((*result).access_2G_Dur().mean <= 0.093)
		     return true;
		  else
		     return false;
	       else
		  return false;
	    else
	       return true;
      else
	 if((*result).access_3G_3Dur().mean <=0.539)
	    return false;
	 else
	    if((*result).access_3G_Dur().mean <= 0.062)
	       if((*result).access_3G_2KeyLat().std <=0.01)
		  return true;
	       else
		  return false;
	    else
	       if((*result).access_2G_NumEvents().mean <= 0.063)
		  return true;
	       else
		  return false;
}

Features TiredAnalysis::calc(const QVector<Features> &a, const int &latest) {
  Features result;
  result.size = 0;
  result.min = INT_MAX;
  result.min = INT_MIN;
  for(int i = 0; i < (int)a.size(); i++) {
    result.size +=a[i].size;
    result.min = std::min(result.min, a[i].min);
    result.max = std::max(result.max, a[i].max);
  }
  /*  result.mean = 0;
  result.std = 0;
  for(int i = 0; i < (int)a.size(); i++) {
    result.mean += a[i].size * a[i].mean;
    result.std += a[i].std * a[i].std * a[i].size;
  }
  result.std = std::sqrt(result.std/result.size);
  result.mean /= result.size;
  */
  //normalize for a[last]
  result.mean = (result.max - result.min + a[latest].mean)/(qreal)result.max;
  
  return result;
}



void TiredAnalysis::calc2G_1D2D(const int &latest) {
   QVector<Features> a;
   for(int i = 0; i < data.size(); i++)
      a.push_back(data[i].access_2G_1D2D());
   (*result).set_2G_1D2D(calc(a, latest));
}

void TiredAnalysis::calc2G_1Dur(const int &latest) {
   QVector<Features> a;
   for(int i = 0; i < data.size(); i++)
      a.push_back(data[i].access_2G_1Dur());
   (*result).set_2G_1Dur(calc(a, latest));
}

void TiredAnalysis::calc2G_KeyLat(const int &latest) {
  QVector<Features> a;
   for(int i = 0; i < data.size(); i++)
      a.push_back(data[i].access_2G_KeyLat());
   (*result).set_2G_KeyLat(calc(a, latest));
}

void TiredAnalysis::calc2G_2Dur(const int &latest) {
    QVector<Features> a;
   for(int i = 0; i < data.size(); i++)
      a.push_back(data[i].access_2G_2Dur());
   (*result).set_2G_2Dur(calc(a, latest));
}

void TiredAnalysis::calc2G_Dur(const int &latest) {
    QVector<Features> a;
   for(int i = 0; i < data.size(); i++)
      a.push_back(data[i].access_2G_Dur());
   (*result).set_2G_Dur(calc(a, latest));
}

void TiredAnalysis::calc2G_NumEvents(const int &latest) {
    QVector<Features> a;
   for(int i = 0; i < data.size(); i++)
      a.push_back(data[i].access_2G_NumEvents());
   (*result).set_2G_NumEvents(calc(a, latest));
}

void TiredAnalysis::calc3G_1D2D(const int &latest) {
    QVector<Features> a;
   for(int i = 0; i < data.size(); i++)
      a.push_back(data[i].access_3G_1D2D());
   (*result).set_3G_1D2D(calc(a, latest));
}

void TiredAnalysis::calc3G_1Dur(const int &latest) {
   QVector<Features> a;
   for(int i = 0; i < data.size(); i++)
      a.push_back(data[i].access_3G_1Dur());
   (*result).set_3G_1Dur(calc(a, latest));
}

void TiredAnalysis::calc3G_1KeyLat(const int &latest) {
   QVector<Features> a;
   for(int i = 0; i < data.size(); i++)
      a.push_back(data[i].access_3G_1KeyLat());
   (*result).set_3G_1KeyLat(calc(a, latest));
}

void TiredAnalysis::calc3G_2D3D(const int &latest) {
   QVector<Features> a;
   for(int i = 0; i < data.size(); i++)
      a.push_back(data[i].access_3G_2D3D());
   (*result).set_3G_2D3D(calc(a, latest));
}

void TiredAnalysis::calc3G_2Dur(const int &latest) {
   QVector<Features> a;
   for(int i = 0; i < data.size(); i++)
      a.push_back(data[i].access_3G_2Dur());
   (*result).set_3G_2Dur(calc(a, latest));
}

void TiredAnalysis::calc3G_2KeyLat(const int &latest) {
   QVector<Features> a;
   for(int i = 0; i < data.size(); i++)
      a.push_back(data[i].access_3G_2KeyLat());
   (*result).set_3G_2KeyLat(calc(a, latest));
}

void TiredAnalysis::calc3G_3Dur(const int &latest) {
   QVector<Features> a;
   for(int i = 0; i < data.size(); i++)
      a.push_back(data[i].access_3G_3Dur());
   (*result).set_3G_3Dur(calc(a, latest));
}

void TiredAnalysis::calc3G_Dur(const int &latest) {
   QVector<Features> a;
   for(int i = 0; i < data.size(); i++)
      a.push_back(data[i].access_3G_Dur());
   (*result).set_3G_Dur(calc(a, latest));
}

void TiredAnalysis::calc3G_NumEvents(const int &latest) {
   QVector<Features> a;
   for(int i = 0; i < data.size(); i++)
      a.push_back(data[i].access_3G_NumEvents());
   (*result).set_3G_NumEvents(calc(a, latest));
}

// might want to also store the number of characters typed as well
void TiredAnalysis::calcNumMistakes(const QVector<int> &a, const int &latest) {
   /* numMistakes = 0.0;
  for(int i = 0; i < a.size(); i++)
    numMistakes += a[i];
  numMistakes /= (qreal)a.size();
   */
   numMistakes = a[latest];
}
