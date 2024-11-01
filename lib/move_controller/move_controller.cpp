#include "move_controller.h"
#include "motor_driver.h"

// Velocidades para el movimiento de los motores
#define VELOCIDAD_MAXIMA 255
#define VELOCIDAD_GIRO 230
#define VELOCIDAD_DETENIDO 0

void move_controller_setup(void) {

    motor_driver_setup();
}

void move_controller_loop(void) {

    motor_driver_loop();
}

void robot_avanzar() {

    motorA_acelerar(VELOCIDAD_MAXIMA);
    motorB_acelerar(VELOCIDAD_MAXIMA);
}

void robot_retroceder() {

    motorA_retroceder(VELOCIDAD_MAXIMA);
    motorB_retroceder(VELOCIDAD_MAXIMA);
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