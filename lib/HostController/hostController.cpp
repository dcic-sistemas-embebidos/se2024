#include "hostController.h"

// Buffer interno para almacenar los datos recibidos
String commandBuffer = "";


void host_controller_setup() {
    Serial.begin(115200);
}


void host_controller_tx(uint8_t *data, size_t len) {
    Serial.write(data, len);
}

String host_controller_rx() {
    String incomingData = "";

    // Esperar a que haya datos disponibles en el buffer serial
    while (Serial.available() > 0) {
        return Serial.readStringUntil('\n');
    }

    return incomingData;  // Retornar el comando recibido
}

void host_controller_main() {
    host_controller_setup();
    const char* message = "Interfaz de Comunicación Iniciada.\n";
    host_controller_tx((uint8_t*)message, strlen(message));
}

void host_controller_loop() {
    
    // Lee los datos que se encuentren en el buffer serial
    String receivedCommand = host_controller_rx();

    // Aqui deberia estar la funcion para procesar los comandos
    process_commands(receivedCommand);

    delay(100);  
}

void process_commands(String command) {
    command.trim();

    const char* message = command.c_str();

    host_controller_tx((uint8_t*)message, strlen(message));

}