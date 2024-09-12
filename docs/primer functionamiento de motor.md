# Funcionamiento del motor

## Introduccion : 

En esta parte voy a hacer funcionar el motor de manera basica : girar en una dirreccion y en la otra.
Para hacer eso voy a realisar el circuito con el esp32, el driver L298N, la alimentacion y las cables.
Despues voy a codear una funcciun en el esp32 para hacer girar el motor.

## Componentes : 
- ESP32
- Driver L298N
- motor 6V
- a battery holder for 4 AA or AAA batteries (para obtener 6V ( la alimentacion de un motor))
- cables de conexión

## Seguridad

Para alimentar el driver L298N, debemos utilizar entre 5 y 46Volts (datasheet).
Para alimentar el esp32, podemos utilisar el PC.

## Circuito 
hzy una foto de las connexionnes pero


## Codigo 
podes encontrar el codigo el los carpetas "LED" o "Funcionamineto del motor"
Pero el codigo functionna como asi : 
Setup, los pin del esp32
setup el canal PWM

empezamos a mandar las valores de pmw a la led o al driver 
cambiamos al valor 
eso siempre



## Bibliografia :

datasheet del driver L298N :
https://www.alldatasheet.com/datasheet-pdf/pdf/22440/STMICROELECTRONICS/L298N.html

datasheet del esp32 : 
https://www.alldatasheet.com/view.jsp?Searchword=Esp32%20datasheet&gad_source=1&gclid=CjwKCAjw59q2BhBOEiwAKc0ijZJ06gPJ2xsAqp229hj6fqG8Pkont1uiykNHEO-VKZg3pkf6obdOShoCm10QAvD_BwE

Pinout del esp32 : https://lastminuteengineers.com/esp32-pinout-reference/
Pinout del driver L298N : https://components101.com/modules/l293n-motor-driver-module

videos youtube de un proyecto similar 
https://www.youtube.com/watch?v=E2raPpB2aJ0

https://www.youtube.com/watch?v=qwFddd0PGoE

https://www.youtube.com/watch?v=_TEZ2-3H0GY


sitio que use para testear el pin gpio del esp y modifiacar el pmw de la led 
https://randomnerdtutorials.com/esp32-pwm-arduino-ide/

sitio que explica el functionamiento del driver y los conectores elctronicos : https://www.techrm.com/how-to-control-a-dc-motor-via-esp32-and-bluetooth-with-l298n-on-platformio/#The_H-bridge
