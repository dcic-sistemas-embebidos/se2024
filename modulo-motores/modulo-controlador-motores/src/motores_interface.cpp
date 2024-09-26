#include "motores_interface.h"

const int pwm_canal_a = 0;  // Canal PWM para el motor A
const int pwm_canal_b = 1;  // Canal PWM para el motor B
const int pwm_frecuencia = 5000;  // Frecuencia PWM en Hz
const int pwm_resolucion = 8;  // Resolucion PWM (8 bits, valores de 0 a 255)
const int velocidad_maxima = 255;
const int velocidad_giro = 210;
const int velocidad_detenido = 0;

void configurar_salidas() {

    // Configuracion motor A
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(ENA, OUTPUT);

    // Configuracion motor B
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    pinMode(ENB, OUTPUT);

    // Configuracion salidas ENA y ENB como PWM
    ledcAttachPin(ENA, pwm_canal_a);
    ledcAttachPin(ENB, pwm_canal_b);

    // Configuracion canales PWM
    ledcSetup(pwm_canal_a, pwm_frecuencia, pwm_resolucion);
    ledcSetup(pwm_canal_b, pwm_frecuencia, pwm_resolucion);
}

// Módulo de movimiento del robot
void avanzar() {

    motorA_acelerar(velocidad_maxima);
    motorB_acelerar(velocidad_maxima);
}

void detener() {

    motorA_acelerar(velocidad_detenido);
    motorB_acelerar(velocidad_detenido);
}

void girar_izquierda() {

    motorA_acelerar(velocidad_detenido);
    motorB_acelerar(velocidad_giro);
}

void girar_derecha() {

    motorA_acelerar(velocidad_giro);
    motorB_acelerar(velocidad_detenido);
}

// Módulo de acción de los motores
void motorA_acelerar(int intensidad) {

    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);

    ledcWrite(pwm_canal_a, intensidad);
}

void motorB_acelerar(int intensidad) {
  
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    
    ledcWrite(pwm_canal_b, intensidad);
}