#include "host.h"

// Buffer interno para almacenar los datos recibidos
String commandBuffer = "";

void host_setup() {
    Serial.begin(115200);
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW); 
}


void _tx(uint8_t *data, size_t len) {
    Serial.write(data, len);  // Envía 'len' bytes del array 'data' a través del puerto serie
    Serial.flush();
}

String _rx() {
    String incomingData = "";

    // Esperar a que haya datos disponibles en el buffer serial
    while (Serial.available() > 0) {
        return Serial.readStringUntil('\n');
    }

    return incomingData;  // Retornar el comando recibido
}



void process_commands(String command) {
    command.trim(); 
    Serial.println(command);
    if (command == "encender") {
        digitalWrite(LED_PIN, HIGH);
        Serial.println("LED encendido");
    } else if (command == "apagar") {
        digitalWrite(LED_PIN, LOW);
        Serial.println("LED apagado");
    } else {
        Serial.println("Comando no reconocido. Use 'encender', 'apagar'.");
    }
}
