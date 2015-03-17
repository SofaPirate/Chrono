/*  * * * * * * * * * * * * * * * * * * * * * * * * * * * 
By Thomas O Fredericks (tof@t-o-f.info)
* * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef Chrono_h
#define Metro_h

#include <inttypes.h>


class Chrono
{

public:
  Chrono();
  uint8_t metro(unsigned long interval);
  uint8_t qmetro(unsigned long interval);
  unsigned long get();
  void restart();
	
private:
  unsigned long  previousMillis;

};

#endif


