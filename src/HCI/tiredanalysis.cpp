#include "tiredanalysis.h"

// make sure everything is already normalized
bool TiredAnalysis::isTired() {
   if(diG_1D2D.mean <= 0.049) 
      if(triG_1Dur.mean <= 0.037) 
	 if(triG_1Dur.std <=0.017) 
	    if(triG_1Dur.mean <= 0.035)
	       if(diG_1Dur.std <=0.015)
		  if(triG_1D2D.std <=0.024)
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
      if(diG_2Dur.mean <= 0.284)
	 if(triG_NumEvents.mena <= 0)
	    if(diG_KeyLat.mean <= 0.069)
	       if(diG_1D2D.mean <= 0.055)
		  return false;
	       else
		  return true;
	    else
	       return false;
	 else
	    if(triG_1D2D.mean <= 0.144)
	       if(NumMistakes <= 7)
		  if(diG_Dur.mean <= 0.093)
		     return true;
		  else
		     return false;
	       else
		  return false;
	    else
	       return true;
      else
	 if(triG_3Dur.mean <=0.539)
	    return false;
	 else
	    if(triG_Dur.mean <= 0.062)
	       if(triG_2KeyLat.std <=0.01)
		  return true;
	       else
		  return false;
	    else
	       if(diG_NumEvents.mean <= 0.063)
		  return true;
	       else
		  return false;
}
