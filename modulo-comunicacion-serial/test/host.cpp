#include <ArduinoFake.h>
#include <unity.h>
#include "host.h"

using namespace fakeit;

void tearDown(void) {

}

void setUp(void) {
    When(Method(ArduinoFake(), pinMode)).AlwaysReturn();
    When(Method(ArduinoFake(), digitalWrite)).AlwaysReturn();
}

void test_process_commands_should_turn_on_led() {
   
    When(Method(ArduinoFake(), digitalWrite));

    process_commands("encender");

    Verify(Method(ArduinoFake(), digitalWrite).Using(LED_PIN, HIGH)).Once();
}

void test_process_commands_should_turn_off_led() {

    When(Method(ArduinoFake(), digitalWrite));

    process_commands("apagar");

    Verify(Method(ArduinoFake(), digitalWrite).Using(LED_PIN, LOW)).Once();
}



int main(int argc, char **argv) {
    UNITY_BEGIN();

    RUN_TEST(test_process_commands_should_turn_on_led);
    RUN_TEST(test_process_commands_should_turn_off_led);

    UNITY_END();
    return 0;
}
