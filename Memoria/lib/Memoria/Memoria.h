#ifndef _Memoria_H
#define _Memoria_H
#include <Arduino.h>
  class Memoria
  {  
    public:
      Memoria(); // Constructor de la clase
      ~Memoria();
      void GuardarDatos(String direccionMAC, String codigo);
      String ObtenerMAC();
      String ObtenerCodigo();
  };
#endif