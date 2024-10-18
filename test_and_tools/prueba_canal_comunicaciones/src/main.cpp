#include <Arduino.h>

#define UART_BAUD_RATE 115200

void setup() {
    // Inicializar la comunicación serie
    Serial.begin(UART_BAUD_RATE);
    Serial.println("Inicializando UART");
    
    pinMode(2, OUTPUT);
    digitalWrite(2, HIGH);
    
}

void loop() {
    static String inputString = ""; // Variable para almacenar la línea recibida

    // Verifica si hay datos disponibles en el puerto serie
    if (Serial.available()) {
        char inChar = (char)Serial.read(); // Lee el siguiente byte disponible

        if (inChar == '\n') { // Verifica si es el carácter de nueva línea
            Serial.print("Recibido: ");
            Serial.println(inputString); // Imprime la línea recibida

            // Enviar una respuesta de vuelta
            Serial.println("Mensaje recibido");
            inputString.trim(); 
            if (inputString == "encender") {
              // Encender un LED, por ejemplo
              digitalWrite(2, HIGH);
            } else if (inputString == "apagar") {
              // Apagar un LED
              digitalWrite(2, LOW);
            }
            // Limpiar la cadena para la próxima línea
            inputString = "";
        } else {
            inputString += inChar; // Añade el carácter a la cadena
        }
    }
}
