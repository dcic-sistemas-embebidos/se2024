#include <ArduinoFake.h>
#include <unity.h>
#include "hostController.h"

using namespace fakeit;

void tearDown(void) {
     ArduinoFakeReset();
}

void setUp(void) {
    ArduinoFakeReset();
}

void test_serial_tx() {
    
    
    When(OverloadedMethod(ArduinoFake(Serial), write, size_t(const uint8_t*, size_t))).AlwaysReturn(3);

    uint8_t data[] = {0x41, 0x42, 0x43};  
    host_tx(data, sizeof(data)); 

    Verify(OverloadedMethod(ArduinoFake(Serial), write, size_t(const uint8_t*, size_t))).Once();
}

void test_rx_calls_readStringUntil() {
    
    When(Method(ArduinoFake(Serial), available)).Return(1);
    When(Method(ArduinoFake(Serial), readStringUntil)).Return(String("comando_prueba"));

    String result = host_rx();

    Verify(Method(ArduinoFake(Serial), readStringUntil).Using('\n')).Once();
    TEST_ASSERT_EQUAL_STRING("comando_prueba", result.c_str());
}


int main(int argc, char **argv) {
    UNITY_BEGIN();

    RUN_TEST(test_rx_calls_readStringUntil);
    RUN_TEST(test_serial_tx);

    UNITY_END();
    return 0;
}
