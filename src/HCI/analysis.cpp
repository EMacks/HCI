//*****************************************************************************
// CPSC 3770 Human Computer Interaction
// Prof: Kevin Grant
// by: Erin Mackey and Camara Lerner
// implementation file for Analysis
//*****************************************************************************
#include "analysis.h"
#include <climits>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

Analysis::Analysis() {
   result = new KeyFeatures();
}

int Analysis::addKeyFeature(KeyFeatures a) { 
  data.push_back(a);
  return data.size() - 1; 
}

int Analysis::addKeyFeature(const QVector<int> &k,
			    const QVector<long long> &p,
			    const QVector<long long> &r) {
  KeyFeatures a;
  Features boundary;
  boundary.min = INT_MAX;
  boundary.max = INT_MIN;
  boundary.size = boundary.std = boundary.mean = 0;
  a.set_2G_1D2D(boundary);
  a.set_2G_1Dur(boundary);
  a.set_2G_KeyLat(boundary);
  a.set_2G_2Dur(boundary);
  a.set_2G_Dur(boundary);
  a.set_2G_NumEvents(boundary);
  a.set_3G_1D2D(boundary);
  a.set_3G_1Dur(boundary);
  a.set_3G_1KeyLat(boundary);
  a.set_3G_2D3D(boundary);
  a.set_3G_2Dur(boundary);
  a.set_3G_2KeyLat(boundary);
  a.set_3G_3Dur(boundary);
  a.set_3G_Dur(boundary);
  a.set_3G_NumEvents(boundary);

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
  cerr << a.access_2G_1D2D().min << " " << a.access_2G_1D2D().max << " "
       << a.access_2G_1D2D().std << " " << a.access_2G_1D2D().mean 
       << endl;
  
  cerr << a.access_2G_1Dur().min << " "  << a.access_2G_1Dur().max  << " "
       << a.access_2G_1Dur().std << " "  << a.access_2G_1Dur().mean << endl;
  
  cerr << a.access_2G_KeyLat().min << " " << a.access_2G_KeyLat().max  << " "
       << a.access_2G_KeyLat().std << " " << a.access_2G_KeyLat().mean << endl;
    
  cerr << a.access_2G_2Dur().min << " " <<  a.access_2G_2Dur().max << " "
       << a.access_2G_2Dur().std << " " <<  a.access_2G_2Dur().mean << endl;
    
  cerr << a.access_2G_Dur().min << " " << a.access_2G_Dur().max << " "
       << a.access_2G_Dur().std << " " << a.access_2G_Dur().mean << endl;
    
  cerr << a.access_2G_NumEvents().min << " " << a.access_2G_NumEvents().max 
       << " " << a.access_2G_NumEvents().std << " " 
       << a.access_2G_NumEvents().mean << endl;

  cerr << a.access_3G_1D2D().min << " " << a.access_3G_1D2D().max  << " "
       << a.access_3G_1D2D().std << " " << a.access_3G_1D2D().mean
       << endl;

  cerr << a.access_3G_1Dur().min << " " << a.access_3G_1Dur().max  << " "
       << a.access_3G_1Dur().std << " " << a.access_3G_1Dur().mean << endl;

  cerr << a.access_3G_1KeyLat().min << " " << a.access_3G_1KeyLat().max << " "
       << a.access_3G_1KeyLat().std << " " << a.access_3G_1KeyLat().mean
       << endl;

  cerr << a.access_3G_2D3D().min << " " << a.access_3G_2D3D().max << " "
       << a.access_3G_2D3D().std << " " << a.access_3G_2D3D().mean << endl;

  cerr << a.access_3G_2Dur().min << " " << a.access_3G_2Dur().max << " "
       << a.access_3G_2Dur().std << " " << a.access_3G_2Dur().mean << endl;
    
  cerr << a.access_3G_2KeyLat().min << " " << a.access_3G_2KeyLat().max << " "
       << a.access_3G_2KeyLat().std << " " << a.access_3G_2KeyLat().mean
       << endl;

  cerr <<  a.access_3G_3Dur().min << " " << a.access_3G_3Dur().max << " "
       <<  a.access_3G_3Dur().std << " " << a.access_3G_3Dur().mean << endl;

  cerr << a.access_3G_Dur().min << " " << a.access_3G_Dur().max << " "
       << a.access_3G_Dur().std << " " << a.access_3G_Dur().mean << endl;
    
  cerr << a.access_3G_NumEvents().min << " " << a.access_3G_NumEvents().max 
       << " " << a.access_3G_NumEvents().std << " " 
       << a.access_3G_NumEvents().mean << endl;

  data.push_back(a); 

  return data.size() - 1; 
}

KeyFeatures Analysis::results(const int &latest) {
   determine(latest);
   return *result;
}

// make sure everything is already normalized
bool Analysis::isTired(const int &latest) {
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

void Analysis::determine(const int &latest) {
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
  
}


