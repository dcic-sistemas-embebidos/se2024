#ifndef MOTORES_INTERFACE_H
#define MOTORES_INTERFACE_H

#include <Arduino.h>

// Motor A
#define ENA 17 // TX2
#define IN1 18 // D18
#define IN2 19 // D19

// Motor B
#define ENB 21 // D21
#define IN3 22 // D22
#define IN4 23 // D23

// Configura los pines de salida y la señal PWM
void configurar_salidas();

// Módulo de movimiento del robot
void avanzar();
void detener();
void girar_derecha();
void girar_izquierda();

// Módulo de acción de los motores
void motorA_acelerar(int intensidad);
void motorB_acelerar(int intensidad);

#endif