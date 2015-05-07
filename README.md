CHRONO
=====================
Chrono library for Arduino or Wiring
by Thomas Ouellet Fredericks and Sofian Audry

Simple chronometer/stopwatch class that counts the time passed since started.
For a chronometer with more advanced features (pause, resume, add time, multiple time units support, etc) please use the [SuperChrono](http://github.com/sofian/SuperChrono) library.

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

hasPassed(timeout)
=====================
Returns true if the chronometer passed the timeout in milliseconds.
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
