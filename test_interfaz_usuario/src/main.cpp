#include <Arduino.h>
#include <test_hw_interfaz.cpp>

void setup()
{
  // Inicialización del puerto serial
  Serial.begin(115200);

  // Configurar el pin 14 como entrada para el pulsador con resistencia pull-up
  pinMode(buttonPin, INPUT_PULLUP);

  // Configurar el pin 5 como salida para el LED
  pinMode(ledPin5, OUTPUT);
  digitalWrite(ledPin5, LOW); // Comienza con el LED apagado
}

void loop()
{
  pruebaLed(); // Prueba de led conectado al pin 5
  pruebaPulsador(); // Prueba del pulsador conectado al pin 4
}
