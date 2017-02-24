/*
 * Lightweight chronometer class.
 * Simple chronometer/stopwatch class that counts the time passed since started.
 * 
 * (c) 2015 Sofian Audry        :: info(@)sofianaudry(.)com
 * (c) 2015 Thomas O Fredericks :: tof(@)t-o-f(.)info
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
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include "LightChrono.h"

LightChrono::LightChrono()
{
  restart();
}

void LightChrono::start() { restart(); }

void LightChrono::restart() 
{
  _startTime = millis();
}

LightChrono::chrono_t LightChrono::elapsed() const {
	return (millis() - _startTime);
}

bool LightChrono::hasPassed(LightChrono::chrono_t timeout) const
{
  return (elapsed() >= timeout);
}

bool LightChrono::hasPassed(LightChrono::chrono_t timeout, bool restartIfPassed) {
  if (hasPassed(timeout)) {
    if (restartIfPassed)
      restart();
    return true;
  }
  else {
    return false;
  }
}


