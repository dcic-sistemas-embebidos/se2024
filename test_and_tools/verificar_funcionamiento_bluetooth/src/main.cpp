#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#define LED 13 // Valor 2 para led integrado en ESP32

BluetoothSerial BT; // Objeto Bluetooth

void setup() 
{
  BT.begin("ESP32_Embebidos"); // Nombre de su dispositivo Bluetooth y en modo esclavo
  pinMode (LED, OUTPUT); // Cambie el pin LED a OUTPUT
}
void loop() 
{
  if (BT.available()) // Compruebe si recibimos algo de Bluetooth
  {
    int incoming = BT.read(); // Lee lo que recibimos

    if (incoming == 49){ // 1 en ASCII
      digitalWrite(LED, HIGH); // LED Encendido
      BT.println("LED encendido"); // Envía el mensaje de texto a través de BT Serial
    }

    if (incoming == 48){ // 0 en ASCII
      digitalWrite(LED, LOW); // LED Apagado
      BT.println("LED apagado"); // Envía el mensaje de texto a través de BT Serial
    }
  }

  delay(20);
}