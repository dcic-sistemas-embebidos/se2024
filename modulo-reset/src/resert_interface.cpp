#include "reset_interface.h"

void reset_interface_begin(){
    Serial.begin(115200);
    pinMode(BUTTON_RESET, INPUT_PULLUP);
}

void reset(){
    int buttonState = digitalRead(BUTTON_RESET);
    if(buttonState == LOW){
        Serial.println("Reiniciando ESP32.");
        delay(1000);
        ESP.restart();
    }
}
