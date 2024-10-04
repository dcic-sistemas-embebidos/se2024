#include <Arduino.h>
#include <test_hw_interfaz.h>

void setup()
{
  // Inicialización del puerto serial
  Serial.begin(115200);
}

void loop()
{
  testLCD("Test LCD");
  //testLed();      // Prueba de led conectado al pin 2
  //testPulsador(); // Prueba del pulsador conectado al pin 4
}
