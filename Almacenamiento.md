Para almacenar los datos en memoria utilizaremos la librería "Preference.h" que se usa para almacenar pares (clave, valor). 
Esta librería utiliza la API Expressif NVS que utiliza la memoria flash.   

## **Almacenamiento de la información permanente del robot.

El almacenamiento permanente en la ESP32 se realiza utilizando la memoria flash interna del dispositivo. 
Esta memoria flash es un tipo de memoria no volátil, lo que significa que los datos almacenados en ella no se pierden cuando se apaga o se reinicia el dispositivo. 
Aquí se almacenan tanto el firmware como los datos persistentes de las aplicaciones, como configuraciones y registros.

## Particiones en la Memoria Flash:

 La memoria flash se divide en diferentes particiones para diferentes propósitos. Un ejemplo de estas particiones incluyen:
- Partición de Firmware: Para el código de la aplicación (programa principal).
- Partición de Datos SPIFFS o LittleFS: Para el sistema de archivos en memoria flash, útil para almacenar archivos como configuraciones o recursos estáticos.
- Partición NVS (Non-Volatile Storage): Para el almacenamiento de datos en formato clave-valor, que es utilizado por la API Preferences.h.

La partición NVS utiliza una parte de la memoria flash para guardar datos en un formato estructurado y seguro como configuraciones, contadores, credenciales Wi-Fi, etc.

## Consideraciones sobre la Memoria Flash:

 Vida Útil: La memoria flash tiene un número limitado de ciclos de escritura/borrado (normalmente entre 10,000 y 100,000 ciclos por bloque), por lo que se debe tener en cuenta el desgaste al diseñar aplicaciones que escriben frecuentemente en la memoria.
 
 Protección contra Fallos: NVS y los sistemas de archivos implementan mecanismos de protección contra fallos para asegurar que los datos no se corrompan en caso de interrupciones inesperadas.

Mas información: https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-reference/storage/nvs_flash.html  

## Para guardar y obtener la información usaremos los siguientes métodos:

1. void GuardarDatos (String direccionMAC, String codigo)

Este método almacenará tanto la dirección MAC, como el código de seguridad. 
Además usará la función serial para informar que se ha guardado la información.   

2. String ObtenerMAC()

El método obtendrá la mac guardada y la devolverá. En caso de que no exista devolverá vacio.

3. String ObtenerCodigo()

El método obtendrá el código de seguridad y lo devolverá. En caso que no exista devolverá vacio.


Un ejemplo del funcionamiento se puede ver en el codigo Interfaz_Usuario.cpp en el cuál cuando se apreta un botón se resetean los valores almacenados, prende el led rojo durante 5 segundos y mostrará un mensaje "Pulsado.."en el display. 
En el caso que se hayan guardado los datos cuando no se esta apretando el botón, se prenderá el led verde durante 5 segundos. 

En el serial enviará los siguientes mensajes:

- "Pulsado!", cuando se presiona el botón.
- "No existe una mac guardada", cuando no tiene datos guardados en memoria.
- "MAC: 00:01:32:63:44:95", cuando tiene una mac guardada.
- "Codigo: codigo de seguridad", cuando tiene un codigo guardado.

  
Para compilar este codigo se puede utilizar el proyecto de la carpeta Almacenamiento.rar. Los pasos son los siguientes:

- Descomprimir el archivo .rar en un directorio.
- Abrir el Proyecto en PlatformIO:
- Abrir VS Code.
- Seleccionar File > Open Folder (o Abrir Carpeta) y selecciona la carpeta del proyecto descomprimido.


  
