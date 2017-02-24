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
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include "Chrono.h"

Chrono::Chrono(Resolution resolution) {
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
  restart();
}

Chrono::Chrono(Chrono::chrono_t (*getTime_)(void), bool startNow) : _getTime(getTime_) {
  if (startNow)
    restart();
  else {
    _startTime = _offset = 0;
    _isRunning = false;
  }
}

void Chrono::start(Chrono::chrono_t offset) {
  restart(offset);
}

void Chrono::restart(Chrono::chrono_t offset) {
  _startTime = _getTime();
  _offset    = offset;
  _isRunning = true;
}

void Chrono::stop() {
  _offset    = elapsed(); // save currently elapsed time
  _isRunning = false;
}
  
void Chrono::resume() {
  _startTime = _getTime();
  _isRunning = true;
}

void Chrono::add(Chrono::chrono_t t) {
  _offset += t;
}

bool Chrono::isRunning() const {
  return (_isRunning);
}

void Chrono::delay(Chrono::chrono_t time) {
  time += elapsed();
  while (!hasPassed(time));
}

Chrono::chrono_t Chrono::elapsed() const {
  return _offset + (_isRunning ? (_getTime() - _startTime) : 0);
}

bool Chrono::hasPassed(Chrono::chrono_t timeout) const
{
  return (elapsed() >= timeout);
}

bool Chrono::hasPassed(Chrono::chrono_t timeout, bool restartIfPassed) {
  if (hasPassed(timeout)) {
    if (restartIfPassed)
      restart();
    return true;
  }
  else {
    return false;
  }
}

Chrono::chrono_t Chrono::seconds() {
  return (millis()/1000);
}



