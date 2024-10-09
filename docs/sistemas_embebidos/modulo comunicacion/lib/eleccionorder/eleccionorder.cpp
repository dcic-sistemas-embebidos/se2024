#include "eleccionorder.h"
#include "messages.h"
#include <Arduino.h>
#include "BluetoothSerial.h"

const int LED_PIN = 2; // Define the pin number

BluetoothSerial SerialBT; 

void bluetoothsetup(void){
  Serial.begin(115200); 
  SerialBT.begin("ESP32_Device"); 
  pinMode(LED_PIN, OUTPUT); 
  Serial.println("El dispositivo está listo para emparejarse.");

}

void order(char estado) {
    if (estado == 'F') {
        Serial.println("Instrucción: Adelante");
        message_adelante();
        //blink(5, 100);
    }
    else if (estado == 'B') {
        Serial.println("Instrucción: Atrás");
        message_atras();
        //blink(5, 300);
    }
    else if (estado == 'R') {
        Serial.println("Instrucción: Derecha");
        message_derecha();
        //blink(3, 100);
    }
    else if (estado == 'L') {
        Serial.println("Instrucción: Izquierda");
        message_izquierda();
        //blink(3, 300);
    }
    else if (estado == 'S') {
        Serial.println("Instrucción: Detener");
        message_detener();
        //blink(3, 300);
    }
    else if (estado == '\0') {
        message_nonuevo();
    }
    else {
        Serial.println("Instrucción no reconocida.");
        message_error();
        //blink(10, 50);
    }
}

char orderloop(){
    if(SerialBT.available()){
    char msg = SerialBT.read();
    Serial.print("Recibido : "); 
    Serial.println(msg);
    return(msg);
    }
    else{
    //Serial.print("No nueno : ");
    char msg = '\0';
    //Serial.println(msg);
    return(msg);
}
}

/*
void blink(int times, int delayTime) {
    for (int i = 0; i < times; i++) {
        digitalWrite(LED_PIN, HIGH);
        delay(delayTime);
        digitalWrite(LED_PIN, LOW);
        delay(delayTime);
    }
}
*/

