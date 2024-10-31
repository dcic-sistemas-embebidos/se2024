#include <Arduino.h>
#include <LedsController.h>
#include <move_controller.h>


void testrobot_setup(void){
   Serial.begin(115200);
   Serial.println("setup robot "); 
   ledscontroller_setup();  
   move_controller_setup();
   
}

void testrobot_loop(void){   
}

void probarleds(void){
   Serial.println("Comenzo "); 
   prenderled("rojo");
   delay(2000);
   prenderled("amarillo");
   delay(2000);
   prenderled("verde");
   delay(2000);
   apagarled("amarillo");
   delay(2000);
   apagarled("rojo");
   delay(2000);
   apagarled("verde");
}

void probarmotores(void){
   robot_avanzar();
   delay(1000);
   robot_detenerse();
   delay(1000);
   robot_girar_izquierda();
   delay(1000);
   robot_girar_derecha(); 
   delay(1000);
}
