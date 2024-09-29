#include <ArduinoFake.h>
#include <unity.h>

using namespace fakeit;

#include "dummy.h"

void setUp(void) {
    ArduinoFakeReset();
}

void tearDown(void) {
}

void dummy(void) {
    When(Method(ArduinoFake(), digitalWrite)).AlwaysReturn();

    TEST_ASSERT_TRUE(dummy_true());
}

int main(int argc, char **argv) {
    UNITY_BEGIN();

    RUN_TEST(dummy);

    UNITY_END();

    return 0;
}