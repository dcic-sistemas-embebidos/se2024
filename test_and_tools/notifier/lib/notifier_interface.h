#ifndef NOTIFIER_INTERFACE_H
#define NOTIFIER_INTERFACE_H

// Configura las salidas de las notificaciones
int setup();

// Notificaciones
void start();
void reset();
void powerOff();
void conection(char type);
void motor_move(int type);
void low_battery();

#endif