//#include <Arduino.h>
#include <ArduinoFake.h>
#include <unity.h>

using namespace fakeit;

// Define el pin del LED (por ejemplo, el pin 2 para la ESP32)
#define LED_PIN 2



void test_example(void)
{
    When(Method(ArduinoFake(), digitalWrite)).AlwaysReturn();
    When(Method(ArduinoFake(), delay)).AlwaysReturn();

    loop();

    Verify(Method(ArduinoFake(), digitalWrite).Using(LED_PIN, HIGH)).Once();
    Verify(Method(ArduinoFake(), digitalWrite).Using(LED_PIN, LOW)).Once();
    Verify(Method(ArduinoFake(), delay).Using(100)).Exactly(2_Times);
}



int main(int argc, char **argv)
{
    UNITY_BEGIN();

    RUN_TEST(test_example);
 
    UNITY_END();

    return 0;
}