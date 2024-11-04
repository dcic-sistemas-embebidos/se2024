# include <Arduino.h>
# include <LedsController.h>

# define PIN_LED_ROJO 4
# define PIN_LED_VERDE 2
# define PIN_LED_AMARILLO 15

void ledscontroller_setup(){
 pinMode(PIN_LED_AMARILLO, OUTPUT);
 pinMode(PIN_LED_VERDE, OUTPUT);
 pinMode(PIN_LED_ROJO, OUTPUT);
   
}

void ledscontroller_loop(){}

void prenderled(int colorled){
   switch(colorled) {
   case LED_ROJO:
       digitalWrite(PIN_LED_ROJO, HIGH);
   break;
   case LED_VERDE:
       digitalWrite(PIN_LED_VERDE, HIGH);
   break;  
   case LED_AMARILLO:
       digitalWrite(PIN_LED_AMARILLO, HIGH);
   break;
   } 
}

void apagarled(int colorled){
   switch(colorled) {
   case LED_ROJO:
       digitalWrite(PIN_LED_ROJO, LOW);
   break;
   case LED_VERDE:
       digitalWrite(PIN_LED_VERDE, LOW);
   break;  
   case LED_AMARILLO:
       digitalWrite(PIN_LED_AMARILLO, LOW);
   break;
   } 
}
