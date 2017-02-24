/*
 * Chronometer class
 * Chronometer/stopwatch class that counts the time passed since started.
 * 
 * (c) 2015 Sofian Audry        :: info(@)sofianaudry(.)com
 * (c)      Thomas O Fredericks :: tof(@)t-o-f(.)info
 * (c)      Rob Tillaart
 *
 * Based on code by Sofian Audry:
 * https://github.com/sofian/libinteract/blob/master/trunk/arduino/SuperTimer.h
 * http://accrochages.drone.ws/node/90
 * 
 * Rob Tillaart StopWatch library:
 * http://playground.arduino.cc/Code/StopWatchClass
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
 * Chrono chrono;
 * // ...
 * chrono.restart(); // start/restart
 * // do some stuff
 * chrono.pause();
 * // do more stuff
 * chrono.resume();
 * // do some "out of the clock" processing, such as shutting the power down using
 * // the watchdog for 8000 ms
 * chrono.add(8000); // add the time that wasn't accounted for
 */
class Chrono
{
public:

#if defined(ARDUINO_ARC32_TOOLS)
  typedef uint64_t chrono_t;
#else
  typedef unsigned long chrono_t;
#endif

  // Different sorts of ways to get time.
  enum Resolution { MILLIS, MICROS, SECONDS };

public:
  // Keeps track of start time (in chosen time unit).
  chrono_t _startTime;

  // Time offset.
  chrono_t long _offset;

  // Time function.
  chrono_t (*_getTime)(void);

  // Tells if the chrono is currently running or not.
  bool _isRunning;

public:
  /// Constructor.
  Chrono(Resolution resolution = MILLIS);

  /**
   * Custom time method constructor. Optional parameter can be used to prevent 
   * the chronometer from starting at construction since some functions might
   * trigger errors when called statically.
   */
  Chrono(chrono_t (*getTime_)(void), bool startNow=true);
  
  // Starts/restarts the chronometer with optional starting offset.
  void start(chrono_t offset = 0);
  void restart(chrono_t offset = 0);
  
  // Stops/pauses the chronometer.
  void stop();

  // Resumes the chronometer.
  void resume();

  /// Adds some time to the chronometer.
  void add(chrono_t t);
  
  /// Returns the elapsed time since start (in milliseconds).
  chrono_t elapsed() const;

  /// Returns true iff elapsed time has passed given timeout.
  bool hasPassed(chrono_t timeout) const;
  bool hasPassed(chrono_t timeout, bool restartIfPassed);

  /// Returns true iff the chronometer is currently running.
  bool isRunning() const;

  // Blocks execution for a given time.
  void delay(chrono_t time);

  /// Returns the time in seconds (millis() / 1000).
  static chrono_t seconds();
};

#endif


