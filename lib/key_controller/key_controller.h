#ifndef KEY_CONTROLLER_H
#define KEY_CONTROLLER_H

void setupKC();
void loopKC();
void _readButtonsDisplay(int pin_button_display);
void _pressingBtn(int pin_pulsador);
void _pressingKey(int pin_key);
bool pressRight();
bool pressLeft();
bool pressUp();
bool pressDown();
bool pressKey();
bool pressBtn();

#endif