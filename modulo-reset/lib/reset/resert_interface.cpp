#include "reset_interface.h"
#include <esp_task_wdt.h>
#include <Arduino.h>

#define WDT_TIMEOUT 3
#define UART_BAUD_RATE 115200

void reset_interface_begin(){
    Serial.begin(UART_BAUD_RATE);
    Serial.println("Configurando WDT...");
    esp_task_wdt_init(WDT_TIMEOUT, true);
    esp_task_wdt_add(NULL);
}   