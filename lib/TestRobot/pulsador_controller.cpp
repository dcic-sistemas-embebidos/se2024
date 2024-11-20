# include <Arduino.h>
# include <pulsador_controller.h>

# define PIN_PULSADOR 13

static volatile byte state = 0;

void IRAM_ATTR pulsado(){    
  if(state == 0)
    state= 1;
  else
    state= 0;       
}

void pulsador_controller_setup(){  
  pinMode(PIN_PULSADOR, INPUT_PULLDOWN);  
  attachInterrupt(digitalPinToInterrupt(PIN_PULSADOR), pulsado, RISING);
}

void pulsador_controller_loop(){
}

bool estadopulsador(){
  return state;
}
