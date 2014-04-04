#include "tiredanalysis.h"
#include <climits>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

TiredAnalysis::TiredAnalysis() {
   result = new KeyFeatures();
}

int TiredAnalysis::addKeyFeature(KeyFeatures a) { 
  data.push_back(a);
  return data.size() - 1; 
}

int TiredAnalysis::addKeyFeature(const QVector<long long> &k,
				 const QVector<long long> &p,
				 const QVector<long long> &r) {
  KeyFeatures a;
  Features boundry;
  boundry.min = LLONG_MAX;
  boundry.max = LLONG_MIN;
  boundry.size = boundry.std = boundry.mean = 0;
  a.set_2G_1D2D(boundry);
  a.set_2G_1Dur(boundry);
  a.set_2G_KeyLat(boundry);
  a.set_2G_2Dur(boundry);
  a.set_2G_Dur(boundry);
  a.set_2G_NumEvents(boundry);
  a.set_3G_1D2D(boundry);
  a.set_3G_1Dur(boundry);
  a.set_3G_1KeyLat(boundry);
  a.set_3G_2D3D(boundry);
  a.set_3G_2Dur(boundry);
  a.set_3G_2KeyLat(boundry);
  a.set_3G_3Dur(boundry);
  a.set_3G_Dur(boundry);
  a.set_3G_NumEvents(boundry);

  for(int i = 0;i < data.size(); ++i) {
    if(data[i].access_2G_1D2D().min < a.access_2G_1D2D().min)
      a.set_2G_1D2D_min(data[i].access_2G_1D2D().min);
    if(data[i].access_2G_1D2D().max > a.access_2G_1D2D().max)
      a.set_2G_1D2D_max(data[i].access_2G_1D2D().max);
    
    if(data[i].access_2G_1Dur().min < a.access_2G_1Dur().min)
      a.set_2G_1Dur_min(data[i].access_2G_1Dur().min);
    if(data[i].access_2G_1Dur().max > a.access_2G_1Dur().max) 
      a.set_2G_1Dur_max(data[i].access_2G_1Dur().max);
    
    if(data[i].access_2G_KeyLat().min < a.access_2G_KeyLat().min)
      a.set_2G_KeyLat_min(data[i].access_2G_KeyLat().min);
    if(data[i].access_2G_KeyLat().max > a.access_2G_KeyLat().max)
      a.set_2G_KeyLat_max(data[i].access_2G_KeyLat().max);
    
    if(data[i].access_2G_2Dur().min < a.access_2G_2Dur().min)
      a.set_2G_2Dur_min(data[i].access_2G_2Dur().min);
    if(data[i].access_2G_2Dur().max > a.access_2G_2Dur().max)
      a.set_2G_2Dur_max(data[i].access_2G_2Dur().max);
    
    if(data[i].access_2G_Dur().min < a.access_2G_Dur().min)
      a.set_2G_Dur_min(data[i].access_2G_Dur().min);
    if(data[i].access_2G_Dur().max > a.access_2G_Dur().max)
      a.set_2G_Dur_max(data[i].access_2G_Dur().max);
    
    if(data[i].access_2G_NumEvents().min < a.access_2G_NumEvents().min)
      a.set_2G_NumEvents_min(data[i].access_2G_NumEvents().min);
    if(data[i].access_2G_NumEvents().max > a.access_2G_NumEvents().max)
      a.set_2G_NumEvents_max(data[i].access_2G_NumEvents().max);

    if(data[i].access_3G_1D2D().min < a.access_3G_1D2D().min)
      a.set_3G_1D2D_min(data[i].access_3G_1D2D().min);
    if(data[i].access_3G_1D2D().max > a.access_3G_1D2D().max)
      a.set_3G_1D2D_max(data[i].access_3G_1D2D().max);

    if(data[i].access_3G_1Dur().min < a.access_3G_1Dur().min)
      a.set_3G_1Dur_min(data[i].access_3G_1Dur().min);
    if(data[i].access_3G_1Dur().max > a.access_3G_1Dur().max)
      a.set_3G_1Dur_max(data[i].access_3G_1Dur().max);

    if(data[i].access_3G_1KeyLat().min < a.access_3G_1KeyLat().min)
      a.set_3G_1KeyLat_min(data[i].access_3G_1KeyLat().min);
    if(data[i].access_3G_1KeyLat().max > a.access_3G_1KeyLat().max)
      a.set_3G_1KeyLat_max(data[i].access_3G_1KeyLat().max);

    if(data[i].access_3G_2D3D().min < a.access_3G_2D3D().min)
      a.set_3G_2D3D_min(data[i].access_3G_2D3D().min);
    if(data[i].access_3G_2D3D().max > a.access_3G_2D3D().max)
      a.set_3G_2D3D_max(data[i].access_3G_2D3D().max);

    if(data[i].access_3G_2Dur().min < a.access_3G_2Dur().min)
      a.set_3G_2Dur_min(data[i].access_3G_2Dur().min);
    if(data[i].access_3G_2Dur().max > a.access_3G_2Dur().max)
      a.set_3G_2Dur_max(data[i].access_3G_2Dur().max);
    
    if(data[i].access_3G_2KeyLat().min < a.access_3G_2KeyLat().min)
      a.set_3G_2KeyLat_min(data[i].access_3G_2KeyLat().min);
    if(data[i].access_3G_2KeyLat().max > a.access_3G_2KeyLat().max)
      a.set_3G_2KeyLat_max(data[i].access_3G_2KeyLat().max);

    if(data[i].access_3G_3Dur().min < a.access_3G_3Dur().min)
      a.set_3G_3Dur_min(data[i].access_3G_3Dur().min);
    if(data[i].access_3G_3Dur().max > a.access_3G_3Dur().max)
      a.set_3G_3Dur_max(data[i].access_3G_3Dur().max);

    if(data[i].access_3G_Dur().min < a.access_3G_Dur().min)
      a.set_3G_Dur_min(data[i].access_3G_Dur().min);
    if(data[i].access_3G_Dur().max > a.access_3G_Dur().max)
      a.set_3G_Dur_max(data[i].access_3G_Dur().max);
    
    if(data[i].access_3G_NumEvents().min < a.access_3G_NumEvents().min)
      a.set_3G_NumEvents_min(data[i].access_3G_NumEvents().min);
    if(data[i].access_3G_NumEvents().max > a.access_3G_NumEvents().max)
      a.set_3G_NumEvents_max(data[i].access_3G_NumEvents().max);
    
  }
  
  a.calculate(k,p,r);
  data.push_back(a); 

  return data.size() - 1; 
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
  cerr << latest << endl;
  (*result).set_2G_1D2D(data[latest].access_2G_1D2D());
  (*result).set_2G_1Dur(data[latest].access_2G_1Dur());
  (*result).set_2G_KeyLat(data[latest].access_2G_KeyLat());
  (*result).set_2G_2Dur(data[latest].access_2G_2Dur());
  (*result).set_2G_Dur(data[latest].access_2G_Dur());
  (*result).set_2G_NumEvents(data[latest].access_2G_NumEvents());
  (*result).set_3G_1D2D(data[latest].access_3G_1D2D());
  (*result).set_3G_1Dur(data[latest].access_3G_1Dur());
  (*result).set_3G_1KeyLat(data[latest].access_3G_1KeyLat());
  (*result).set_3G_2D3D(data[latest].access_3G_2D3D());
  (*result).set_3G_2Dur(data[latest].access_3G_2Dur());
  (*result).set_3G_2KeyLat(data[latest].access_3G_2KeyLat());
  (*result).set_3G_3Dur(data[latest].access_3G_3Dur());
  (*result).set_3G_Dur(data[latest].access_3G_Dur());
  (*result).set_3G_NumEvents(data[latest].access_3G_NumEvents());
  (*result).set_numMistakes(data[latest].access_numMistakes());
    
  /*  cerr << (*result).access_2G_1D2D().min << " " << (*result).access_2G_1D2D().max 
       << endl;
  
  cerr << (*result).access_2G_1Dur().min << " "  << (*result).access_2G_1Dur().max << endl;
  
  cerr << (*result).access_2G_KeyLat().min << " " << (*result).access_2G_KeyLat().max << endl;
    
  cerr << (*result).access_2G_2Dur().min << " " <<  (*result).access_2G_2Dur().max << endl;
    
  cerr << (*result).access_2G_Dur().min << " " << (*result).access_2G_Dur().max << endl;
    
  cerr << (*result).access_2G_NumEvents().min << " " << (*result).access_2G_NumEvents().max 
       << endl;

  cerr << (*result).access_3G_1D2D().min << " " << (*result).access_3G_1D2D().max << endl;

  cerr << (*result).access_3G_1Dur().min << " " << (*result).access_3G_1Dur().max << endl;

  cerr << (*result).access_3G_1KeyLat().min << " " << (*result).access_3G_1KeyLat().max
       << endl;

  cerr << (*result).access_3G_2D3D().min << " " << (*result).access_3G_2D3D().max << endl;

  cerr << (*result).access_3G_2Dur().min << " " << (*result).access_3G_2Dur().max << endl;
    
  cerr << (*result).access_3G_2KeyLat().min << " " << (*result).access_3G_2KeyLat().max
       << endl;

  cerr <<  (*result).access_3G_3Dur().min << " " << (*result).access_3G_3Dur().max << endl;

  cerr << (*result).access_3G_Dur().min << " " << (*result).access_3G_Dur().max << endl;
    
  cerr << (*result).access_3G_NumEvents().min << " " << (*result).access_3G_NumEvents().max 
       << endl;
  */
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


