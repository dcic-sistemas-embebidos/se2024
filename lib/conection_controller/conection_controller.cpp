#include <Arduino.h>
#include <BluetoothSerial.h>
#include <device_storage.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run make menuconfig to and enable it
#endif

BluetoothSerial SerialBT;
String estado = "";

void _serialEvent()
{
    while (SerialBT.available())
    {
        char inChar = (char)SerialBT.read();
        estado += inChar; // Concatenar el carácter recibido al estado
    }
}

void setupCC()
{
    // Iniciar Bluetooth
    if (!SerialBT.begin("ESP32_Device"))
    {
        Serial.println("¡Error al iniciar Bluetooth!");
        return;
    }
    setupDS();
}
void loopCC()
{
    if (SerialBT.available())
    {
        _serialEvent();
    }
    //Serial.println("Direccion: " + SerialBT.getBtAddress());
    loopDS();

    if (estado.length() > 0)
    {
        // Mostrar en el monitor serie el comando recibido
        if (estado == "F")
        { // Adelante
            Serial.println("Instrucción: Adelante");
        }
        else if (estado == "B")
        { // Atras
            Serial.println("Instrucción: Atrás");
        }
        else if (estado == "R")
        { // Derecha
            Serial.println("Instrucción: Derecha");
        }
        else if (estado == "L")
        { // Izquierda
            Serial.println("Instrucción: Izquierda");
        }
        else if (estado == "S")
        { // Parar
            Serial.println("Instrucción: Detener");
        }
        else
        {
            Serial.println("Instrucción no reconocida.");
        }

        estado = ""; // Limpiar el estado después de procesarlo
    }

    delay(100); // Retraso para evitar saturación de la comunicación serie
}