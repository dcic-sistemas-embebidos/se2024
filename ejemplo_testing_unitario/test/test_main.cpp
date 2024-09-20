#include <unity.h>

bool led_estado;

void setUp(void) {
    // Se ejectua antes de cada prueba
    int led = 23;
    int tiempo = 200;
    led_estado = false;
}

void tearDown(void) {
    // Limpieza despues de cada prueba
}

void prender_led() {
    led_estado = true;
}

void apagar_led() {
    led_estado = false;
}

bool get_estado_led() {
    return led_estado;
}

void test_prender_led(void) {
    prender_led();
    TEST_ASSERT_TRUE(get_estado_led());
}

void test_apagar_led(void) {
    prender_led();
    apagar_led();
    TEST_ASSERT_FALSE(get_estado_led());
}

// Función principal que ejecuta las pruebas
int main(int argc, char **argv) {
    UNITY_BEGIN();        // Inicializa el framework Unity

    RUN_TEST(test_prender_led);  // Ejecuta test_prender_led
    RUN_TEST(test_apagar_led);  // Ejecuta test_prender_led

    UNITY_END();          // Finaliza el framework Unity y muestra resultados
    return 0;
}