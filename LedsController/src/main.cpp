#include <Arduino.h>
#include <LedsController.h>


void setup() {
 ledscontroller_setup();
}

void loop() {
 delay(500);
 prenderled("rojo");
 delay(500);
 prenderled("amarillo");
 delay(500);
 prenderled("verde");
 delay(500);
 apagarled("amarillo");
 delay(500);
 apagarled("rojo");
 delay(500);
 apagarled("verde");
}

