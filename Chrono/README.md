CHRONO
=====================

Chrono library for Arduino or Wiring
by Thomas Ouellet Fredericks

This library facilitates the timing of events.


Basic Example
=====================

```
// INCLUDE CHRONO LIBRARY
// Documentation : https://github.com/thomasfredericks/Chrono-Arduino-Wiring/blob/master/README.md
// Download : https://github.com/thomasfredericks/Chrono-Arduino-Wiring/archive/master.zip

// Instanciate a Chrono object.
Chrono myChrono; 

void setup() {
}

void loop() {
  // Use Chrono as a metronome with an interval of 1000 ms : 
  if (myChrono.metro(1000) ) { // metro(1000) returns 1 everytime an interval of 1000 is passed.
    // Do something here...
  }
}

```


Include the library
=====================

```
// INCLUDE CHRONO LIBRARY :
#include <Chrono.h> 

```

Create an instance
=====================

Once a Chrono is created, it starts counting (in milliseconds).

```
// CREATE A CHRONO INSTANCE :
Chrono myChrono;

```

get()
=====================

Returns the elasped milliseconds.

```
// GET ELAPSED MILLISECONDS :
unsigned long elapsed = myChrono.get();

```

restart()
=====================

Restarts the chronometer.

```
// RESTART THE CHRONOMETER :
myChrono.restart();

```

metro(interval) and qmetro(interval)
=====================

You can use Chrono as a metronome for recurring events. 
Each call to metro(interval) or qmetro(interval) checks if the interval has passed. 
* If the interval has passed, it returns 1 and restarts the chronometer . 
* If the interval has not passed, it returns 0.

```
// USE CHRONO AS A METRONOME :
if ( myChrono.metro(1000) ) {
	// Do something every 1000 milliseconds.
}

```

```
// USE CHRONO AS A Q METRONOME :
if ( myChrono.qmetro(1000) ) {
	// Do something every 1000 milliseconds.
}

```


qmetro(interval) and metro(interval) are the same except in the way the inteval is calculated.

metro adds the interval to time the metro _should_ have triggered. If your code takes to long for the interval, the lag will be substracted from the next interval.

qmetro calculates the interval from the last time it triggered. This means that it can accumulate lag over time, but is more appropriate in certain situations.

