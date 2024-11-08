#ifndef TIMER
#define TIMER

struct timer_struct;

void timer_setup(void);
void timer_loop(void);

timer_struct generar_timer(void);
void iniciar_timer(timer_struct *timer);
void detener_timer(timer_struct *timer);
void reiniciar_timer(timer_struct *timer);
int consultar_timer_ms(timer_struct *timer);
bool consultar_timer_actividad(timer_struct *timer);

#endif