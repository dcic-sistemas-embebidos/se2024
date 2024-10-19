#ifndef Memory_H
#define Memory_H

#include <Arduino.h>
#include <Preferences.h>

int memorysetup();
void memoryloop();
void guardardatos(String direccionMAC, String codigo);
String obtenermac();
String obtenercodigo();

#endif