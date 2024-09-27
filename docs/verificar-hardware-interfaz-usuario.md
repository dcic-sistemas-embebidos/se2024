# Verificación del Hardware Interfaz De Usuario

## Componentes De Interfaz De Usuario
### Entrada:
* Pulsador
* Llave
### Salida:
* Led
* Display


## Verificacion integridad componentes:
* Pulsador/Llave: con un multimetro comprobar la continuidad del circuito al presionar el pulsador o llave.
* Led/Llave: con un multimetro comprobar la continuidad del circuito al presionar el pulsador o llave.

## Verificacion funcionamiento componentes (sin requerir codigo):
* Led: Conectamos las salida de 3v de la ESP32 a una resistencia de X ohms, luego el otro extremo de la resistencia lo conectamos al anodo(pata larga) del led, y el catodo(pata corta) a GND de la ESP32.

* Pulsado/LLaver: Reconocer las patas que estan conectadas entre si, cuya conexion es "horizontal". Conectamos las salida de 3V de la ESP32 a una de las patas, y luego de la otra conexion horizontal a una de sus patas, conectamos un extremo de la resistencia. El otro extremos de la resistencia lo conectamos al anodo(pata larga) del led, y el catodo(pata corta) a GND de la ESP32.

* Display: 

## Verificacion funcionamiento componentes:
Se ejecuta el script de prueba llamado "test_hw_interfaz.cpp" desde el loop() en "main.cpp".

* Led: debe estar conectado en el pin 5.
* Pulsador/Llave: debe estar conectado en el pin 4.
* Display: 