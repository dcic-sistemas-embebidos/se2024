#include <Memoria.h>
#include <Preferences.h>

Preferences preferences;

Memoria::Memoria(){

}
Memoria::~Memoria(){

}

void inicializar(){
  preferences.begin("robot", false);
}

void finalizar(){
  preferences.end();
}

void Memoria::GuardarDatos(String direccionMAC, String codigo){
  inicializar();
  preferences.putString("direcmac", direccionMAC);
  preferences.putString("codseg", codigo);
  finalizar();

}



String Memoria::ObtenerMAC(){  
  inicializar();
  String MAC= preferences.getString("direcmac","");
  finalizar();
  return MAC;

}


String Memoria::ObtenerCodigo(){
  inicializar();
  String codigo= preferences.getString("codseg","");
  finalizar();
  return codigo;

}

