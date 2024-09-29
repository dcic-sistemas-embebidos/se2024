#include <Arduino.h>
#include "dummy.h"

void leds_setup(void) {
    pinMode(2, OUTPUT);
    dummy_true();
}
