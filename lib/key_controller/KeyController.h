#ifndef KEY_CONTROLLER_H
#define KEY_CONTROLLER_H

void setupKC();
void loopKC();
void _readButtonsDisplay(int pin_button_display);
void _pressingPulse(int pin_pulsador);
void _pressingKey(int pin_key);

#endif