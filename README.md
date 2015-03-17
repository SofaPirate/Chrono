CHRONO
=====================
Chrono library for Arduino or Wiring
by Thomas Ouellet Fredericks

This library facilitates the timing of events.


DOWNLOAD
=====================
Download the latest version here : https://github.com/thomasfredericks/Chrono-Arduino-Wiring/archive/master.zip


INSTALLATION
=====================
Copy the Chrono folder to your Arduino libraries.


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

elapsed()
=====================

Returns the elasped milliseconds.

```
// GET ELAPSED MILLISECONDS :
unsigned long elapsed = myChrono.elapsed();

```

restart()
=====================

Restarts the chronometer.

```
// RESTART THE CHRONOMETER :
myChrono.restart();

```

passed(interval)
=====================
Returns true if the chronometer passed the interval in milliseconds.
```
if ( myChrono.passed(500) ) {
	// DO SOMETHING IF 500 MS HAVE PASSED.
}

```

Combined with restart() you can have a metronome :
```
if ( myChrono.passed(200) ) {
     myChrono.restart();
	// DO SOMETHING EVERY 200 MS.
}

```