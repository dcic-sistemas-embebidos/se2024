#include "serial_interface.h"

// Inicializa el puerto serie y el LED
void serial_interface_begin() {
    Serial.begin(115200);
    Serial.println("Interfaz de Comunicación Iniciada.");
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW); // Inicialmente, el LED está apagado
}

// Procesa los comandos recibidos por el puerto serie
void process_commands() {
    if (Serial.available()) {
        String command = Serial.readStringUntil('\n');
        command.trim();  // Eliminar espacios en blanco

        // Procesar los comandos reconocidos
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
}
