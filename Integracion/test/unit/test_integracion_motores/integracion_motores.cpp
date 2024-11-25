#include <Arduinofake.h>
#include <unity.h>
using namespace fakeit;
#include "motores_interface.h"

void setUp(void) {
  // set stuff up here
}

void tearDown(void) {
  // clean stuff up here
}

void test_setUp_motores(void) {
  When(Method(ArduinoFake(), pinMode)).AlwaysReturn();

  motores_setup();

  // Configuración motor A
  Verify(Method(ArduinoFake(), pinMode).Using(17, OUTPUT)).Once();
  Verify(Method(ArduinoFake(), pinMode).Using(18, OUTPUT)).Once();
  Verify(Method(ArduinoFake(), pinMode).Using(19, OUTPUT)).Once();

  // Configuración motor B
  Verify(Method(ArduinoFake(), pinMode).Using(21, OUTPUT)).Once();
  Verify(Method(ArduinoFake(), pinMode).Using(22, OUTPUT)).Once();
  Verify(Method(ArduinoFake(), pinMode).Using(23, OUTPUT)).Once();
}

int main(int argc, char **argv) {
  UNITY_BEGIN();
  RUN_TEST(test_setUp_motores);
  UNITY_END();

  return 0;
}

