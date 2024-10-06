#ifndef Memoria_H
#define Memoria_H

#include <Arduino.h>
#include <Preferences.h>

int set_preferences(Preferences *preferences_param);
void GuardarDatos(String direccionMAC, String codigo);
String ObtenerMAC();
String ObtenerCodigo();

#endif