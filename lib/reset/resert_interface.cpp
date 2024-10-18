#include "reset_interface.h"
#include <esp_task_wdt.h>
#include <Arduino.h>

#define WDT_TIMEOUT 3
#define UART_BAUD_RATE 115200

void setup_reset(){
    Serial.begin(UART_BAUD_RATE);
    Serial.println("Configurando WDT...");
    esp_task_wdt_init(WDT_TIMEOUT, true);
    esp_task_wdt_add(NULL);
}   

void loop_reset(){
    esp_task_wdt_reset();
}

void force_reset(){
    Serial.println("Forzando el reset...");
    delay(4000);
}