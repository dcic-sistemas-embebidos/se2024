#include <Preferences.h>
#include <MemoryOperations.h>

static Preferences *preferences;

int operacionsetpreferences(Preferences *preferences_param) {
  preferences = preferences_param;
  return 1;
}


void inicializar(){
  preferences->begin("robot", false);
}

void finalizar(){
  preferences->end();
}

void operacionguardardatos(String direccionMAC, String codigo){
  inicializar();
  preferences->putString("direcmac", direccionMAC);
  preferences->putString("codseg", codigo);
  finalizar();
}



String operacionobtenermac(){  
  inicializar();
  String MAC= preferences->getString("direcmac","");
  finalizar();
  return MAC;

}


String operacionobtenercodigo(){
  inicializar();
  String codigo= preferences->getString("codseg","");
  finalizar();
  return codigo;

}



