#include <unity.h>
#include <motores_interface.h>

void setup(void) {

}

void test_robot_avanzando() {

}

void test_robot_detenido() {

}

void test_robot_girando_derecha() {

}

void test_robot_girando_izquierda() {

}

int main(int argc, char **argv) {

    UNITY_BEGIN();        // Inicializa el framework Unity

    RUN_TEST(test_robot_avanzando);
    RUN_TEST(test_robot_detenido);
    RUN_TEST(test_robot_girando_derecha);
    RUN_TEST(test_robot_girando_izquierda);

    UNITY_END();          // Finaliza el framework Unity y muestra resultados

    return 0;
}