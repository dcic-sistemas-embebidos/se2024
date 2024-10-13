#include <ArduinoFake.h>
#include <unity.h>

using namespace fakeit;

#include "motores_interface.h"

void setUp(void) {}

void tearDown(void) {}

void test_robot_avanzando(void) {

    When(Method(ArduinoFake(), digitalWrite)).AlwaysReturn();
    //When(Method(ArduinoFake(), ledcWrite)).AlwaysReturn();

    robot_avanzar();

    Verify(Method(ArduinoFake(), digitalWrite).Using(18, HIGH)).Once();
    Verify(Method(ArduinoFake(), digitalWrite).Using(19, LOW)).Once();
    Verify(Method(ArduinoFake(), digitalWrite).Using(22, HIGH)).Once();
    Verify(Method(ArduinoFake(), digitalWrite).Using(23, LOW)).Once();

    //Verify(Method(ArduinoFake(), ledcWrite).Using(255)).Once();

/*Hice funcionar los digitalWrite, me falta ver los ledcWrite con mis mock o los de arduinoFake*/
}

void test_robot_detenido(void) {

    robot_detenerse();
}

void test_robot_girando_izquierda(void) {

    robot_girar_izquierda();
}

void test_robot_girando_derecha(void) {

    robot_girar_derecha();
}

int main(int argc, char **argv) {

    UNITY_BEGIN();

    RUN_TEST(test_robot_avanzando);

    UNITY_END();

    return 0;
}