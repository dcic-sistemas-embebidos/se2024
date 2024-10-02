#include <Arduino.h>
#include "dummy.h"

int leds_setup(void) {
    pinMode(2, OUTPUT);
    dummy_true();
    return 1;
}