#include "serial_interface.h"


void serial_interface_begin() {
    Serial.begin(115200);
    Serial.println("Interfaz de Comunicación Iniciada.");
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW); 
}

void process_commands(String command) {
    command.trim(); 

    if (command == "encender") {
        digitalWrite(LED_PIN, HIGH);
        Serial.println("LED encendido");
    } else if (command == "apagar") {
        digitalWrite(LED_PIN, LOW);
        Serial.println("LED apagado");
    } else if (command == "status") {
        if (digitalRead(LED_PIN) == HIGH) {
            Serial.println("El LED está encendido");
        } else {
            Serial.println("El LED está apagado");
        }
    } else {
        Serial.println("Comando no reconocido. Use 'encender', 'apagar' o 'status'.");
    }
}
