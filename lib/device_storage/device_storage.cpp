#include <Arduino.h>
#include <Preferences.h>

Preferences preferences;
String deviceName;
bool hasDeviceConnected = false;
bool hasDevicePaired = false;

// Cargar dispositivo guardado
void loadStoredDevice()
{
  deviceName = preferences.getString("ESP32_Device", "");
  if (deviceName.length() > 0)
  {
    Serial.println("Dispositivo cargado desde NVS: " + deviceName);
  }
  else
  {
    Serial.println("No hay dispositivo almacenado en NVS.");
  }
}

// Guardar el dispositivo en la NVS
void addDevice(const String &newDeviceName)
{
  if (!hasDeviceConnected)
  {
    preferences.putString("ESP32_Device", newDeviceName); // Guardar nombre en NVS
    deviceName = newDeviceName;
    Serial.println("Nuevo dispositivo guardado: " + newDeviceName);
    hasDeviceConnected = true; // Actualizar bandera
    hasDevicePaired = true;
  }
  else
  {
    Serial.println("Ya existe un dispositivo guardado.");
  }
}

// Verificar si el dispositivo ya está guardado
bool _isDeviceStored(const String &newDeviceName)
{
  // Verificar si ya hay un dispositivo emparejado guardado
  hasDevicePaired = preferences.getBool("device_paired", false);
  // Si no había un dispositivo emparejado, marcarlo ahora
  if (!hasDevicePaired)
  {
    hasDevicePaired = true;
    preferences.putBool("device_paired", hasDevicePaired);
    Serial.println("Dispositivo emparejado y guardado en NVS.");
  }
  return hasDevicePaired;
}

void setupDS()
{
  Serial.begin(115200);

  // Inicializar almacenamiento NVS
  preferences.begin("bt_prefs", false);

  // Cargar dispositivos guardados
  loadStoredDevice();

  // Intentar reconectar con el dispositivo guardado
  if (deviceName.length() > 0)
  {
    Serial.println("Intentando reconectar con el dispositivo: " + deviceName);
    // Implementa aquí la lógica de reconexión
    addDevice("pasar un nombre");
  }
  else
  {
    Serial.println("Esperando emparejamiento de un nuevo dispositivo...");
  }
}

void loopDS()
{
  // Simulación: intentar guardar un dispositivo si no está almacenado
  String newDeviceName = "ESP32_Device"; // Ejemplo de nombre de dispositivo
  if (!_isDeviceStored(newDeviceName))
  {
    addDevice(newDeviceName); // Almacenar el nuevo dispositivo
  }
}
