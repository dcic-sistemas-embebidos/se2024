#include <Arduino.h>
#include <LiquidCrystal.h>
#include <key_controller.h>

// LiquidCrystal lcd(22, 23, 21, 19, 18, 5);

static int val_boton = 9999;
static bool btnRight = false;
static bool btnLeft = false;
static bool btnUp = false;
static bool btnDown = false;
static bool Key = false;
static bool Btn = false;

// Estado de los botones
static bool lastBtnRight = false;
static bool lastBtnLeft = false;
static bool lastBtnUp = false;
static bool lastBtnDown = false;

void setupKC()
{
}

void loopKC()
{
    _readButtonsDisplay(2);
    _pressingBtn(3);
    _pressingKey(4);
    _changeBtnStatus();
}

void _readButtonsDisplay(int pin_button_display)
{
    // Evaluar rangos de 0 a 600, mayores a 4095, y entre 2700 y 4095
    // @return 1 Izq 2 Abajo 3 Arriba 4 Abajo 0 Ninguno
    int val_boton_actual = analogRead(pin_button_display);
    String msg = "";

    if (val_boton_actual != val_boton)
    {
        // TODO enviar notificacion, la notificacion puede ser prender un led,
        // o mostrar un msg por pantalla, se haria llamando a otra funcion
        // de otro controlador que se encargue de eso?
        val_boton = val_boton_actual;
    }

    // if( val_boton > 0 && val_boton < 682.5 )  lcd.print("RESET");
    // if( val_boton > 682.5 && val_boton < 1365)  lcd.print("SELECT");
    if (val_boton > 2700 && val_boton < 4095)
    {
        msg = "Izquierda";
        btnLeft = true;
    }
    if (val_boton > 1700 && val_boton < 2700)
    {
        msg = "Abajo";
        btnDown = true;
    }
    if (val_boton > 600 && val_boton < 1700)
    {
        msg = "Arriba";
        btnUp = true;
    }
    if (val_boton == 0)
    {
        msg = "Derecha";
        btnRight = true;
    }
    if (val_boton == 4095)
    {
        msg = "Aprete un boton";
        btnRight = false;
        btnLeft = false;
        btnUp = false;
        btnDown = false;
    }
    delay(1000);
}

void _pressingBtn(int btn_Btn)
{
    pinMode(btn_Btn, INPUT_PULLUP);
    int buttonState = digitalRead(btn_Btn);
    if (buttonState == LOW)
    { // Pulsador presionado
        Btn = true;
    }
    else
    { // Pulsador no presionado
        Btn = false;
    }
}

void _pressingKey(int btn_key)
{
    pinMode(btn_key, INPUT_PULLUP);
    int keyState = digitalRead(btn_key);
    if (keyState == LOW)
    { // Pulsador presionado
        Key = true;
    }
    else
    { // Pulsador no presionado
        Key = false;
    }
}

void _changeBtnStatus()
{
    if (btnRight != lastBtnRight)
    {
        if (btnRight)
        {
            // Serial.prinln("Derecha presionado");
            //  sendNotification("Derecha presionado");
        }
        else
        {
            // Serial.prinln("Derecha liberado");
            //  sendNotification("Derecha liberado");
        }
        lastBtnRight = btnRight;
    }

    if (btnLeft != lastBtnLeft)
    {
        if (btnLeft)
        {
            // Serial.prinln("Izquierda presionado");
            //  sendNotification("Izquierda presionado");
        }
        else
        {
            // Serial.prinln("Izquierda liberado");
            //  sendNotification("Izquierda liberado");
        }
        lastBtnLeft = btnLeft;
    }

    if (btnUp != lastBtnUp)
    {
        if (btnUp)
        {
            // Serial.prinln("Arriba presionado");
            //  sendNotification("Arriba presionado");
        }
        else
        {
            // Serial.prinln("Arriba liberado");
            //  sendNotification("Arriba liberado");
        }
        lastBtnUp = btnUp;
    }

    if (btnDown != lastBtnDown)
    {
        if (btnDown)
        {
            // Serial.prinln("Abajo presionado");
            //  sendNotification("Abajo presionado");
        }
        else
        {
            // Serial.prinln("Abajo liberado");
            //  sendNotification("Abajo liberado");
        }
        lastBtnDown = btnDown;
    }
}

int *getPressBtn()
{ // TODO la idea es que devuelva un arrglo con los botones que son presionados en un momento
    int *btns = new int[6];
    btns[0] = btnRight ? 1 : 0;
    btns[1] = btnLeft ? 1 : 0;
    btns[2] = btnUp ? 1 : 0;
    btns[3] = btnDown ? 1 : 0;
    btns[4] = Btn ? 1 : 0;
    btns[5] = Key ? 1 : 0;
    return btns;
}

bool pressRight() { return btnRight; }
bool pressLeft() { return btnLeft; }
bool pressUp() { return btnUp; }
bool pressDown() { return btnDown; }
bool pressKey() { return Btn; }
bool pressBtn() { return Key; }
