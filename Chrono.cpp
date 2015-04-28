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
  start();
}

void Chrono::start() 
{
  _startTime = millis();
}

unsigned long Chrono::elapsed() const {
	return (millis() - _startTime);
}


bool Chrono::hasPassed(unsigned long timeout) const
{
  return (millis() - previousMillis >= interval);
}



