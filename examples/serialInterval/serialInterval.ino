/*
Description
=============
L'Arduino effectue a chaque 20 ms une mesure de la tension
de la broche analogique 0 et envoie la valeur sous forme de message ASCII.

Le message ASCII est compose des elements suivants:
1) "A0" suivi d'un espace
2) la valeur de la mesure
3) indicateur de fin de ligne (retour de chariot)

Circuit
=============
Broche analogique 0: un capteur analogique.

Logitheques
=============
Cet exemple utilise la logitheque Chrono

Version originale : Thomas Ouellet Fredericks, 4 novembre 2012
Derniere version :  Thomas Ouellet Fredericks, 23 septembre 2014
*/

// INCLUDE CHRONO LIBRARY : http://github.com/SofaPirate/Chrono
#include <Chrono.h> 

Chrono envoiMessage;

int mesurePrecedente;

void setup() {

        // Demarrer la communication serie a  57600 baud.
        Serial.begin(57600);
}

void loop() {

        if ( envoiMessage.hasPassed(20) ) {
		    envoiMessage.restart();
               
                // Mesurer la tension a la broche analogique 0 :
                int nouvelleMesure = analogRead(0);
                
                // Comparer la nouvelleMesure avec la precedente :
                if ( mesurePrecedente != nouvelleMesure ) {
                  // Enregistrer la nouvelleMesure :
                  mesurePrecedente = nouvelleMesure;
                  
                  // Envoyer la valeur du potentiometre.
                  Serial.print("A0 "); // "A0" suivi d'un espace
                  Serial.print(nouvelleMesure); // la valeur de la mesure
                  Serial.println(); // indicateur de fin de ligne
                  /* 
                  // Le bloc precedent peut aussi etre ecrit ainsi:
                  Serial.print("A0 "); // "A0" suivi d'un espace
                  Serial.println(valeur); // la valeur suivi de l'indicateur de fin de ligne
                  */
                }

        }
}
