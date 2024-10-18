#include <Arduino.h>
#include "motor_driver.h"

// Motor A
#define PWM_MOTOR_A 17 // TX2
#define INPUT_1_MOTOR_A 18 // D18
#define INPUT_2_MOTOR_A 19 // D19

// Motor B
#define PWM_MOTOR_B 21 // D21
#define INPUT_1_MOTOR_B 22 // D22
#define INPUT_2_MOTOR_B 23 // D23

// Configuración PWM
#define PWM_CANAL_A 0  // Canal PWM para el motor A
#define PWM_CANAL_B 1  // Canal PWM para el motor B
#define PWM_FRECUENCIA 5000  // Frecuencia PWM en Hz
#define PWM_RESOLUCION 8  // Resolucion PWM (8 bits, valores de 0 a 255)

void setup(void) {}

void loop(void) {}

void motor_driver_setup() {

    // Configuración motor A
    pinMode(INPUT_1_MOTOR_A, OUTPUT);
    pinMode(INPUT_2_MOTOR_A, OUTPUT);
    pinMode(PWM_MOTOR_A, OUTPUT);

    // Configuración motor B
    pinMode(INPUT_1_MOTOR_B, OUTPUT);
    pinMode(INPUT_2_MOTOR_B, OUTPUT);
    pinMode(PWM_MOTOR_B, OUTPUT);

    // Configuración salidas PWM para motores A y B
    ledcAttachPin(PWM_MOTOR_A, PWM_CANAL_A);
    ledcAttachPin(PWM_MOTOR_B, PWM_CANAL_B);

    // Configuración canales PWM
    ledcSetup(PWM_CANAL_A, PWM_FRECUENCIA, PWM_RESOLUCION);
    ledcSetup(PWM_CANAL_B, PWM_FRECUENCIA, PWM_RESOLUCION);
}

void motorA_acelerar(int intensidad) {

    digitalWrite(INPUT_1_MOTOR_A, HIGH);
    digitalWrite(INPUT_2_MOTOR_A, LOW);

    ledcWrite(PWM_CANAL_A, intensidad);
}

void motorB_acelerar(int intensidad) {
  
    digitalWrite(INPUT_1_MOTOR_B, HIGH);
    digitalWrite(INPUT_2_MOTOR_B, LOW);
    
    ledcWrite(PWM_CANAL_B, intensidad);
}