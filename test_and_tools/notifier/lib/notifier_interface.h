#ifndef NOTIFIER_INTERFACE_H
#define NOTIFIER_INTERFACE_H

// Configura las salidas de las notificaciones
int setup();

// Notificaciones
void notify_start();
void notify_reset();
void notify_powerOff();
void notify_conection(char type);
void notify_motor_move(int type);
void notify_low_battery();

#endif