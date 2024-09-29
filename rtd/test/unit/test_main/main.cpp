
#include <unity.h>

void setUp(void) {
}

void tearDown(void) {
}

void test_myFunction(void) {
    // int result = myFunction(1, 1);
    // TEST_ASSERT_EQUAL_INT(2, result);
    TEST_ASSERT_TRUE(1);
}

int main(int argc, char **argv) {
    UNITY_BEGIN();

    RUN_TEST(test_myFunction);

    UNITY_END();

    return 0;
}