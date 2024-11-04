#ifndef LedsController_H
#define LedsController_H

#define LED_ROJO 1
#define LED_VERDE 2
#define LED_AMARILLO 3 
 
void ledscontroller_setup();
void ledscontroller_loop();
void prenderled(int colorled);
void apagarled(int colorled);

#endif