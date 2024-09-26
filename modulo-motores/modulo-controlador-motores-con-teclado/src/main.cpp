#include <Arduino.h>
#include <motores_interface.h>

String accion = "";

void setup() {

  	Serial.begin(115200);

	configurar_salidas();
}

void loop() {

	recibir_mensaje();

	if (accion.length() > 0) {

		if (accion == "w") {
			avanzar();
		}

		if (accion == "s") {
			detener();
		}

		if (accion == "d") {
			girar_derecha();
		}

		if (accion == "a") {
			girar_izquierda();
		}

		accion = "";
	}

	delay(10);
}

// Lectura de la instrucción por el puerto serial
void recibir_mensaje() {

  	while (Serial.available()) {
		char inChar = (char)Serial.read();
		accion += inChar;
 	 }
}

