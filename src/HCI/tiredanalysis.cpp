#include "tiredanalysis.h"
#include <climits>
#include <cmath>
#include <cstdlib>
#include <fstream>
using namespace std;

TiredAnalysis::TiredAnalysis() {
   result = new KeyFeatures();
}

// make sure everything is already normalized
bool TiredAnalysis::isTired(const int &latest) {
   determine(latest);
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
	       if((*result).access_numMistakes() <= 7)
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

void output(ofstream& out, const Features& a) {
   out << "min: " << a.min  << ", max: " << a.max << ", mean: "
       << a.mean << ", std: " << a.std << ", size: " << a.size
       << endl;
}

void TiredAnalysis::determine(const int &latest) {

   calc2G_1D2D(latest);
   calc2G_1Dur(latest);
   calc2G_KeyLat(latest);
   calc2G_2Dur(latest);
   calc2G_Dur(latest);
   calc2G_NumEvents(latest);
   calc3G_1D2D(latest);
   calc3G_1Dur(latest);
   calc3G_1KeyLat(latest);
   calc3G_2D3D(latest);
   calc3G_2Dur(latest);
   calc3G_2KeyLat(latest);
   calc3G_3Dur(latest);
   calc3G_Dur(latest);
   calc3G_NumEvents(latest);
   calcNumMistakes(latest);

   ofstream out("tiredData.txt", ofstream::out);
   out << "2G_1D2D: ";
   output(out, (*result).access_2G_1D2D());
   out << endl; 
   out << "2G_1Dur: ";
   output(out, (*result).access_2G_1Dur());
   out << endl;
   out << "2G_KeyLat: ";
   output(out, (*result).access_2G_KeyLat());
   out << endl;
   out << "2G_2Dur: "; output(out, (*result).access_2G_2Dur()); out << endl;
   out << "2G_Dur: "; output(out, (*result).access_2G_Dur()); out << endl;
   out << "2G_1NumEvents: "; output(out, (*result).access_2G_NumEvents());
   out << endl;
   out << "3G_1D2D: "; output(out, (*result).access_3G_1D2D()); out <<  endl;
   out << "3G_1Dur: "; output(out, (*result).access_3G_1Dur()); out <<  endl;
   out << "3G_1KeyLat: "; output(out, (*result).access_3G_1KeyLat());
   out << endl;
   out << "3G_2D3D: "; output(out, (*result).access_3G_2D3D()); out << endl;
   out << "3G_2Dur: "; output(out, (*result).access_3G_2Dur()); out << endl;
   out << "3G_2KeyLat: "; output(out, (*result).access_3G_2KeyLat());
   out << endl;
   out << "3G_3Dur: "; output(out, (*result).access_3G_3Dur()); out << endl;
   out << "3G_Dur: "; output(out, (*result).access_3G_Dur()); out << endl;
   out << "3G_NumEvents: "; output(out, (*result).access_3G_NumEvents());
   out << endl;
   out << "Num of Mistakes: " << (*result).access_numMistakes() << endl;
   
}

Features TiredAnalysis::calc(const QVector<Features> &a, const int &latest) {
   Features result;
   
   result.size = 0;
   result.min = a[0].min;
   result.max = a[0].max;
   for(int i = 0; i < (int)a.size(); i++) {
      result.size +=a[i].size;
      result.min = min(result.min, a[i].min);
      result.max = max(result.max, a[i].max);
   }
   /*  result.mean = 0;
       result.std = 0;
       for(int i = 0; i < (int)a.size(); i++) {
       result.mean += a[i].size * a[i].mean;
       result.std += a[i].std * a[i].std * a[i].size;
       }
       result.std = sqrt(result.std/result.size);
       result.mean /= result.size;
   */
   //normalize for a[last]
   result.mean = -(qreal)result.min/(result.max - result.min)
      + a[latest].mean/(qreal)(result.max-result.min);

   long long r = result.max - result.min;
   r = r*r;
   result.std = std::sqrt(4.0*(qreal)result.min/r
			  + (qreal)a[latest].std * a[latest].std/r
			  - 4.0*result.min*
			  std::sqrt(a[latest].std*a[latest].std*a[latest].size)
			  /r/(qreal)a[latest].size);
			  
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
void TiredAnalysis::calcNumMistakes(const int &latest) {
   /* numMistakes = 0.0;
      for(int i = 0; i < a.size(); i++)
      numMistakes += a[i];
      numMistakes /= (qreal)a.size();
   */
   (*result).set_numMistakes(data[latest].access_numMistakes());
}
