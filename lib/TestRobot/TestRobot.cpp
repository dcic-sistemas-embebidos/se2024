# include <Arduino.h>
# include <LedsController.h>
# include <move_controller.h>
# include <lcd_interface.h>
# include <TestRobot.h>
# include <pulsador_controller.h>

static byte estadoanterior= 0; 
static byte estadoactual= 0;

void testrobot_setup(void){
   ledscontroller_setup();  
   move_controller_setup();
   setup_lcd();
   pulsador_controller_setup();
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

void probardisplay(void){    
   int i= 0;
   char* linea0= "Hola !!!!!!!!!!!!!!!!!!";
   char* linea1= "segunda linea!!!!!!!!";
   while(i<2){
    loop_lcd(linea0, 9, 0);
    loop_lcd(linea1,0 , 1);
    delay(500);
    clean_lcd();
    i++;
   }   
}

void probarpulsador(void){    
    
   estadoactual= estadopulsador();
   if( estadoactual != estadoanterior){
     estadoanterior = estadoactual;
     prenderled(LED_ROJO);
     prenderled(LED_AMARILLO);
     prenderled(LED_VERDE);
     delay(2000);
     apagarled(LED_AMARILLO);
     apagarled(LED_ROJO);
     apagarled(LED_VERDE);
     delay(2000);      
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
   case 4:
      probarpulsador();   
      break;
   }
}