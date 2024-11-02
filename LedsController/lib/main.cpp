#include <Arduino.h>
#include <LedsController.h>


void setup() {
 ledscontroller_setup();
}

void loop() {
 delay(500);
 prenderled(LED_ROJO);
 delay(500);
 prenderled(LED_AMARILLO);
 delay(500);
 prenderled(LED_VERDE);
 delay(500);
 apagarled(LED_AMARILLO);
 delay(500);
 apagarled(LED_VERDE);
 delay(500);
 apagarled(LED_ROJO);
}

