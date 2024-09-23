#include <Arduino.h>
#include "serial_interface.h" // Importamos el módulo de interfaz serie

void setup() {
    // Inicializar el puerto serie y el LED
    serial_interface_begin();
}

void loop() {
    // Procesar comandos entrantes
    process_commands();
}
