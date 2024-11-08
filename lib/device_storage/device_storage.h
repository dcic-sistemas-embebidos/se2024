#ifndef DEVICE_STORAGE_H
#define DEVICE_STORAGE_H

void setupDS();
void loopDS();
void loadStoredDevice(); // Carga el dispositivo almacenado 
void addDevice(const String &deviceName); // Agregar un nuevo dispositivo
bool _isDeviceStored(const String &deviceName); // Controla si el dispositivo esta almacenado

#endif