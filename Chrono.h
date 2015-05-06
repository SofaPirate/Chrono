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
  bool hasPassed(unsigned long interval);
  unsigned long elapsed();
  void restart();
  
  // DEPRACATED
  /*

  uint8_t metro(unsigned long interval);
  uint8_t qmetro(unsigned long interval);
	*/
	
private:
  unsigned long  previousMillis;

};

#endif


