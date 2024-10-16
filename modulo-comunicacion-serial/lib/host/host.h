#ifndef HOST_H
#define HOST_H

#include <Arduino.h>

void host_setup(void);
void host_tx(uint8_t *data, size_t len);
String host_rx(void);
void process_commands(String command);

#endif 