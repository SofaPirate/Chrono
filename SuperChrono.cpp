/*
 * Advanced chronometer class
 * Advanced chronometer/stopwatch class that counts the time passed since started.
 * 
 * (c) 2015 Sofian Audry        :: info(@)sofianaudry(.)com
 * (c)      Thomas O Fredericks :: tof(@)t-o-f(.)info
 * (c)      Rob Tillaart
 *
 * See also the Chrono library (simple chronometer):
 * https://github.com/sofian/Chrono
 * 
 * Based on code by Sofian Audry:
 * https://github.com/sofian/libinteract/blob/master/trunk/arduino/SuperTimer.h
 * http://accrochages.drone.ws/node/90
 * 
 * Thomas O Fredericks (tof@t-o-f.info)
 * https://github.com/thomasfredericks/Chrono
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
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include "SuperChrono.h"

SuperChrono::SuperChrono(Resolution resolution = MILLIS) {
  // Assign appropriate time function.
  switch(resolution) {
    case SECONDS:
      _getTime = seconds;
      break;
    case MICROS:
      _getTime = micros;
      break;
    case MILLIS:
    default:  
      _getTime = millis;
      break;
  }
  // Start.
  start();
}

SuperChrono::SuperChrono(unsigned long (*getTime_)(void), bool start=true) : _getTime(getTime_) {
  if (start)
    start();
  else {
    _startTime = offset = 0;
    _isRunning = false;
  }
}

void SuperChrono::start(unsigned long offset = 0) {
  _startTime = _getTime();
  _offset    = offset;
  _isRunning = true;
}

void SuperChrono::stop() {
  _offset    = elapsed(); // save currently elapsed time
  _isRunning = false;
}
  
void SuperChrono::resume() {
  _startTime = _getTime();
  _isRunning = true;
}

void SuperChrono::add(unsigned long t) {
  _offset += t;
}

bool SuperChrono::isRunning() const {
  return (_isRunning);
}

unsigned long SuperChrono::elapsed() const {
  return _offset + _isRunning ? (_getTime() - _startTime) : 0;
}

bool SuperChrono::hasPassed(unsigned long timeout) const
{
  return (elapsed() >= timeout);
}

static unsigned long SuperChrono::seconds() {
  return (millis()/1000);
}



