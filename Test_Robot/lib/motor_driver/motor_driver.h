#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H

// Configura los pines de salida y la señal PWM
void motor_driver_setup(void);

// Loop del driver de motores
void motor_driver_loop(void);

// Accion de los motores
void motorA_acelerar(int intensidad);
void motorB_acelerar(int intensidad);

#endif