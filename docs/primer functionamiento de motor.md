# Funcionamiento del motor

## Introduccion : 

En esta parte voy a hacer funcionar el motor de manera basica : girar en una dirreccion y en la otra.
Para ello primero quise modificar la intensidad de la luz de un LED usando una señal PWM enviada por ESP para familiarizarme con este medio de comunicación y los pines PGIO del ESP32. Luego creé el circuito y el código para hacer girar el motor con las mismas funciones y pines que descubrí en mi primera parte.

## Componentes :

### LED :
- ESP32 alimentado por una computadora
- LED
- Resistencia
- Cables de conexión

### Motor :
- ESP32 alimentado por una computadora
- Driver L298N
- motor 6V
- Alimentacion de 6V con 4 pilas AA ( la alimentacion de un motor)
- Cables de conexión

## Seguridad

Para alimentar el driver L298N, debemos utilizar entre 5 y 46Volts (datasheet).
Para alimentar el esp32, podemos utilisar el PC.
Siempre debemos utilisar una resistencia con una LED.

## Circuitos

Podéis encontrar los dos circuitos en la carpeta "fotos", para más detalles: Para el LED, alimentamos el ESP32 con el PC, conectamos un GPIO al LED, el LED a la resistencia y la resistencia a tierra. Para el motor alimentamos el ESP32 con el PC, conectamos 3 GPIO al driver, conectamos el driver a tierra al motor y a la fuente de alimentación.

## Codigo 

Puede encontrar el código en las carpetas "LED" o "functionamiento del motor".
Pero el código funciona así:
Configuración de pines esp32 y canal PWM.
Inicializando pines y canal

En el bucle principal: Enviamos los valores desde el ESP32 gracias a la función (ledcWrite), modificamos el valor tras un breve retraso y mandamos el nuevo valor, esto hasta que hayas hecho todos los valores.
Precisión para el motor, elegimos el sentido de giro gracias a la función (digitalWrite) y a los GPIO conectados al driver.

## Puntos importante :

Probar la alimentacion.
Cuando creamos el proyecto debemos eligir el board : "esp32dev".
Modificar el platformio.ini para poner el mismo "monitor_speed" que en el "Serial.begin".
Asegurarse utilisar los buenos pins del ESP32 y del driver.

## Bibliografia :

datasheet del driver L298N :
https://www.alldatasheet.com/datasheet-pdf/pdf/22440/STMICROELECTRONICS/L298N.html

datasheet del esp32 : 
https://www.alldatasheet.com/view.jsp?Searchword=Esp32%20datasheet&gad_source=1&gclid=CjwKCAjw59q2BhBOEiwAKc0ijZJ06gPJ2xsAqp229hj6fqG8Pkont1uiykNHEO-VKZg3pkf6obdOShoCm10QAvD_BwE

Pinout del esp32 : 
https://lastminuteengineers.com/esp32-pinout-reference/

Pinout del driver L298N : 
https://components101.com/modules/l293n-motor-driver-module

videos youtube de un proyecto similar : 
https://www.youtube.com/watch?v=E2raPpB2aJ0


sitio que use para testear el pin gpio del esp y modifiacar el pmw de la led 
https://randomnerdtutorials.com/esp32-pwm-arduino-ide/

sitio que explica el functionamiento del driver y los conectores elctronicos : https://www.techrm.com/how-to-control-a-dc-motor-via-esp32-and-bluetooth-with-l298n-on-platformio/#The_H-bridge
