#include <Arduino.h>

// Declaracion
const int IN1 = 18;  // Broche IN1 du L298N
const int IN2 = 19;  // Broche IN2 du L298N
const int ENA = 17;  // Broche ENA (PWM) du L298N

// Configuracion PWM
const int pwmChannel = 0;  // Canal PWM
const int pwmFrequency = 5000;  // frequency PWM en Hz
const int pwmResolution = 8;  // Résolucion PWM (8 bits, valores de 0 à 255)

void setup() {
  // Initialisacion
  Serial.begin(115200);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  // Link ENA to PWM
  ledcAttachPin(ENA, pwmChannel);

  // Configuracion del canal
  ledcSetup(pwmChannel, pwmFrequency, pwmResolution);
}

void loop() {

  Serial.println("Avancer");
  digitalWrite(IN1, HIGH);  // direccion
  digitalWrite(IN2, LOW);
  
  // Aumentacion de la velocidad
  for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
    ledcWrite(pwmChannel, dutyCycle); 
    delay(10);  
  }

  delay(2000);  

  for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) {
    ledcWrite(pwmChannel, dutyCycle); 
    delay(10); 
  }

  delay(2000); 

  Serial.println("Reverser");
  digitalWrite(IN1, LOW);  
  digitalWrite(IN2, HIGH);
  
  
  for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
    ledcWrite(pwmChannel, dutyCycle); 
    delay(10); 
  }

  delay(2000);  

  for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) {
    ledcWrite(pwmChannel, dutyCycle); 
    delay(10); 
  }

  delay(2000); 
}
