# include <Arduino.h>

# define ledRojo 4
# define ledVerde 2
# define ledAmarillo 15

void ledscontroller_setup(){
 pinMode(ledAmarillo, OUTPUT);
 pinMode(ledVerde, OUTPUT);
 pinMode(ledRojo, OUTPUT);
   
}
void ledscontroller_loop(){}
void prenderled(String colorled){
    if(colorled == "rojo")    
      digitalWrite(ledRojo, HIGH);
    else
      if(colorled == "verde")
        digitalWrite(ledVerde, HIGH);
        else
          if(colorled == "amarillo")
            digitalWrite(ledAmarillo, HIGH);  
}
void apagarled(String colorled){
    if(colorled == "rojo")    
      digitalWrite(ledRojo, LOW);
    else
      if(colorled == "verde")
        digitalWrite(ledVerde, LOW);
        else
          if(colorled == "amarillo")
            digitalWrite(ledAmarillo, LOW);  
}
