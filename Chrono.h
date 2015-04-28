/*
 * Chronometer class
 * Simple chronometer/stopwatch class that counts the time passed since started.
 * 
 * (c) 2015 Sofian Audry        :: info(@)sofianaudry(.)com
 * (c)      Thomas O Fredericks :: tof(@)t-o-f(.)info
 *
 * Based on code from Thomas O Fredericks (tof@t-o-f.info)
 * https://github.com/thomasfredericks/Chrono
 * and
 * http://accrochages.drone.ws/node/90
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
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


