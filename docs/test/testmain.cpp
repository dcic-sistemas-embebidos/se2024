#include <Arduino.h>
#include <unity.h>
#include "order.h"

//otras funcciones
void message_adelante();
void blink(int times, int delayTime);

// Para verificar la llamada de las otras funcciones
bool messageAdelanteCalled = false;
bool messageAtrasCalled = false;
bool messageDerechaCalled = false;
bool messageIzquierdaCalled = false;
bool messageDetenerCalled = false;
bool messageErrorCalled = false;

int blinkTimes = 0;
int lastdelay=0;

void message_adelante() { //solo para verificar mi funcion order, la llamada de la buena funcion
    messageAdelanteCalled = true; 
}

void message_atras() {
    messageAtrasCalled = true; 
}

void message_derecha() {
    messageDerechaCalled = true; 
}

void message_izquierda() {
    messageIzquierdaCalled = true; 
}

void message_detener() {
    messageDetenerCalled = true; 
}

void message_error() {
    messageErrorCalled = true; 
}


void blink(int times, int delayTime) { //solo para verificar mi funcion order
    blinkTimes = times; 
    lastdelay=delayTime;
}


void test_command_forward() {
    messageAdelanteCalled = false;
    blinkTimes = 0; 
    lastdelay=0;
    order('F');
    TEST_ASSERT_TRUE_MESSAGE(messageAdelanteCalled, "message_adelante() n'a pas été appelé pour la commande 'F'");
    TEST_ASSERT_EQUAL(5, blinkTimes);
    TEST_ASSERT_EQUAL(100, lastdelay);
}

void test_command_backward() {
    messageAtrasCalled = false;
    blinkTimes = 0; 
    lastdelay=0;
    order('B');
    TEST_ASSERT_TRUE_MESSAGE(messageAtrasCalled, "message_atras() n'a pas ete appele pour la commande 'B'");
    TEST_ASSERT_EQUAL(5, blinkTimes);
    TEST_ASSERT_EQUAL(300, lastdelay);
}

void test_command_right() {
    messageDerechaCalled = false;
    blinkTimes = 0; 
    lastdelay=0;
    order('R');
    TEST_ASSERT_TRUE_MESSAGE(messageDerechaCalled, "message_derecha() n'a pas ete appele pour la commande 'R'");
    TEST_ASSERT_EQUAL(3, blinkTimes); 
    TEST_ASSERT_EQUAL(100, lastdelay);
}

void test_command_error() {
    messageErrorCalled = false;
    blinkTimes = 0; 
    lastdelay = 0; 
    order('X');
    TEST_ASSERT_TRUE_MESSAGE(messageErrorCalled, "message_error() n'a pas été appelé pour une commande non reconnue");
    TEST_ASSERT_EQUAL(10, blinkTimes); 
    TEST_ASSERT_EQUAL(50, lastdelay); 
}

void test_command_left() {
    messageIzquierdaCalled = false;
    blinkTimes = 0;
    lastdelay = 0;

    order('L');

    TEST_ASSERT_TRUE_MESSAGE(messageIzquierdaCalled, "message_izquierda() n'a pas été appelé pour la commande 'L'");
    TEST_ASSERT_EQUAL(3, blinkTimes);
    TEST_ASSERT_EQUAL(300, lastdelay);
}

void test_command_stop() {
    messageDetenerCalled = false;
    blinkTimes = 0;
    lastdelay = 0;

    order('S');

    TEST_ASSERT_TRUE_MESSAGE(messageDetenerCalled, "message_detener() n'a pas été appelé pour la commande 'S'");
    TEST_ASSERT_EQUAL(3, blinkTimes);
    TEST_ASSERT_EQUAL(300, lastdelay);
}


void setup() {
    UNITY_BEGIN(); 
    
    
    RUN_TEST(test_command_forward); 
    RUN_TEST(test_command_backward);
    RUN_TEST(test_command_right);
    RUN_TEST(test_command_error);
    RUN_TEST(test_command_left);
    RUN_TEST(test_command_stop);



    UNITY_END(); 
}

void loop() {
    // Nada
}
