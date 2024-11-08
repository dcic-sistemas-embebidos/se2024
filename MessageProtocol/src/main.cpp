#include <stdio.h>
#include "MessageParser.h"
#include "MessageParser.c"

int i = 1;
// Simulación de recepción de datos
void simulateIncomingData(MessageParser *parser, const char *data) {
    for (int i = 0; data[i] != '\0'; i++) {
        processByte(parser, data[i]);
        processMessage(parser);  // Verifica si el mensaje está completo para procesarlo
    }
}

void loop() {
    MessageParser parser;
    initParser(&parser);
    while(i==1){
        // Ejemplo de mensajes de prueba
        simulateIncomingData(&parser, "#F10;");          // Mensaje completo (adelante, velocidad 10)
        simulateIncomingData(&parser, "#B500;");           // Mensaje completo (atrás, velocidad 5)
        simulateIncomingData(&parser, "#L;#R15;");       // Mensaje incompleto seguido de uno completo
        i=0;
    }
}

void setup(){}