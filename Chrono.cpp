/*  * * * * * * * * * * * * * * * * * * * * * * * * * * * 
By Thomas O Fredericks (tof@t-o-f.info)
* * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include "Chrono.h"

Chrono::Chrono()
{
		
}


bool Chrono::passed(unsigned long interval)
{
   
  if ( (millis() - previousMillis) >= interval ) return true;
  
  return false;
  
}

unsigned long Chrono::elapsed() {
	return millis()-previousMillis;
}



void Chrono::restart() 
{
  this->previousMillis = millis();
}

/*

uint8_t Chrono::qmetro(unsigned long interval)
{
  unsigned long now = millis();
   
  if ( interval == 0 || ((now - previousMillis) >= interval) ) {
	
	previousMillis = now;
	
    return 1;
  }
  
  return 0;
}

uint8_t Chrono::metro(unsigned long interval)
{
  unsigned long now = millis();
  
  if ( interval == 0 ){
    previousMillis = now;
	return 1;
  }
 
  if ( (now - previousMillis) >= interval) {
	previousMillis += interval ; 
    return 1;
  }
  
  return 0;
}

}



*/
