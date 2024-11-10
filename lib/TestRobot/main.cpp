#include <TestRobot.h>
#include <Arduino.h>






void setup() {
  Serial.begin(115200); 
  testrobot_setup();
  
}

void loop() {  
    procesar_comando(PROBAR_LEDS);
    procesar_comando(PROBAR_MOTORES); 
    procesar_comando(PROBAR_PULSADOR);  
   // procesar_comando(PROBAR_DISPLAY);
}
   

