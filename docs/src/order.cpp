#include "order.h"
#include <Arduino.h>



void order(char estado){

    if (estado == 'F') { // Adelante
      Serial.println("Instrucción: Adelante");
      message_adelante();
      blink(5, 100); 
    }
    else if (estado == 'B') { // Atras
      Serial.println("Instrucción: Atrás");
      message_atras();
      blink(5, 300); 
    }
    else if (estado == 'R') { // Derecha
      Serial.println("Instrucción: Derecha");
      message_derecha();
      blink(3, 100); 
    }
    else if (estado == 'L') { // Izquierda
      Serial.println("Instrucción: Izquierda");
      message_izquierda();
      blink(3, 300); 
    }
    else if (estado == 'S') { // Parar
      Serial.println("Instrucción: Detener");
      message_detener();
      blink(3, 300); 
    } 
    else {
      Serial.println("Instrucción no reconocida.");
      message_error();
      blink(10, 50); 
    }
  }
  