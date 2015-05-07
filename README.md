CHRONO
=====================
Chrono library for Arduino or Wiring
by Sofian Audry and Thomas Ouellet Fredericks

Chronometer/stopwatch library that counts the time passed since started.

Repository
=====================
http://github.com/thomasfredericks/Chrono
Download the latest version here : https://github.com/thomasfredericks/Chrono-Arduino-Wiring/archive/master.zip

Installation
=====================
Copy the Chrono folder to your Arduino libraries.


Basic Example
=====================
```arduino
// INCLUDE CHRONO LIBRARY
// Documentation : https://github.com/thomasfredericks/Chrono-Arduino-Wiring/blob/master/README.md
// Download : https://github.com/thomasfredericks/Chrono-Arduino-Wiring/archive/master.zip
#include <Chrono.h>

// Instanciate a Chrono object.
Chrono myChrono; 

void setup() {
  // Start the chronometer on setup.
  myChrono.start();
}

void loop() {
  // Check whether the chronometer has reached 1000 time units.
  if (myChrono.hasPassed(1000)) {
    // Do something here...
    // Restart the chronometer.
    myChrono.restart();
  }
}

```


Include the library
=====================
```arduino
// INCLUDE CHRONO LIBRARY : http://github.com/thomasfredericks/Chrono
#include <Chrono.h> 

```

Create an instance
=====================
Once a Chrono is created, it starts counting (in milliseconds).

```arduino
// CREATE A CHRONO INSTANCE :
Chrono myChrono;

```

You can create a Chrono that counts in microseconds or seconds:
```arduino
Chrono myChronoMicros(SuperChrono::MICROS);
Chrono myChronoSeconds(SuperChrono::SECONDS);

```

Alternatively you can create a Chrono with a custom time function:
```arduino
unsigned long mySpecialTimeFunction();

Chrono myChronoMicros(mySpecialTimeFunction);

```


elapsed()
=====================

Returns the elasped milliseconds.

```arduino
// GET ELAPSED MILLISECONDS :
unsigned long elapsed = myChrono.elapsed();

```

restart()
restart(offset)
=====================

Starts/restarts the chronometer.

```arduino
// RESTART THE CHRONOMETER :
myChrono.restart();

```

stop()
=====================

Stops/pauses the chronometer.

```arduino
// STOPS/PAUSES THE CHRONOMETER :
mySuperChrono.stop();

```

resume()
=====================

Resumes the chronometer.

```arduino
// STOPS/PAUSES THE CHRONOMETER :
mySuperChrono.stop();

```


hasPassed(timeout)
=====================
Returns true if the chronometer passed the timeout.
```arduino
if ( myChrono.hasPassed(500) ) {
	// DO SOMETHING IF 500 TIME UNITS HAVE PASSED.
}

```

Combined with restart() you can have a metronome :
```arduino
if ( myChrono.hasPassed(200) ) {
     myChrono.restart();
	// DO SOMETHING EVERY 200 TIME UNITS.
}

```

add(time)
=====================

Adds some time to the chronometer.

```arduino
// ADDS 500 TIME UNITS TO THE CHRONOMETER :
myChrono.add(500);

```

isRunning()
=====================

Returns true if the chronometer is currently running.

```arduino
myChrono.restart();
Serial.println( myChrono.isRunning() ); // will print "1" (true)
myChrono.stop();
Serial.println( myChrono.isRunning() ); // will print "0" (false)
myChrono.resume();
Serial.println( myChrono.isRunning() ); // will print "1" (true)

```

delay(time)
=====================

Waits for some time (in the time unit of the chronometer).

```arduino
// WAIT FOR 1000 TIME UNITS :
myChrono.delay(1000);

```