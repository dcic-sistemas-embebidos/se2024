#include <Arduino.h>
#include <LedsController.h>
#include <move_controller.h>
#include <TestRobot.h>

void testrobot_setup(void){
   ledscontroller_setup();  
   move_controller_setup();
   
}

void testrobot_loop(void){   
   
}

void probarleds(void){
   
   prenderled(LED_ROJO);
   delay(1000);
   prenderled(LED_AMARILLO);
   delay(1000);
   prenderled(LED_VERDE);
   delay(1000);
   apagarled(LED_AMARILLO);
   delay(500);
   apagarled(LED_ROJO);
   delay(500);
   apagarled(LED_VERDE);
   delay(500);
}

void probarmotores(void){
   robot_avanzar();
   delay(1000);
   robot_detenerse();  
   delay(1000); 
   robot_girar_izquierda();
   delay(1000);
   robot_detenerse();
   delay(1000);
   robot_girar_derecha(); 
   delay(1000);
   robot_detenerse();
   delay(1000);
   robot_retroceder();
   delay(1000);
   robot_detenerse();
   delay(1000);
}

void procesar_comando(int comando){
   switch (comando)
   {
   case 1:
      probarleds();
      break;
   case 2:
      probarmotores();
      break;
   default:
      break;
   }
}