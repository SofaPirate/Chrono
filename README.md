SuperChrono
=====================
SuperChrono library for Arduino or Wiring
by Sofian Audry

Advanced chronometer/stopwatch class that counts the time passed since started.

Installation
=====================
Copy the SuperChrono folder to your Arduino libraries.


Basic Example
=====================
```arduino
#include <SuperChrono.h>

// Instanciate a SuperChrono object.
SuperChrono mySuperChrono;

void setup() {
  // Start the chronometer on setup.
  mySuperChrono.start();
}

void loop() {
  // Check whether the chronometer has reached 1000 ms
  if (mySuperChrono.hasPassed(1000)) {
    // Do something here...
    // Restart the SuperChrono.
    mySuperChrono.start();
  }
}

```


Include the library
=====================
```arduino
// INCLUDE SuperChrono LIBRARY :
#include <SuperChrono.h> 

```

Create an instance
=====================
Once a SuperChrono is created, it starts counting.

```arduino
// CREATE A SuperChrono INSTANCE :
SuperChrono mySuperChrono;

```

You can create a SuperChrono that counts in microseconds or seconds:
```arduino
SuperChrono mySuperChronoMicros(SuperChrono::MICROS);
SuperChrono mySuperChronoSeconds(SuperChrono::SECONDS);

```

Alternatively you can create a SuperChrono with a custom time function:
```arduino
unsigned long mySpecialTimeFunction();

SuperChrono mySuperChronoMicros(mySpecialTimeFunction);

```


start(offset)
=====================

Starts/restarts the chronometer.

```arduino
// START/RESTART THE CHRONOMETER :
mySuperChrono.start();

// START/RESTART THE CHRONOMETER WITH ALREADY 1000 TIME UNITS AS AN OFFSET :
mySuperChrono.start(1000);

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


elapsed()
=====================

Returns the elasped time.

```arduino
// GET ELAPSED MILLISECONDS :
unsigned long elapsed = mySuperChrono.elapsed();

```


hasPassed(timeout)
=====================
Returns true if the chronometer passed the timeout.
```arduino
if ( mySuperChrono.hasPassed(500) ) {
	// DO SOMETHING IF 500 TIME UNITS HAVE PASSED.
}

```

Combined with start() you can have a metronome :
```arduino
if ( mySuperChrono.hasPassed(200) ) {
  mySuperChrono.start();
	// DO SOMETHING EVERY 200 TIME UNITS.
}

```

add(time)
=====================

Adds some time to the chronometer.

```arduino
// ADDS 500 TIME UNITS TO THE CHRONOMETER :
mySuperChrono.add(500);

```

isRunning()
=====================

Returns true if the chronometer is currently running.

```arduino
mySuperChrono.start();
Serial.println( mySuperChrono.isRunning() ); // will print "1" (true)
mySuperChrono.stop();
Serial.println( mySuperChrono.isRunning() ); // will print "0" (false)
mySuperChrono.resume();
Serial.println( mySuperChrono.isRunning() ); // will print "1" (true)

```

delay(time)
=====================

Waits for some time (in the time unit of the chronometer).

```arduino
// WAIT FOR 1000 TIME UNITS :
mySuperChrono.delay(1000);

```


