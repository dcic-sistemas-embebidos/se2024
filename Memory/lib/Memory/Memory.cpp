#include <Preferences.h>
#include <MemoryOperations.h>

Preferences preferences;

void memorysetup(){

   int a= operacionsetpreferences(&preferences);
}

void memoryloop(){}

void guardardatos(String direccionMAC, String codigo){
   operacionguardardatos(direccionMAC, codigo);
}

String obtenermac(){
    return operacionobtenermac();
}

String obtenercodigo(){
    return operacionobtenercodigo();
}


