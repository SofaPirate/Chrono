/*
 * Chronometer class
 * Simple chronometer/stopwatch class that counts the time passed since started.
 * 
 * (c) 2015 Sofian Audry        :: info(@)sofianaudry(.)com
 * (c)      Thomas O Fredericks :: tof(@)t-o-f(.)info
 *
 * Based on code by Sofian Audry:
 * https://github.com/sofian/libinteract/blob/master/trunk/arduino/Timer.h
 * http://accrochages.drone.ws/node/90
 * 
 * and Thomas O Fredericks (tof@t-o-f.info)
 * https://github.com/thomasfredericks/Chrono
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

Chrono::Chrono()
{
  restart();
}

void Chrono::restart() 
{
  _startTime = millis();
}

unsigned long Chrono::elapsed() const {
	return (millis() - _startTime);
}


bool Chrono::passed(unsigned long timeout) const
{
  return (elapsed() >= timeout);
}



