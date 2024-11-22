#ifndef MOVE_CONTROLLER_H
#define MOVE_CONTROLLER_H

// Inicializa el driver de motores
void move_controller_setup(void);

// Loop del controlador de movimientos
void move_controller_loop(void);

// Movimientos del robot
void robot_avanzar(void);
void robot_retroceder(void);
void robot_detenerse(void);
void robot_girar_izquierda(void);
void robot_girar_derecha(void);

#endif