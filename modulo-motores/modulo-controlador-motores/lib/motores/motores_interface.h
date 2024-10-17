#ifndef MOTORES_INTERFACE_H
#define MOTORES_INTERFACE_H

// Recibe el mensaje 
void recibir_mensaje();

// Configura los pines de salida y la señal PWM
int motores_setup();

// Movimientos del robot
void robot_avanzar();
void robot_detenerse();
void robot_girar_izquierda();
void robot_girar_derecha();

// Accion de los motores
void motorA_acelerar(int intensidad);
void motorB_acelerar(int intensidad);

#endif