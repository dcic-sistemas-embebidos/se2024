#include <Arduino.h>
#include "reset_interface.h" 

void setup() {
    // Inicializar el puerto serie y el boton
    reset_interface_begin();
}

void loop() {
    // Verificar si hay datos disponibles en el puerto serie
    if (Serial.available()) {
        reset();
    }
}
