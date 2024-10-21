#include <Arduino.h>
#include "motores_interface.h"
#include "move_controller.h"

#define VELOCIDAD_MAXIMA 255
#define VELOCIDAD_GIRO 210
#define VELOCIDAD_DETENIDO 0

int move_setup() {
    motores_setup();
    return 1;
}

int loop(){}

// Módulo de movimiento
void robot_avanzar() {
    motorA_acelerar(VELOCIDAD_MAXIMA);
    motorB_acelerar(VELOCIDAD_MAXIMA);
}

void robot_detenerse() {
    motorA_acelerar(VELOCIDAD_DETENIDO);
    motorB_acelerar(VELOCIDAD_DETENIDO);
}

void robot_girar_izquierda() {
    motorA_acelerar(VELOCIDAD_DETENIDO);
    motorB_acelerar(VELOCIDAD_GIRO);
}

void robot_girar_derecha() {
    motorA_acelerar(VELOCIDAD_GIRO);
    motorB_acelerar(VELOCIDAD_DETENIDO);
}