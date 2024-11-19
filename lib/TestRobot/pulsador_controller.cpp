# include <Arduino.h>
# include <pulsador_controller.h>

# define PIN_PULSADOR 13

static volatile bool estadoanterior = false;  
static volatile bool estadoactual = false;

void IRAM_ATTR pulsado(){    
  estadoactual = true;   
}

void pulsador_controller_setup(){  
  pinMode(PIN_PULSADOR, INPUT_PULLDOWN);  
  attachInterrupt(PIN_PULSADOR, pulsado, RISING);
}

void pulsador_controller_loop(){
  if (estadoactual == true){  
    estadoanterior= true; 
    estadoactual= false;
  }
}

bool estadopulsador(){
  bool valorestadoanterior= estadoanterior; // salva el estado previo si se ha presionado 
  estadoanterior= false;
  return valorestadoanterior;
}
