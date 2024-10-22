
#include <Arduino.h>
#include <Memory.h>

String codigoobtenido= "";
String macobtenida= "";
String respcod="";
String respmac="";


int i= 0;
void setup() {
 memory_setup();
 Serial.begin(115200);
}

void loop() {
  if(i < 5){
    macobtenida= macobtenida + i + i +i;
    codigoobtenido= codigoobtenido + i + i;
    guardardatos(macobtenida,codigoobtenido);
    respmac= obtenermac();
    respcod= obtenercodigo();
    Serial.print(" mac: "+ respmac);
    Serial.println(",    cod: "+ respcod);
    
    ++i;
  }
  
}

