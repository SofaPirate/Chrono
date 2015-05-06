CHRONO
=====================
Chrono library for Arduino or Wiring
by Thomas Ouellet Fredericks

This library facilitates the timing of events.


REPOSITORY
=====================
http://github.com/thomasfredericks/Chrono


INSTALLATION
=====================
Copy the Chrono folder to your Arduino libraries.


BASIC EXAMPLE
=====================
```arduino
// INCLUDE CHRONO LIBRARY : http://github.com/thomasfredericks/Chrono
#include <Chrono.h>

// Instanciate a Chrono object.
Chrono myChrono; 

void setup() {
}

void loop() {
  // Use Chrono as a metronome with an interval of 1000 ms : 
  if (myChrono.hasPassed(1000) ) { // returns 1 if 1000 ms have passed.
     myChrono.restart(); // restart the Chrono
    // Do something here...
  }
}

```


INCLUDE THE LIBRARY
=====================
```arduino
// INCLUDE CHRONO LIBRARY : http://github.com/thomasfredericks/Chrono
#include <Chrono.h> 

```

CREATE AN INSTANCE
=====================
Once a Chrono is created, it starts counting (in milliseconds).

```arduino
// CREATE A CHRONO INSTANCE :
Chrono myChrono;

```

elapsed()
=====================

Returns the elasped milliseconds.

```arduino
// GET ELAPSED MILLISECONDS :
unsigned long elapsed = myChrono.elapsed();

```

restart()
=====================

Restarts the chronometer.

```arduino
// RESTART THE CHRONOMETER :
myChrono.restart();

```

hasPassed(interval)
=====================
Returns true if the chronometer passed the interval in milliseconds.
```arduino
if ( myChrono.hasPassed(500) ) {
	// DO SOMETHING IF 500 MS HAVE PASSED.
}

```

Combined with restart() you can have a metronome :
```arduino
if ( myChrono.hasPassed(200) ) {
     myChrono.restart();
	// DO SOMETHING EVERY 200 MS.
}

```
