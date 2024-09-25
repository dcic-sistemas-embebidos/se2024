#include <Arduino.h>
#include "serial_interface.h" 

void setup() {
    // Inicializar el puerto serie y el LED
    serial_interface_begin();
}

void loop() {
    // Verificar si hay datos disponibles en el puerto serie
    if (Serial.available()) {
        // Leer el mensaje completo desde el puerto serie
        String message = Serial.readStringUntil('\n');
        message.trim(); 

        // Enviar el mensaje a process_commands para procesarlo
        process_commands(message);
    }
}
