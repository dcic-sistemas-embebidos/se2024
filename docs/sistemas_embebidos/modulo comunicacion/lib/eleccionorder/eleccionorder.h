#ifndef ELECCIONORDER_H
#define ELECCIONORDER_H

extern const int LED_PIN; // Declare LED_PIN as an external variable

void order(char estado);
void blink(int times, int delayTime);
void bluetoothsetup(void);
void orderloop(void);

#endif
