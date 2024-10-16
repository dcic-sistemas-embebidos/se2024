#include <Arduino.h>
#include <unity.h>
#include "serial_interface.h"

#define LED_PIN 2

void setUp(void) {
    
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW); 
}

void tearDown(void) {
    
}

// Test para la función serial_interface_begin()
void test_serial_interface_begin(void) {
    serial_interface_begin();
    // Verificar si el LED está apagado después de la inicialización
    TEST_ASSERT_EQUAL(LOW, digitalRead(LED_PIN));
}

// Test para el comando "encender"
void test_process_commands_encender(void) {
    process_commands("encender");
    // Verificar si el LED está encendido
    TEST_ASSERT_EQUAL(HIGH, digitalRead(LED_PIN));
}

// Test para el comando "apagar"
void test_process_commands_apagar(void) {
    process_commands("apagar");
    // Verificar si el LED está apagado
    TEST_ASSERT_EQUAL(LOW, digitalRead(LED_PIN));
}


// Función principal para ejecutar los tests
void setup() {
    
    UNITY_BEGIN();

  
    RUN_TEST(test_serial_interface_begin);
    RUN_TEST(test_process_commands_encender);
    RUN_TEST(test_process_commands_apagar);

    
    UNITY_END();
}

void loop() {

}
