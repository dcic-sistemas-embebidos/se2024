#include <unity.h>

#include "rtd.h"

void setUp(void) {}
void tearDown(void) {}

void test_rtd_setup(void) {
    TEST_ASSERT_EQUAL_INT(1, rtd_setup());
}

int main(int argc, char **argv) {
    UNITY_BEGIN();

    RUN_TEST(test_rtd_setup);

    UNITY_END();

    return 0;
}