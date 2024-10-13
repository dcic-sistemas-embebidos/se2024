#include "motores_interface.h"

void procesarEntradas(){
	char entrada = 'W';

	switch(entrada){
		case 'W':
			//avanzar();
			break;
		case 'S':
			//detener();
			break;
		case 'A':
			//girar_izquierda();
			break;
		case 'D':
			//girar_derecha();
			break;
	}
}

void main(){
	motores_setup();
}

void loop(){
	procesarEntradas();
}
