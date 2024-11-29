#include "eleccionorder.h"
#include "move_controller.h"
#include "motor_driver.h"
#include "move_controller.cpp"
#include "motor_driver.cpp"
#include <Arduino.h>
#include "BluetoothSerial.h"

#define LED_PIN 2

BluetoothSerial SerialBT; 

void bluetoothsetup(void){
  Serial.begin(115200); 
  SerialBT.begin("ESP32_Device"); 
  pinMode(LED_PIN, OUTPUT); 
}

void order(char estado) {
    if (estado == 'F') {
        robot_avanzar(); 
    }
    else if (estado == 'B') {
        robot_retroceder();
    }
    else if (estado == 'R') {
        robot_girar_derecha();
    }
    else if (estado == 'L') {
        robot_girar_izquierda();
    }
    else if (estado == 'S') {
        robot_detenerse();
    }
    else if (estado == '\0') {
        //no hace nada
    }
    else {
        //notify an error
    }
}

void orderloop(){
    if(SerialBT.available()){
    char msg = SerialBT.read();
    order(msg);
    }
    else{
    char msg = '\0';
    order(msg);
}
}

