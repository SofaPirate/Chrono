CHRONO
=====================
Chrono library for Arduino or Wiring
by Thomas Ouellet Fredericks and Sofian Audry

This library facilitates the timing of events.

INSTALLATION
=====================
Copy the Chrono folder to your Arduino libraries.


Basic Example
=====================
```arduino
#include <Chrono.h>

// Instanciate a Chrono object.
Chrono myChrono;


 * Chrono myChrono; // chronometer automatically starts at creation
 * // ...
 * myChrono.start(); // you can start (restart) it later
 * while (!myChrono.passed(2000)) // a 2000 ms loop
 *  Serial.println(myChrono.elapsed()); // current time
 *   // do something
 * // ...
 */
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
myChrono.restart();

```


elapsed()
=====================

Returns the elasped time (in milliseconds).

```arduino
// GET ELAPSED MILLISECONDS :
unsigned long elapsed = myChrono.elapsed();

```


passed(interval)
=====================
Returns true if the chronometer passed the interval in milliseconds.
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
