#include <Arduino.h>
#include "host.h"

void setup() {
    
    host_setup();
    const char* message = "Interfaz de Comunicación Iniciada.\n";
    _tx((uint8_t*)message, strlen(message));
}

void loop() {
    
    String receivedCommand = _rx();

    
    if (receivedCommand != "") {
        process_commands(receivedCommand);
    }

    delay(100);  
}