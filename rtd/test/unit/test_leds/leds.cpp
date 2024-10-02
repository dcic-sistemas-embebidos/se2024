#include <ArduinoFake.h>
#include <unity.h>

using namespace fakeit;

#include "leds.h"

struct Dummy {
    virtual int dummy_true(void) = 0;
};

Mock<Dummy> dummy_mock;

int dummy_true(void) {
    return dummy_mock.get().dummy_true();
}

void setUp(void) {}

void tearDown(void) {}

void test_leds_setup(void) {
    When(Method(ArduinoFake(), pinMode)).AlwaysReturn();
    When(Method(dummy_mock, dummy_true)).Return(1);

    leds_setup();

    Verify(Method(ArduinoFake(), pinMode).Using(2, OUTPUT)).Once();
    Verify(Method(dummy_mock, dummy_true));
}

int main(int argc, char **argv) {
    UNITY_BEGIN();

    RUN_TEST(test_leds_setup);

    UNITY_END();

    return 0;
}