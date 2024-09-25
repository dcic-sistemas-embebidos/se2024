#include "BluetoothSerial.h"

#include <Arduino.h>

#include "order.h"



BluetoothSerial SerialBT; 

const int LED_PIN = 2; // LED ESP

void blink(int times, int delayTime) { 
  for (int i = 0; i < times; i++) {
    digitalWrite(LED_PIN, HIGH); 
    delay(delayTime); 
    digitalWrite(LED_PIN, LOW); 
    delay(delayTime); 
  }
}

void message_adelante(){
  Serial.println("Mock: ADelante");
//debe ser en el modulo de los motores
}

void message_atras(){
  Serial.println("Mock: Atras");
//debe ser en el modulo de los motores
}

void message_derecha(){
  Serial.println("Mock: Derecha");
//debe ser en el modulo de los motores
}

void message_izquierda(){
  Serial.println("Mock: Izquierda");
//debe ser en el modulo de los motores
}

void message_detener(){
  Serial.println("Mock: Detener");
//debe ser en el modulo de los motores
}

void message_error(){
  Serial.println("Mock: Error");
//debe ser en el modulo de los motores
}




void setup() {
  Serial.begin(115200); 
  SerialBT.begin("ESP32_Device"); 
  pinMode(LED_PIN, OUTPUT); 
  Serial.println("El dispositivo está listo para emparejarse.");

}

void loop() {
  if (SerialBT.available()) {
    char msg = SerialBT.read();
    Serial.print("Recibido : "); 
    Serial.println(msg);
    order(msg);
  }
  delay(50); // Retraso para evitar saturación de la comunicación serie

}


