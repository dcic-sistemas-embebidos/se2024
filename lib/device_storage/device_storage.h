#ifndef DEVICE_STORAGE_H
#define DEVICE_STORAGE_H

void setupDS();
void loopDS();
void loadStoredDevices();
void addDevice(const String &deviceName);
bool _isDeviceStored(const String &deviceName);
void loadStoredDevices();
void _isDeviceStored();

#endif