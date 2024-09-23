#ifndef SERIAL_INTERFACE_H
#define SERIAL_INTERFACE_H

#include <Arduino.h>

#define LED_PIN 2 // Pin del LED 

// Función para inicializar el puerto serie y los pines
void serial_interface_begin();

// Función para procesar los comandos recibidos
void process_commands();

#endif 
