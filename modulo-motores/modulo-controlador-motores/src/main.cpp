#include <Arduino.h>
#include "motor_driver.h"
#include "move_controller.h"

String accion = "";

void setup() {

}

void loop() {

	//Integrar modulo recepcion de mensajes
	//accion = recibir_mensaje();

    if (accion.length() > 0) {

      	if (accion == "w") {
        	robot_avanzar();
    	}

		if (accion == "s") {
			robot_detenerse();
		}

		if (accion == "a") {
			robot_girar_izquierda();
		}

		if (accion == "d") {
			robot_girar_derecha();
		}

    	accion = "";
    }

    delay(10);
}