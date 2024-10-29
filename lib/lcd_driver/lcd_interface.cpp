#include "lcd_interface.h"
#include <Wire.h>
#include <LiquidCrystal.h>
#include <Arduino.h>

// Pins para el LCD
LiquidCrystal lcd(22, 23, 21, 19, 18, 5);

void setup_lcd(){
    lcd.begin(16, 2);  // Inicializo la pantalla 16x2
    lcd.setCursor(0, 0);
    lcd.print("Mensajes: ");
}

void scrollMessage(char* message, int row) {
  int messageLength = strlen(message);
  for (int i = 0; i < messageLength; i++) {
    lcd.setCursor(0, row);
    char buffer[17]; //16 + 1 null
    strncpy(buffer, message + i, 16);
    //lcd.print(message.substring(i, i + 16));  //muestro la subcadena
    buffer[16] = '\0';
    lcd.print(buffer);
    delay(700);  // velocidad de desplazamiento

    if (i + 16 >= messageLength) { //reset de la cadena
      i = -1;
    }
  }
}
void loop_lcd(char* msg){
  scrollMessage(msg, 1); 
  delay(2000);  //para visualizar el mensaje
}
