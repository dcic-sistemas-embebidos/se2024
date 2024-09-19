# **Almacenamiento de la información permanente del robot.

Para almacenar la dirección mac del teléfono y un código de seguridad usamos la memoria flash nvs (NON-VOLATILE STORAGE) que poseen las placas ESP 32; utilizando la librería "Preference.h". 

## Para guardar y obtener la información usaremos los siguientes métodos:

1) void GuardarDatos (String direccionMAC, String codigo)

Este método almacenará tanto la dirección MAC, como el código de seguridad. 
Además usará la función serial para informar que se ha guardado la información.   

2) String ObtenerMAC()

El método obtendrá la mac guardada y la devolverá. En caso de que no exista devolverá vacio.

3) String ObtenerCodigo()

El método obtendrá el código de seguridad y lo devolverá. En caso que no exista devolverá vacio.


Un ejemplo del funcionamiento se puede ver en el codigo Interfaz_Usuario.cpp en el cuál cuando se apreta un botón se resetean los valores almacenados, prende el led rojo durante 5 segundos y mostrará un mensaje "Pulsado.."en el display. 
En el caso que se hayan guardado los datos cuando no se esta apretando el botón, se prenderá el led verde durante 5 segundos. 

En el serial enviará los siguientes mensajes:

- "Pulsado!", cuando se presiona el botón.
- "No existe una mac guardada", cuando no tiene datos guardados en memoria.
- "MAC: 00:01:32:63:44:95", cuando tiene una mac guardada.
- "Codigo: codigo de seguridad", cuando tiene un codigo guardado.
  

  