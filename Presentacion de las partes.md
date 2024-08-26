## Introducción : 
En este documento primero presenté brevemente cada parte que vamos a utilizar y luego desarrollé el interés y el principio de 
funcionamiento de dos partes principales: el motor con caja reductora y el driver de control del motor.


## I - Presentación de los diferentes componentes y sus características

| Elemento | Funcion | Caracteristicas | Ventajas | Desventajas |
| --- | --- | --- | --- | --- |
| Chassis | Soporte básico para componentes de robots | Estructura rígida, materiales variados (metal, plástico), diseño modular o personalizado | Solidez, protección de componentes, estabilidad | Peso, complejidad del diseño, volumen |
| Ruedas | Asegurar el movimiento del robot en contacto con el suelo | Neumáticos (goma), diámetro y ancho que influyen en la tracción y la estabilidad | Tracción, estabilidad, facilidad de instalación | Peso, resistencia a la rodadura |
| Motores | Impulsa las ruedas para mover el robot | Voltaje, velocidad de rotación, torque, consumo de energía. | Control directo, simplicidad, varias opciones de control | Requiere alimentación, refrigeración y mantenimiento adecuados | 
| Driver | Interfaz entre el microcontrolador y los motores, permitiendo controlar su velocidad y dirección | Corriente, voltaje | Protección del microcontrolador, control eficiente del motor | Disipación de calor, complejidad adicional, límite actual |
| Microcontrolador | Recuperar la entrada y gestionar la velocidad, dirección y sincronización de los motores | Microcontrolador, vamos a elegirlo | Precisión de movimiento, flexibilidad, automatización posible.| Complejidad de programación |
| Fuente de alimentación | Proporciona energía a motores y sistemas de control | Batería (LiPo, NiMH), convertidor de voltaje, reguladores | Autonomía variable, potencia suficiente torque a los motores elegidos | Peso de la batería, gestión de la carga, riesgos relacionados con la energía |


## II - Motores con caja reductora ( 100 RPM → 1000 RPM )

https://tienda.starware.com.ar/producto/motor-reductor-micro-pololu-6v-100-rpm-dc/
https://www.electronicabyp.com.ar/producto/motoreductor-3-a-6v (tienda en Bahía Blanca)

Un motor reductor es un sistema en el que un motor, a menudo eléctrico, está acoplado a un reductor de velocidad (o caja reductora). La función principal de este reductor es reducir la velocidad de rotación del motor mientras aumenta el torque transmitido al eje de salida.
El motor genera rotación a alta velocidad pero con un torque relativamente bajo.
Engranaje reductor: este engranaje contiene un conjunto de engranajes que reducen la velocidad de rotación aumentando el torque. Los engranajes están dispuestos de modo que el engranaje (más pequeño) del motor impulse uno o más engranajes de mayor diámetro.
A la salida del reductor, la velocidad de rotación se reduce significativamente en comparación con la del motor, pero el torque aumenta proporcionalmente.

Ventajas de la caja reductora : 
- Aumento de torque
- Control preciso
- Ahorro de energía
- Sostenibilidad
Desventajas : 
- Mantenimiento
- Peso y volumen
- Pérdida de eficiencia

Un motor con engranaje reductor es ideal para aplicaciones que requieren un torque elevado a baja velocidad. Para lograr un movimiento preciso y controlado, los motores de los robots suelen estar equipados con cajas de cambios. Si bien ofrece importantes ventajas en términos de control y rendimiento, también presenta desventajas relacionadas con la complejidad, el peso y las pérdidas de eficiencia.


## III - Driver de control

https://tienda.starware.com.ar/producto/driver-para-motor-stepper-y-puente-h-arduino-compatible-l298n-dual-h/

El uso de un controlador de motor en un proyecto de robot es crucial por varias razones. Un controlador sirve como interfaz entre el microcontrolador y los motores del robot, permitiendo que el microcontrolador controle la velocidad y dirección de los motores sin ser dañado por las altas corrientes requeridas para operar los motores.

Funcionamiento : el controlador recibe señales de control del microcontrolador, como señales PWM (Pulse Width Modulation) para regular la velocidad y señales de dirección para controlar la dirección de rotación del motor. Después, el Driver amplifica esta señal para proporcionar la corriente adecuada al motor, respetando las órdenes del microcontrolador porque el microcontrolador sólo puede proporcionar una corriente baja, insuficiente para alimentar directamente los motores.

Ventajas del driver :
- Control preciso
- Protección
Desventajas : 
- Calefacción
- Complejidad

En resumen, el Driver del motor es un componente esencial para cualquier proyecto de robótica donde los motores deben ser controlados por un microcontrolador. Amplifica las señales de control, permite el control de velocidad y dirección, al mismo tiempo que protege los componentes electrónicos de sobrecargas.


## IV - Conclusion

Puntos clave a considerar para nuestro proyecto :

- Chasis: Elegir un material que equilibre resistencia y peso para garantizar la estabilidad de su robot.

- Ruedas: Adaptar el diámetro y ancho de las ruedas según la superficie sobre la que se desplazará el robot.

- Motores: Seleccionar motores teniendo en cuenta el peso total del robot y la velocidad deseada. Si nuestro robot necesita mover cargas o navegar con precisión, se recomienda un motor con caja reductora.

- Microcontrolador: Planificar la integración de componentes electrónicos según nuestros objetivos de control.

- Driver : Transformar la señal del microcontrolador en una tensión adaptada.

- Energía: Asegurarse que haya suficiente energía para operar sus motores sin sobrecalentamiento o fallas, sin añadir demasiado peso.


## Bibliografía : 

sitio que explica el fonctionamiento de los reductores : 
https://docs.revrobotics.com/ion-build-system/motion/gears/advanced-gears

sitio que presenta  algunos ventajas / desventajas de los motores reductores : 
https://medium.com/@martajunco2022/ventajas-y-desventajas-de-los-motores-reductores-1de0287cc527#:~:text=Una%20de%20las%20principales%20ventajas,que%20requieren%20una%20alta%20potencia.


sitio que presenta un ejemplo de circuito y cómo utilizar un driver : 
https://naylampmechatronics.com/blog/11_tutorial-de-uso-del-modulo-l298n.html

video youtube que muestra la utilización del driver en arduino : 
https://youtube.com/watch?v=0bxqxp9EkVI


