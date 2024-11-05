#ifndef TIMER
#define TIMER

void timer_setup(void);
void timer_loop(void);

timer_struct generar_timer(void);
void iniciar_timer(*timer_struct);
void detener_timer(*timer_struct);
void reiniciar_timer(*timer_struct);
int consultar_timer(*timer_struct);

#endif