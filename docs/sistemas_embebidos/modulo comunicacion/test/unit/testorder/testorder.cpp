#include <unity.h>

#include <Arduino.h>

#include <AduinoFake.h>

#include "eleccionorder.h"
#include "messages.h"


void setup(void) {}

void tearDown(void) {}

void testorderadelante(void){
    When(Method(ArduinoFake(), message_adelante)).AlwaysReturn();

    order('F');

    Verify(Method(ArduinoFake(), message_adelante)).Once();

}

int main(void){

    UNITY_BEGIN();

    RUN_TEST(testorderadelante);

    UNITY_END();

    
    return 0;

}