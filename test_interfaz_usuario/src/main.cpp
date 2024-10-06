#include <Arduino.h>
#include <test_hw_interfaz.h>

void setup()
{
  // Inicialización del puerto serial
  Serial.begin(115200);
}

void loop()
{
  testLed(2);             // Prueba de led conectado al pin 2
  testPulsador(4);        // Prueba del pulsador conectado al pin 4
  testLCD("Test LCD",32); // (msj,pinSeñalAnaloga)
}
