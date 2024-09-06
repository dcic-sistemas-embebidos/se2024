# **Interfaz de usuario**

Para la interacción entre el usuario y el robot usaremos los siguientes componentes:

- Un teléfono que nos permita conectar el bluetooth de placa esp32 con el bluetooth del teléfono.
- Un display LCD1602 Key Shield 1.0 que nos permita ver los mensajes necesarios.
- Tres leds que nos indicarán diferentes situaciones del robot.
- Una llave que desconecte los motores cuando no se estén usando.
- Un chasis para contener los componentes del robot.

## Uso del teléfono:

El teléfono se emparejará con la placa esp32 a través de una app compatible con Android 6.0 o superior. 
La app ofrecerá la posibilidad de que el robot circule hacia delante, atrás, a derecha , a izquierda y detenerlo.

## Uso del display:

El display ofrecerá los mensajes que indicará si la placa está conectada con el teléfono a través del bluetooth y si esta circulado en alguno de los sentidos o si está detenido.

## Uso de los leds:

Existirán tres colores de leds que indicarán si el robot está circulando en alguno de los sentidos o está detenido. 
El led de color verde indicará que el robot está conectado al bluetooth del teléfono esperando ordenes de avanzar hacia alguno de los sentidos.
El led de color amarillo indicará que se está moviendo hacia el sentido seleccionado.
El led de color rojo indicará que existe alguna falla con el robot.


## Uso de la llave:

La llave permitirá conectar y desconectar los motores cuando se estén utilizando o no.

## Uso del chasis:

El chasis albergará las diferentes partes del robot como los motores con sus ruedas, el display, la placa esp32 y la protoboard con las conexiones.  
 
