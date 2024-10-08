#ifndef HOST_H
#define HOST_H

#include <Arduino.h>

#define LED_PIN 2 // Pin del LED 

void host_setup(void);
void _tx(uint8_t *data, size_t len);
String _rx(void);
void process_commands(String command);

#endif 