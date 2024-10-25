#include <Arduino.h>
#include <motores_interface.h>

String accion = "";

void setup() {

  	Serial.begin(115200);

	motores_setup();
}

void loop() {

	recibir_mensaje();

	if (accion.length() > 0) {

		if (accion == "w") {
			robot_avanzar();
			Serial.println("Robot avanzando");
		}

		if (accion == "s") {
			robot_detenerse();
			Serial.println("Robot detenido");
		}

		if (accion == "a") {
			robot_girar_izquierda();
			Serial.println("Robot girando izquierda");
		}

		if (accion == "d") {
			robot_girar_derecha();
			Serial.println("Robot girando derecha");
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