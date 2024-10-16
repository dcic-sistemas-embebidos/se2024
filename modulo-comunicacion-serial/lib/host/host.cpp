#include "host.h"

// Buffer interno para almacenar los datos recibidos
String commandBuffer = "";

#define LED_PIN 2 // Pin del LED 

void host_setup() {
    Serial.begin(115200);
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW); 
}


void host_tx(uint8_t *data, size_t len) {
    Serial.write(data, len);
}

String host_rx() {
    String incomingData = "";

    // Esperar a que haya datos disponibles en el buffer serial
    while (Serial.available() > 0) {
        return Serial.readStringUntil('\n');
    }

    return incomingData;  // Retornar el comando recibido
}



void process_commands(String command) {
    command.trim();

    const char* message;

    if (command == "encender") {
        digitalWrite(LED_PIN, HIGH);
        message = "LED encendido.\n";
        host_tx((uint8_t*)message, strlen(message));
    } else if (command == "apagar") {
        digitalWrite(LED_PIN, LOW);
        message = "LED apagado.\n";
        host_tx((uint8_t*)message, strlen(message));
    } else {
        message = "Comando no reconocido. Use 'encender' o 'apagar' \n";
        host_tx((uint8_t*)message, strlen(message));
    }
}
