# **Almacenamiento de la informaci�n permanente del robot.

Para almacenar la direcci�n mac del tel�fono y un c�digo de seguridad usamos la memoria flash nvs (NON-VOLATILE STORAGE) que poseen las placas ESP 32; utilizando la librer�a "Preference.h". 

## Para guardar y obtener la informaci�n usaremos los siguientes m�todos:

1) void GuardarDatos (String direccionMAC, String codigo)

Este m�todo almacenar� tanto la direcci�n MAC, como el c�digo de seguridad. 
Adem�s usar� la funci�n serial para informar que se ha guardado la informaci�n.   

2) String ObtenerMAC()

El m�todo obtendr� la mac guardada y la devolver�. En caso de que no exista devolver� vacio.

3) String ObtenerCodigo()

El m�todo obtendr� el c�digo de seguridad y lo devolver�. En caso que no exista devolver� vacio.


Un ejemplo del funcionamiento se puede ver en el codigo Interfaz_Usuario.cpp en el cu�l cuando se apreta un bot�n se resetean los valores almacenados, prende el led rojo durante 5 segundos y mostrar� un mensaje "Pulsado.."en el display. 
En el caso que se hayan guardado los datos cuando no se esta apretando el bot�n, se prender� el led verde durante 5 segundos. 

En el serial enviar� los siguientes mensajes:

- "Pulsado!", cuando se presiona el bot�n.
- "No existe una mac guardada", cuando no tiene datos guardados en memoria.
- "MAC: 00:01:32:63:44:95", cuando tiene una mac guardada.
- "Codigo: codigo de seguridad", cuando tiene un codigo guardado.
  

  