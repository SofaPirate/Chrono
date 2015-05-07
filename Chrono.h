/*
 * Chronometer class
 * Simple chronometer/stopwatch class that counts the time passed since started.
 * 
 * (c) 2015 Sofian Audry        :: info(@)sofianaudry(.)com
 * (c) 2015 Thomas O Fredericks :: tof(@)t-o-f(.)info
 *
 * Partly based on code by Sofian Audry:
 * https://github.com/sofian/libinteract/blob/master/trunk/arduino/Timer.h
 * http://accrochages.drone.ws/node/90
 * 
 * The MIT License (MIT)
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#ifndef CHRONO_H_
#define CHRONO_H_

/*
 * Example code:
 *
 * Chrono myChrono; // chronometer automatically starts at creation
 * // ...
 * myChrono.restart(); // you can start (restart) it later
 * while (!myChrono.hasPassed(2000)) // a 2000 ms loop
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
  void restart();

  /// Returns the elapsed time since start (in milliseconds).
  unsigned long elapsed() const;

  /// Returns true iff elapsed time has passed given timeout.
  bool hasPassed(unsigned long timeout) const;
};

#endif


