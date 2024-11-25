#ifndef MOVE_CONTROLLER_INTERFACE_H
#define MOVE_CONTROLLER_INTERFACE_H

// Configura los pines de salida y la señal PWM
int move_setup();

int loop();

// Movimientos del robot
void robot_avanzar();
void robot_detenerse();
void robot_girar_izquierda();
void robot_girar_derecha();

#endif