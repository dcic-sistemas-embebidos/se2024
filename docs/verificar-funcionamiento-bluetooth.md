## Verificación del funcionamiento del Bluetooth

Para comprobar el correcto funcionamiento del **Bluetooth** de nuestro módulo ESP32, se requiere un celular Android junto con un breve código de prueba escrito en VSCode. También se deberán montar los componentes en la protoboard (ESP32, resistencia, led y cables) para hacer las pruebas.
A continuación, se detallan los pasos a seguir:

1. Montar los componentes como se indica en la imagen inferior, y luego conectar el ESP32 a la computadora.
2. Abrir el proyecto en VSCode (disponible en el repositorio) que se encargará de interactuar con el Bluetooth del chip.
3. Construir y subir la imagen haciendo uso de la extensión PlatformIO.
4. En el celular, descargar la [aplicación](https://play.google.com/store/apps/details?id=de.kai_morich.serial_bluetooth_terminal&hl=en) que permitirá conectarnos y comunicarnos con nuestro chip.
5. Debemos encender el Bluetooth y vincularnos con el chip normalmente desde nuestro celular (como si fuera cualquier otro dispositivo).
6. Luego, desde la aplicación debemos ir a MENÚ->DEVICES->ESP32_EMBEBIDOS para establecer la conexión, y deberíamos observar el mensaje "Conectado".
7. Por último, debemos enviar los valores 1 y 0 desde la aplicación, observando como se enciende y apaga el led.

![Conexión de componentes](/test_and_tools/verificar_funcionamiento_bluetooth/Conexión%20de%20componentes.png)
