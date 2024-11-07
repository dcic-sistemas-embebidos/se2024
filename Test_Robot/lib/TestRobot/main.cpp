#include <TestRobot.h>
#include <Arduino.h>

void setup() {
  testrobot_setup();  
  

}

void loop() {
    procesar_comando(PROBAR_LEDS);
    procesar_comando(PROBAR_MOTORES);
    procesar_comando(PROBAR_DISPLAY);
}
   

