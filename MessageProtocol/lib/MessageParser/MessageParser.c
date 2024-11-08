#include "MessageParser.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void initParser(MessageParser *parser) {
    memset(parser->buffer, 0, MAX_BUFFER_SIZE);
    parser->index = 0;
    parser->messageComplete = false;
    parser->messageStarted = false;
}

void processByte(MessageParser *parser, char byte) {
    // Si llega un carácter de inicio, descarta el mensaje anterior y comienza uno nuevo
    if (byte == '#') {
        if (parser->index > 0 && !parser->messageComplete) {
            printf("Nuevo mensaje detectado. Descartando mensaje anterior incompleto: %s\n", parser->buffer);
        }
        initParser(parser);
        parser->messageStarted = true;
    }

    if (parser->messageStarted) {
        if (parser->index < MAX_BUFFER_SIZE - 1) {
            parser->buffer[parser->index++] = byte;
            if (byte == ';') {
                parser->messageComplete = true;
            }
        } else {
            printf("Error: buffer lleno. Mensaje descartado.\n");
            initParser(parser);
        }
    }
}

void processMessage(MessageParser *parser) {
    if (parser->messageComplete) {
        // Verifica si el mensaje cumple con la estructura correcta
        if (parser->buffer[0] == '#' && parser->buffer[parser->index - 1] == ';' && parser->index >= 4) {
            // Extrae el comando y la velocidad
            char command = parser->buffer[1];
            int speed = atoi(&parser->buffer[2]);

            // Verifica que la velocidad esté entre 1 y 100
            if (speed >= 1 && speed <= 100) {
                printf("Mensaje completo y válido recibido: %s\n", parser->buffer);
                printf("ACK enviado.\n");
            } else {
                printf("Mensaje descartado: velocidad fuera de rango (1-100) en %s\n", parser->buffer);
            }
        } else {
            printf("Mensaje descartado: estructura inválida en %s\n", parser->buffer);
        }
        initParser(parser);  // Reinicia el parser
    }
}
