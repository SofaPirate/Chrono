/*
Description
=============
L'Arduino envoie a chaque 20 ms le nombre de millisecondes
depuis qu'il a ete demarre en message ASCII.

Le message ASCII est compose des elements suivants:
1) "ms" suivi d'un espace
2) les millisecondes
3) indicateur de fin de ligne (retour de chariot)

Logitheques
=============
Cet exemple utilise la logitheque Chrono

Version originale : Thomas Ouellet Fredericks, 4 novembre 2012
Derniere version :  Thomas Ouellet Fredericks, 6 mai 2015
*/

// INCLUDE CHRONO LIBRARY : http://github.com/SofaPirate/Chrono
#include <Chrono.h> 

Chrono envoiMessage;


void setup() {

        // Demarrer la communication serie a 57600 baud.
        Serial.begin(57600);
}

void loop() {
          if (envoiMessage.hasPassed(20) ) { // returns true if 20 ms have passed.
                envoiMessage.restart();  // restart the Chrono 
                  Serial.print("ms "); // "ms" suivi d'un espace
                  Serial.print( millis() ); // la valeur de la mesure
                  Serial.println(); // indicateur de fin de ligne
        }     
}
