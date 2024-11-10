# include <Arduino.h>
# include <pulsador_controller.h>
# include <LedsController.h>

# define PIN_PULSADOR 13

volatile unsigned  long lastInterruptTime = 0;  
int interruptDuration = 1000;
int tiempoEncendidoApagado;

volatile bool flag = false;  // Variable volátil para indicar la interrupción

void IRAM_ATTR encender(){  
  if(millis() - lastInterruptTime > interruptDuration) {
     flag = true;  // Cambia el estado del flag cuando ocurre la interrupción    
     lastInterruptTime= millis();
  }
}

void pulsador_controller_setup(){  
  pinMode(PIN_PULSADOR, INPUT_PULLDOWN);  // Configura el pin como entrada
  attachInterrupt(PIN_PULSADOR, encender, RISING);
}

void pulsador_controller_loop(){
if (flag) {  // Si ocurre una interrupción
    Serial.println("¡Interrupción detectada!");
    flag = false;  // Restablece el flag
    prenderled(LED_AMARILLO);
    prenderled(LED_ROJO);
    prenderled(LED_VERDE);
    tiempoEncendidoApagado = millis();    
    while (millis() - tiempoEncendidoApagado < interruptDuration) {
     
    }
    apagarled(LED_AMARILLO);
    apagarled(LED_ROJO);
    apagarled(LED_VERDE);
    tiempoEncendidoApagado = millis();    
    while (millis() - tiempoEncendidoApagado < interruptDuration) {
     
    }
    Serial.print("millis: ");
    Serial.println(millis());
  
  }
}

