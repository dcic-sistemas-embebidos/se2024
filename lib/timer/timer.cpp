#include "timer.h"
#include <Ticker.h>

struct timer_struct{

    int ms;
    bool esta_activo;

}timers_array[10];

static Ticker ticker_timer;
static int timers_en_uso;

void incrementar_timers() {

    for (int i = 0; i < timers_en_uso; i++) {
        if (timers_array[i].esta_activo) {
            timers_array[i].ms += 1;
        }
    }
}

void iniciar_ticker() {
    
    ticker_timer.attach_ms(1, incrementar_timers);
}

void timer_setup(void) {

    iniciar_ticker();
    timers_en_uso = 0;
}

void timer_loop(void) {}

timer_struct generar_timer(void){

    timer_struct new_timer = {0, false};
    timers_array[timers_en_uso++] = new_timer;

    return new_timer;
}

void iniciar_timer(timer_struct *timer) {

    timer->esta_activo = true;
}

void detener_timer(timer_struct *timer) {

    timer->esta_activo= false;
}

void reiniciar_timer(timer_struct *timer) {

    timer->ms = 0;
}

int consultar_timer_ms(timer_struct *timer) {

    return timer->ms;
}

bool consultar_timer_actividad(timer_struct *timer) {

    return timer->esta_activo;
}