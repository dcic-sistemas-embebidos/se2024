#include <ArduinoFake.h>
#include <unity.h>

using namespace fakeit;

#include "motores_interface.h"

struct Dummy {
    
    virtual int dummy_true(void) = 0;
};

Mock<Dummy> dummy_mock;

int dummy_true(void) {

    return dummy_mock.get().dummy_true();
}

void setUp(void) {}

void tearDown(void) {}

void test_robot_avanzando(void) {

    //When(Method(ArduinoFake(), ledcWrite)).AlwaysReturn();
    //When(Method(ArduinoFake(), ledcWrite)).AlwaysReturn();
    
    //When(Method(dummy_mock, dummy_true)).Return(1);

    robot_avanzar();

    //Verify(Method(ArduinoFake(), ledcWrite).Using(255)).Once();
    //Verify(Method(ArduinoFake(), ledcWrite).Using(255)).Once();

    //Verify(Method(dummy_mock, dummy_true));
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
    //RUN_TEST(test_robot_detenido);
    //RUN_TEST(test_robot_girando_derecha);
    //RUN_TEST(test_robot_girando_izquierda);

    UNITY_END();

    return 0;
}