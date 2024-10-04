#include <Arduino.h>
#include <LiquidCrystal.h>
#include <test_hw_interfaz.h>

LiquidCrystal lcd(22, 23, 21, 19, 18, 5);

void testLed(int pin_led)
{
  // Configurar el pin  como salida para el LED
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW); // Comienza con el LED apagado
  Serial.println("test del led iniciada...");
  if (digitalRead(ledPin) == LOW)
  {                              // Si el pulsador está presionado
    digitalWrite(ledPin, HIGH); // Enciende el LED
    Serial.println("LED encendido..");
  }
  else
  {
    digitalWrite(ledPin, LOW); // Apaga el LED
    Serial.println("LED apagado...");
  }
}

void testPulsador(int pin_pulsador)
{
  // Configurar el pin 4 como entrada para el pulsador con resistencia pull-up
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.println("test del pulsador iniciada...");
  // Leer el estado del pulsador
  int buttonState = digitalRead(buttonPin);

  // Imprimir el estado del pulsador en el monitor serial
  if (buttonState == LOW)
  { // Pulsador presionado
    Serial.println("Pulsador presionado");
  }
  else
  { // Pulsador no presionado
    Serial.println("Pulsador no presionado");
  }

  delay(500);
}

void testLCD(String txt, int boton_lcd)
{
  pinMode(boton_lcd, INPUT);
  lcd.begin(16, 2);
  _testLCDTxt(txt);
  _testLCDButtons(boton_lcd);

}

void _testLCDTxt(String txt)
{
  lcd.setCursor(0, 0);
  lcd.print(txt);
}

void _testLCDButtons(int boton_lcd)
{
  int val_boton = analogRead(boton_lcd);
  lcd.setCursor(0, 1);
  Serial.println(val_boton);
  //if( val_boton > 0 && val_boton < 682.5 )  lcd.print("RESET");;  
  //if( val_boton > 682.5 && val_boton < 1365)  lcd.print("SELECT");
  if( val_boton > 2700 && val_boton < 4095)  lcd.print("Izquierda");    
  if( val_boton > 1700 && val_boton < 2700)  lcd.print("Abajo");        
  if( val_boton > 600 && val_boton < 1700)  lcd.print("Arriba");        
  if( val_boton == 0 )  lcd.print("Derecha");
  if( val_boton == 4095 )  lcd.print("Aprete un boton");
  delay(1000);
}