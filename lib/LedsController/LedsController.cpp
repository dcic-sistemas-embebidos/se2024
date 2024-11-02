# include <Arduino.h>
# include <LedsController.h>

# define ledRojo 4
# define ledVerde 2
# define ledAmarillo 15

void ledscontroller_setup(){
 pinMode(ledAmarillo, OUTPUT);
 pinMode(ledVerde, OUTPUT);
 pinMode(ledRojo, OUTPUT);
   
}
void ledscontroller_loop(){}
void prenderled(int colorled){
    if(colorled == LED_ROJO)    
      digitalWrite(ledRojo, HIGH);
    else if(colorled == LED_VERDE)
        digitalWrite(ledVerde, HIGH);
        else if(colorled == LED_AMARILLO)
            digitalWrite(ledAmarillo, HIGH);  
}
void apagarled(int colorled){
    if(colorled == LED_ROJO)    
      digitalWrite(ledRojo, LOW);
    else if(colorled == LED_VERDE)
        digitalWrite(ledVerde, LOW);
        else if(colorled == LED_AMARILLO)
            digitalWrite(ledAmarillo, LOW);  
}
