#include <Arduino.h>
#include <test_hw_interfaz.h>

void setup()
{
  // Inicialización del puerto serial
  Serial.begin(115200);
}

void loop()
{
  testEntrada();
  testSalida();
}
