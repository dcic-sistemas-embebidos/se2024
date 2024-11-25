#include "lcd_interface.h"
#include <Wire.h>
#include <LiquidCrystal.h>
#include <Arduino.h>

// Pins para el LCD
LiquidCrystal lcd(22, 23, 21, 19, 18, 5);

void setup_lcd(){
    lcd.begin(16, 2);  // Inicializo la pantalla 16x2
    lcd.clear();
    lcd.backlight();
}

void print_lcd(char* msg, int col, int row){
  lcd.setCursor(col, row);
  lcd.print(msg);
}

void clean_row_lcd(int row){
   for(int i=0; i< 16; i++){
      lcd.setCursor(i, row);
      lcd.print(" ");
  } 
}

void clean_lcd(){
  lcd.clear();
}

void scrollMessage(char* message, int cols, int row) {
  int messageLength = strlen(message);
  for (int i = 0; i < messageLength-15; i++) {
      char buffer[17]; //16 + 1 null
      strncpy(buffer, message + i, 16);
      buffer[16] = '\0';
      print_lcd(buffer, cols, row);
      delay(300);  // velocidad de desplazamiento
  }  
}

void loop_lcd(char* msg, int cols, int row){
  clean_row_lcd(row);
  int msgLength = strlen(msg);
  if(msgLength < 17){
    print_lcd(msg, cols, row);
  }
  else{
    scrollMessage(msg, cols, row); 
  } 

}


