#include <Arduino.h>
#include <Memoria.h>

String codigoobtenido= "";
String macobtenida= "";
String respcod="";
String respmac="";

int i= 0;

void setup() {
 Serial.begin(115200);
 
}

void loop() {
  if(i < 5){
    macobtenida= macobtenida + i + i;
    codigoobtenido= codigoobtenido + i;
    guardardatos(macobtenida,codigoobtenido);
    respmac= obtenermac();
    respcod= obtenercodigo();
    Serial.print(" mac: "+ respmac);
    Serial.println(",    cod: "+ respcod);
    
    ++i;
  }
  
}

