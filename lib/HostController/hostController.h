#ifndef HOSTCONTROLLER_H
#define HOSTCONTROLLER_H

#include <Arduino.h>

void host_controller_loop();
void host_controller_setup(void);
void host_controller_tx(uint8_t *data, size_t len);
String host_controller_rx(void);
void process_commands(String command);

#endif 