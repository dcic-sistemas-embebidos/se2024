#include <Arduino.h>

const int buttonPin = 4; // GPIO 14 para el pulsador
const int ledPin5 = 5;

void pruebaLed()
{
    Serial.println("Prueba del led iniciada...");
  if (digitalRead(ledPin5) == LOW)
  {                              // Si el pulsador está presionado
    digitalWrite(ledPin5, HIGH); // Enciende el LED
    Serial.println("LED encendido..");
  }
  else
  {
    digitalWrite(ledPin5, LOW); // Apaga el LED
    Serial.println("LED apagado...");
  }
}

void pruebaPulsador()
{
  Serial.println("Prueba del pulsador iniciada...");
  // Leer el estado del pulsador
  int buttonState = digitalRead(buttonPin);

  // Imprimir el estado del pulsador en el monitor serial
  if (buttonState == LOW)
  { // Pulsador presionado
    Serial.println("Pulsador presionado");
  }
  else
  { // Pulsador no presionado
    Serial.println("Pulsador no presionado");
  }

  // Pequeña pausa para evitar demasiadas impresiones rápidas
  delay(500);
}