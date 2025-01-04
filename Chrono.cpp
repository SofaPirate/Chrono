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

#if defined(ARDUINO_ARC32_TOOLS)
  #define CHRONO_T_MAX UINT64_MAX
#else
  #define CHRONO_T_MAX UINT32_MAX
#endif

// Safe addition (prevents overflows and underflows).
Chrono::chrono_t safeAdd(Chrono::chrono_t a, Chrono::signed_chrono_t b) {
  if (b > 0) {
    // Overflow.
    if ((Chrono::chrono_t)b > CHRONO_T_MAX - a)
      return CHRONO_T_MAX;
  }

  else {
    // Underflow.
    if ((Chrono::chrono_t)(-b) > a)
      return 0;
  }
  // Default.
  return a + b;
}

Chrono::Chrono(Resolution resolution, bool startNow) {
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
  _init( (resolution == SECONDS ? seconds : (resolution == MICROS ? micros : millis) ), startNow);
}

Chrono::Chrono(bool startNow) {
  _init(millis, startNow);
}

Chrono::Chrono(Chrono::chrono_t (*getTime_)(void), bool startNow) : _getTime(getTime_) {
  _init(getTime_, startNow);
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
  if (_isRunning) { // can only stop if was running
    _offset    = elapsed(); // save currently elapsed time
    _isRunning = false;
  }
}
  
void Chrono::resume() {
  if (!_isRunning) { // can only resume if was stopped
    _startTime = _getTime();
    _isRunning = true;
  }
}

void Chrono::add(Chrono::signed_chrono_t t) {
  _offset = safeAdd(_offset, t);
}

bool Chrono::isRunning() const {
  return (_isRunning);
}

void Chrono::delay(Chrono::chrono_t time) {
  time = safeAdd(time, elapsed())
  while (!hasPassed(time));
}

Chrono::chrono_t Chrono::elapsed() const {
  return _isRunning ? safeAdd(_offset, _getTime() -_startTime) : _offset;
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

void Chrono::_init(chrono_t (*getTime_)(void), bool startNow) {
  _getTime = getTime_;
  // Start.
  if (startNow)
    restart();
  else {
    _startTime = 0;
    _offset = 0;
    _isRunning = false;
  }
}




