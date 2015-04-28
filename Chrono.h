/*  * * * * * * * * * * * * * * * * * * * * * * * * * * * 
By Thomas O Fredericks (tof@t-o-f.info)
* * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef CHRONO_H_
#define CHRONO_H_

/*
 * Example code:
 *
 * Chrono myChrono; // chronometer automatically starts at creation
 * // ...
 * myChrono.start(); // you can start (restart) it later
 * while (!myChrono.passed(2000)) // a 2000 ms loop
 *  Serial.println(myChrono.elapsed()); // current time
 *   // do something
 * // ...
 */
class Chrono
{
private:
  unsigned long _startTime; // keeps track of start time (in milliseconds)

public:
  /// Constructor.
  Chrono();

  // Starts/restarts the chronometer.
  void start();

  /// Returns the elapsed time since start (in milliseconds).
  unsigned long elapsed() const;

  /// Returns true iff elapsed time has passed given timeout.
  bool hasPassed(unsigned long timeout) const;
};

#endif


