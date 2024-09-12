#include <Arduino.h>

const int ledPin = 17;  // GPIO XX

void setup() {
  // Initialisation
  Serial.begin(115200);

  // Configure le canal PWM avec une fréquence et une résolution de base
  ledcSetup(0, 5000, 8);  // Canal 0, fréquence 5000 Hz, résolution 8 bits
  ledcAttachPin(ledPin, 0);  // Attache la broche GPIO XX au canal 0

  // Démarre avec une luminosité de 0
  ledcWrite(0, 0);
}

void loop() {
  // Augmente la luminosité de 0 à 255
  for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
    ledcWrite(0, dutyCycle);  // Définit la luminosité de la LED
    delay(10);  
  }
  Serial.print("max");

  // Diminue la luminosité de 255 à 0
  for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) {
    ledcWrite(0, dutyCycle);  // Définit la luminosité de la LED
    delay(10);  
  }
}