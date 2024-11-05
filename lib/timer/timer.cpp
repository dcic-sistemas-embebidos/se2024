#include "timer.h"
#include <Ticker.h>

struct timer_struct{

    Ticker timer;
    int ms;

}timers_array[10];

int timers_en_uso;

void timer_setup(void) {

    timers_en_uso = 0;
}

void timer_loop(void) {}

timer_struct generar_timer(void){

    Ticker timer_ticker;
    timer_struct new_timer = {timer_ticker, 0};

    timers_array[timers_en_uso++] = new_timer;

    return new_timer;
}

void incrementar_timer(*timer_struct) {

    *timer_struct.ms += 1;
}

void iniciar_timer(*timer_struct) {

    *timer_struct.timer.attach_ms(1, incrementar_timer(&timer_struct));
}

void detener_timer(*timer_struct) {

    *timer_struct.timer.detach();
}

void reiniciar_timer(*timer_struct) {

    *timer_struct.timer.detach();
    *timer_struct.ms = 0;
    *timer_struct.timer.attach_ms(1, incrementar_timer(&timer_struct));
}

int consultar_timer(*timer_struct) {

    return *timer_struct.ms;
}