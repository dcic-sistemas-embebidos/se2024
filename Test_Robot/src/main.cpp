#include <TestRobot.h>
#include <Arduino.h>

void setup() {
  testrobot_setup();  
  

}

void loop() {
  procesar_comando(PROBAR_LEDS);
  delay(1000);
  procesar_comando(PROBAR_MOTORES);
  delay(1000);
}
   

