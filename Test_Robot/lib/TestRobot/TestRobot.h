#ifndef TestRobot_H
#define TestRobot_H

#define PROBAR_LEDS 1
#define PROBAR_MOTORES 2
#define PROBAR_DISPLAY 3

void testrobot_setup(void);
void testrobot_loop(void);
void procesar_comando(int comando);
#endif