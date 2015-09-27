# CHRONO
Chrono library for Arduino or Wiring
by Sofian Audry and Thomas Ouellet Fredericks

Chronometer/stopwatch library that counts the time passed since started.

## Repository

http://github.com/thomasfredericks/Chrono

Download the latest version here : https://github.com/thomasfredericks/Chrono-Arduino-Wiring/archive/master.zip

## Installation
Copy the Chrono folder to your Arduino libraries.


## Basic Example
```arduino
// INCLUDE CHRONO LIBRARY
// Download : https://github.com/thomasfredericks/Chrono/archive/master.zip
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

## Usage

### Include the library

```arduino
// INCLUDE CHRONO LIBRARY : http://github.com/thomasfredericks/Chrono
#include <Chrono.h> 

```

### Create an instance
Once a Chrono is created, it starts counting (in milliseconds by default).

```arduino
// CREATE A CHRONO INSTANCE :
Chrono myChrono;

```

#### Time units
You can create a Chrono that counts in microseconds or seconds:
```arduino
Chrono myChronoMicros(Chrono::MICROS);
Chrono myChronoSeconds(Chrono::SECONDS);

```

Alternatively you can create a Chrono with a custom time function:
```arduino
unsigned long mySpecialTimeFunction();

Chrono myChronoMicros(mySpecialTimeFunction);

```


### elapsed()

Returns the elapsed milliseconds.

```arduino
// GET ELAPSED MILLISECONDS :
unsigned long elapsed = myChrono.elapsed();

```

### restart()

Starts/restarts the chronometer.

```arduino
// RESTART THE CHRONOMETER :
myChrono.restart();

```

#### restart(offset)

You can alternatively start the chronometer with a time offset:
```arduino
// RESTART THE CHRONOMETER WITH AN OFFSET OF 1000 TIME UNITS :
myChrono.restart(1000);

```


### stop()

Stops/pauses the chronometer.

```arduino
// STOPS/PAUSES THE CHRONOMETER :
myChrono.stop();

```

### resume()

Resumes the chronometer.

```arduino
// STOPS/PAUSES THE CHRONOMETER :
myChrono.stop();

```


### hasPassed(timeout)
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

#### hasPassed(timeout,restartIfPassed)

The metronome code above can be written more simply by setting the restartIfPassed argument to true, which will 
automatically restart the chronometer if timeout is passed :
```arduino
// when passed 200 time units, the chrono will restart and the function will return true
if ( myChrono.hasPassed(200, true) ) { 
	// DO SOMETHING EVERY 200 TIME UNITS.
}

```


### add(time)

Immediately adds some time to the chronometer.

```arduino
// ADDS 500 TIME UNITS TO THE CHRONOMETER :
myChrono.add(500);

```

### isRunning()

Returns true if the chronometer is currently running.

```arduino
myChrono.restart();
Serial.println( myChrono.isRunning() ); // will print "1" (true)
myChrono.stop();
Serial.println( myChrono.isRunning() ); // will print "0" (false)
myChrono.resume();
Serial.println( myChrono.isRunning() ); // will print "1" (true)

```

### delay(time)

Waits for some time (in the time unit of the chronometer).

```arduino
// WAIT FOR 1000 TIME UNITS :
myChrono.delay(1000);

```

## LightChrono

The Chrono library provides a lightweight version of the Chrono class called LightChrono, with a lower memory trace but less functionalities.
LightChrono works in milliseconds only and provides only the following methods :
* elapsed()
* hasPassed(timeOut)
* hasPassed(timeOut, restartIfPassed)
* restart() (no offset option)

To use the LightChrono class instead of the Chrono class just include the LightChrono.h file and declare LightChrono objects :

```arduino
#include <LightChrono.h> 

LightChrono myChrono;

```

