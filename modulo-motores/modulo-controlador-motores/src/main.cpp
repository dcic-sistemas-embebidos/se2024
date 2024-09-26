#include <Arduino.h>
#include <motores_interface.h>

String accion = "";

void setup() {

  configurar_salidas();
}

void loop() {

	//accion = recibir_mensaje();

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