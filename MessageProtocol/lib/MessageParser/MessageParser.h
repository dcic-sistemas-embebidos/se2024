#ifndef MESSAGE_PARSER_H
#define MESSAGE_PARSER_H

#include <stdbool.h>

#define MAX_BUFFER_SIZE 50
#define TIMEOUT 2000  // Timeout en milisegundos

// Estructura para el parser de mensajes
typedef struct {
    char buffer[MAX_BUFFER_SIZE];
    int index;
    bool messageComplete;
    unsigned long lastByteTime;
    bool messageStarted;
} MessageParser;

// Inicialización del parser
void initParser(MessageParser *parser);

// Procesa un byte de entrada
void processByte(MessageParser *parser, char byte);

// Procesa el mensaje cuando está completo
void processMessage(MessageParser *parser);

// Función para obtener el tiempo actual en milisegundos
unsigned long getCurrentMillis();

#endif
