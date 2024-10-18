#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <Arduino.h>

#define START_DELIMITER '#'
#define END_DELIMITER ';'
#define MAX_MESSAGE_LEN 16 

int i = 1;


typedef struct {
    char command; 
    int param;     
    int valid;     
} ProtocolMessage;

// Función para convertir caracteres ASCII a número
int ascii_to_int(const char *str) {
    int result = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) return -1;  
        result = result * 10 + (str[i] - '0');
    }
    return result;
}

// Función para parsear el mensaje
ProtocolMessage parse_message(const char *msg) {
    ProtocolMessage parsed_msg = {'\0', 0, 0};  
    
    if (msg[0] != START_DELIMITER || msg[strlen(msg) - 1] != END_DELIMITER) {
        printf("Error: Delimitadores incorrectos\n");
        return parsed_msg;
    }

    char command = msg[1];
    if (command != 'F' && command != 'B' && command != 'L' && command != 'R' && command != 'S' && command != 'P') {
        printf("Error: Comando no válido\n");
        return parsed_msg;
    }

    parsed_msg.command = command;

    if (strlen(msg) > 3) {
        char param_str[MAX_MESSAGE_LEN - 3] = {0}; 
        strncpy(param_str, &msg[2], strlen(msg) - 3); 

        int param = ascii_to_int(param_str);
        if (param == -1) {
            printf("Error: Parámetro no válido\n");
            return parsed_msg;
        }

        parsed_msg.param = param;
    }

    parsed_msg.valid = 1;
    return parsed_msg;
}

// Función para manejar mensajes y errores
void handle_message(const char *input) {
    if (strlen(input) < 3 || strlen(input) > MAX_MESSAGE_LEN) {
        printf("Error: Mensaje con longitud incorrecta\n");
        return;
    }

    ProtocolMessage msg = parse_message(input);

    if (msg.valid) {
        switch (msg.command) {
            case 'F':
                printf("Comando: Adelante. Velocidad: %d\n", msg.param);
                break;
            case 'B':
                printf("Comando: Atrás. Velocidad: %d\n", msg.param);
                break;
            case 'L':
                printf("Comando: Izquierda\n");
                break;
            case 'R':
                printf("Comando: Derecha\n");
                break;
            case 'S':
                printf("Comando: Detener\n");
                break;
            case 'P':
                printf("Comando: Ping\n");
                break;
            default:
                printf("Error: Comando no soportado\n");
        }
    }
}

void loop(){
    // Ejemplos de mensajes para probar el protocolo
    char msg1[] = "#F100;";
    char msg2[] = "#B50;";
    char msg3[] = "#L;";
    char msg4[] = "#P;";
    char msg_err[] = "#X100;";  // Comando inválido

    while(i == 1){ 
        // Manejo de mensajes
        handle_message(msg1);
        handle_message(msg2);
        handle_message(msg3);
        handle_message(msg4);
        handle_message(msg_err);
        i = 0;
    }
}

void setup(){
}

