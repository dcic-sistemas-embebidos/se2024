#include <Arduino.h>
#include <esp_task_wdt.h>

void tareaEjemplo (void *parametros){
    while(1){
        Serial.println("Tarea funcionando...");
        delay(2000);
        esp_task_wdt_reset();
    }
}