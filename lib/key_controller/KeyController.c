#include <Arduino.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(22, 23, 21, 19, 18, 5);

void setupKC()
{
}

void loopKC()
{
    _readButtonsDisplay(2);
    _pressingPulse(3);
    _pressingKey(4);
}

int _readButtonsDisplay(int pin_button_display)
{
    //TODO retorno un entero que signifique un boton o una cadena, ej "derecha"
    int val_boton = analogRead(pin_button_display);
    lcd.setCursor(0, 1);
    String msg = "";
    int boton = 0;

    // if( val_boton > 0 && val_boton < 682.5 )  lcd.print("RESET");
    // if( val_boton > 682.5 && val_boton < 1365)  lcd.print("SELECT");
    if (val_boton > 2700 && val_boton < 4095)
    {
        msg = "Izquierda";
        boton = 1;
    }
    if (val_boton > 1700 && val_boton < 2700)
    {
        msg = "Abajo";
        boton = 2;
    }
    if (val_boton > 600 && val_boton < 1700)
    {
        msg = "Arriba";
        boton = 3;
    }
    if (val_boton == 0)
    {
        msg = "Derecha";
        boton = 4;
    }
    if (val_boton == 4095)
    {
        msg = "Aprete un boton";
    }

    lcd.print(msg);

    delay(1000);
    // 1 Izq 2 Abajo 3 Arriba 4 Abajo 0 Ninguno
    return boton;
}

bool _pressingPulse(int btn_pulse)
{
    pinMode(btn_pulse, INPUT_PULLUP);
    int buttonState = digitalRead(btn_pulse);
    bool res = false;
    if (buttonState == LOW)
    { // Pulsador presionado
        Serial.println("Pulsador presionado");
        res = true;
    }
    else
    { // Pulsador no presionado
        Serial.println("Pulsador no presionado");
    }

    delay(500);
    return res;
}

bool _pressingKey(int btn_key)
{
    pinMode(btn_key, INPUT_PULLUP);
    int keyState = digitalRead(btn_key);
    bool res = false;
    if (keyState == LOW)
    { // Pulsador presionado
        Serial.println("Llave presionada");
        res = true;
    }
    else
    { // Pulsador no presionado
        Serial.println("Llave no presionada");
    }

    delay(500);
    return res;
}