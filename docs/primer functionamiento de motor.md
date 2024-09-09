# Funcionamiento del motor

## Introduccion : 

En esta parte voy a hacer funcionar el motor de manera basica : girar en una dirreccion y en la otra.
Para hacer eso voy a realisar el circuito con el esp32, el driver L298N, la alimentacion y las cables.
Despues voy a codear una funcciun en el esp32 para hacer girar el motor.

## Componentes : 
- ESP32
- Driver L298N
- motor 6V
- a battery holder for 4 AA or AAA batteries (in order to have 6V) ( a recuperar )

## Seguridad

Para alimentar el driver L298N, debemos utilizar entre 5 y 46Volts (datasheet).
Para alimentar el esp32, podemos utilisar el PC o recuperar la alimentacion del driver.

## Circuito 



## Codigo 



## Bibliografia :

datasheet del driver L298N :
https://www.alldatasheet.com/datasheet-pdf/pdf/22440/STMICROELECTRONICS/L298N.html

datasheet del esp32 : 
https://www.alldatasheet.com/view.jsp?Searchword=Esp32%20datasheet&gad_source=1&gclid=CjwKCAjw59q2BhBOEiwAKc0ijZJ06gPJ2xsAqp229hj6fqG8Pkont1uiykNHEO-VKZg3pkf6obdOShoCm10QAvD_BwE

videos youtube de un proyecto similar 
https://www.youtube.com/watch?v=E2raPpB2aJ0

https://www.youtube.com/watch?v=qwFddd0PGoE

https://www.youtube.com/watch?v=_TEZ2-3H0GY


sitio que explica el functionamiento del driver y los conectores elctronicos
https://www.techrm.com/how-to-control-a-dc-motor-via-esp32-and-bluetooth-with-l298n-on-platformio/#The_H-bridge
