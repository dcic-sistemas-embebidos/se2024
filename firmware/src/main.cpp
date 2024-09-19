#include <Arduino.h>

// Define el pin del LED (puede ser el pin 2 para la mayoría de las placas ESP32)
#define LED_PIN 2

void setup() {
    // Configura el pin del LED como salida
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    // Enciende el LED
    digitalWrite(LED_PIN, HIGH);
    delay(500);  // Espera 1 segundo
    
    // Apaga el LED
    digitalWrite(LED_PIN, LOW);
    delay(1000);  // Espera 1 segundo
}