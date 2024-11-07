#include <Arduino.h>
#include <LedsController.h>
#include <move_controller.h>
#include <lcd_interface.h>
#include <TestRobot.h>

void testrobot_setup(void){
   ledscontroller_setup();  
   move_controller_setup();
   setup_lcd();
}

void testrobot_loop(void){   
  
}

void probarleds(void){
   
   prenderled(LED_ROJO);
   delay(500);
   prenderled(LED_AMARILLO);
   delay(500);
   prenderled(LED_VERDE);
   delay(500);
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

void probardisplay(void){    
   int i= 0;
   while(i<5){
   char* linea0= "Hola !!!!!!!!!!!!!!!!!!";
   char* linea1= "Que tal !!!!!!!!!!!!!!!!!!!!!!!!!";
   loop_lcd(linea0, 9, 0);
   loop_lcd(linea1,0 , 1);
   delay(3000);
   clean_lcd();
   i++;
   }   
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
   case 3:
      probardisplay();
      break;   
      
   default:
      break;
   }
}