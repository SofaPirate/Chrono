Chrono
=====================
Chrono library for Arduino or Wiring
by Sofian Audry
based on code by Thomas Ouellet Fredericks

Simple chronometer/stopwatch class that counts the time passed since started.
For a chronometer with more advanced features (pause, resume, add time, multiple time units support, etc) please use the [SuperChrono](http://github.com/sofian/SuperChrono) library.

Installation
=====================
Copy the Chrono folder to your Arduino libraries.


Basic Example
=====================
```arduino
#include <Chrono.h>

// Instanciate a Chrono object.
Chrono myChrono;

void setup() {
  // Start the chronometer on setup.
  myChrono.start();
}

void loop() {
  // Check whether the chronometer has reached 1000 ms
  if (myChrono.hasPassed(1000)) {
    // Do something here...
    // Restart the chrono.
    myChrono.start();
  }
}

```


Include the library
=====================
```arduino
// INCLUDE CHRONO LIBRARY :
#include <Chrono.h> 

```

Create an instance
=====================
Once a Chrono is created, it starts counting (in milliseconds).

```arduino
// CREATE A CHRONO INSTANCE :
Chrono myChrono;

```

start()
=====================

Starts/restarts the chronometer.

```arduino
// START/RESTART THE CHRONOMETER :
myChrono.start();

```


elapsed()
=====================

Returns the elasped time (in milliseconds).

```arduino
// GET ELAPSED MILLISECONDS :
unsigned long elapsed = myChrono.elapsed();

```


hasPassed(timeout)
=====================
Returns true if the chronometer passed the timeout in milliseconds.
```arduino
if ( myChrono.hasPassed(500) ) {
	// DO SOMETHING IF 500 MS HAVE PASSED.
}

```

Combined with start() you can have a metronome :
```arduino
if ( myChrono.hasPassed(200) ) {
  myChrono.start();
	// DO SOMETHING EVERY 200 MS.
}

```
