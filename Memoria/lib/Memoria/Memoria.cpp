#include <Preferences.h>
#include "Memoria.h"

static Preferences *preferences;

int set_preferences(Preferences *preferences_param) {
  preferences = preferences_param;
  return 1;
}


void inicializar(){
  preferences->begin("robot", false);
}

void finalizar(){
  preferences->end();
}

void GuardarDatos(String direccionMAC, String codigo){
  inicializar();
  preferences->putString("direcmac", direccionMAC);
  preferences->putString("codseg", codigo);
  finalizar();
}



String ObtenerMAC(){  
  inicializar();
  String MAC= preferences->getString("direcmac","");
  finalizar();
  return MAC;

}


String ObtenerCodigo(){
  inicializar();
  String codigo= preferences->getString("codseg","");
  finalizar();
  return codigo;

}

