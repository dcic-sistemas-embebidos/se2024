#include <Preferences.h>

Preferences *preferences;

void memory_setup(){
 preferences= new Preferences();
}
 
void memory_loop(){}

void inicializar(){
  preferences->begin("robot", false);
}

void finalizar(){
  preferences->end();
}

void guardardatos(String direccionMAC, String codigo){
  inicializar();
  preferences->putString("direcmac", direccionMAC);
  preferences->putString("codseg", codigo);
  finalizar();
}

String obtenermac(){
  inicializar();
  String MAC= preferences->getString("direcmac","");
  finalizar();
  return MAC;
}

String obtenercodigo(){
  inicializar();
  String codigo= preferences->getString("codseg","");
  finalizar();
  return codigo; 
}


