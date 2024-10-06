#include <Arduino.h>
#include <LiquidCrystal.h>
#include <test_hw_interfaz.h>

LiquidCrystal lcd(22, 23, 21, 19, 18, 5);

void testLed(int pin_led)
{
  pinMode(pin_led, OUTPUT);
  digitalWrite(pin_led, LOW); // Comienza con el LED apagado
  Serial.println("test del led iniciada...");
  if (digitalRead(pin_led) == LOW)
  {
    digitalWrite(pin_led, HIGH); // Enciende el LED
    Serial.println("LED encendido..");
  }
  else
  {
    digitalWrite(pin_led, LOW); // Apaga el LED
    Serial.println("LED apagado...");
  }
}

void testPulsador(int pin_pulsador)
{
  pinMode(pin_pulsador, INPUT_PULLUP);
  Serial.println("test del pulsador iniciada...");
  int buttonState = digitalRead(pin_pulsador);

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

void testLCD(String txt, int pin_boton_lcd)
{
  pinMode(pin_boton_lcd, INPUT);
  lcd.begin(16, 2);
  _testLCDTxt(txt);
  _testLCDButtons(pin_boton_lcd);
}

void _testLCDTxt(String txt)
{
  lcd.setCursor(0, 0);
  lcd.print(txt);
}

void _testLCDButtons(int pin_boton_lcd)
{
  int val_boton = analogRead(pin_boton_lcd);
  lcd.setCursor(0, 1);
  Serial.println(val_boton);
  String msg = "";

  // if( val_boton > 0 && val_boton < 682.5 )  lcd.print("RESET");;
  // if( val_boton > 682.5 && val_boton < 1365)  lcd.print("SELECT");
  if (val_boton > 2700 && val_boton < 4095)
    msg = "Izquierda";
  if (val_boton > 1700 && val_boton < 2700)
    msg = "Abajo";
  if (val_boton > 600 && val_boton < 1700)
    msg = "Arriba";
  if (val_boton == 0)
    msg = "Derecha";
  if (val_boton == 4095)
    msg = "Aprete un boton";
  lcd.print(msg);
  Serial.println(msg);

  delay(1000);
}