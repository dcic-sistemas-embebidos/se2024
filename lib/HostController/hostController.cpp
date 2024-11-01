#include <Arduino.h>
#include "hostController.h"


// Buffer interno para almacenar los datos recibidos
String commandBuffer = "";


void host_controller_setup() {
    Serial.begin(115200);
    const char* message = "Interfaz de Comunicación Iniciada.\n";
    host_controller_tx((uint8_t*)message, strlen(message));
}


void host_controller_tx(uint8_t *data, size_t len) {
    Serial.write(data, len);
}

String host_controller_rx() {
    
    while (Serial.available() > 0) {
        char incomingChar = Serial.read();  
        commandBuffer += incomingChar;      

        // Si se detecta un fin de línea, el comando está completo
        if (incomingChar == '\n') {
            String completedCommand = commandBuffer;  
            commandBuffer = "";  
            return completedCommand;  
        }
    }

    // Si no se ha recibido el fin de línea, retornar NULL
    return "";
}

void process_commands(String command) {
    
    const char* message = command.c_str();
    host_controller_tx((uint8_t*)message, strlen(message));

}

void host_controller_loop() {
    
    // Lee los datos que se encuentren en el buffer serial
    String receivedCommand = host_controller_rx();

    if (receivedCommand != "") {
        // Aquí debería estar la función para procesar los comandos
        process_commands(receivedCommand);
    }

    delay(100);  
}

