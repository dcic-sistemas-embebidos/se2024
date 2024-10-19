#ifndef MemoryOperations_H
#define MemoryOperations_H

#include <Arduino.h>
#include <Preferences.h>

int operacionsetpreferences(Preferences *preferences_param);
void operacionguardardatos(String direccionMAC, String codigo);
String operacionobtenermac();
String operacionobtenercodigo();

#endif
