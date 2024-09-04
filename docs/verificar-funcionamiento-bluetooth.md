## Verificación del funcionamiento del Bluetooth

Para comprobar el correcto funcionamiento del **Bluetooth** de nuestro módulo ESP32, se hizo uso de un celular Android junto con un breve código de prueba escrito en VSCode, y luego cargado en el chip.
A continuación, se detallan los pasos seguidos:

1. Se escribió un breve [código](https://pastebin.com/raw/1u1fFTeM) de prueba en VSCode que hace uso del led integrado en el chip.
2. Se construyó la imagen y se subió al ESP32 haciendo uso de la extensión PlatformIO.
3. En el celular, se descargó una [aplicación](https://play.google.com/store/apps/details?id=de.kai_morich.serial_bluetooth_terminal&hl=en) que permite conectarse y comunicarse por Bluetooth con nuestro chip.
4. Por último, se hicieron las pruebas de enviar los valores 0 y 1 desde la aplicación hacia el chip, observando como se enciende y apaga el led.
