# include <Arduino.h>
# include <pulsador_controller.h>
# include <LedsController.h>

# define PIN_PULSADOR 13


volatile bool flag = false;  // Variable volátil para indicar la interrupción

void IRAM_ATTR encender(){  
  flag = true;  // Cambia el estado del flag cuando ocurre la interrupción    
  
}

void pulsador_controller_setup(){  
  pinMode(PIN_PULSADOR, INPUT_PULLDOWN);  // Configura el pin como entrada
  attachInterrupt(PIN_PULSADOR, encender, RISING);
}

void pulsador_controller_loop(){
if (flag) {  // Si ocurre una interrupción
    Serial.println("¡Interrupción detecta!");
    flag = false;  // Restablece el flag
    prenderled(LED_AMARILLO);
    prenderled(LED_ROJO);
    prenderled(LED_VERDE);
    delay(2000);  
    apagarled(LED_AMARILLO);
    apagarled(LED_ROJO);
    apagarled(LED_VERDE);
    delay(2000);
  
  }
}

