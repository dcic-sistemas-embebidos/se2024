#include "reset_interface.h" 
#include "tarea.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <esp_task_wdt.h>

TaskHandle_t tareaHandle;

void setup() {
  tareaHandle = NULL;
  reset_interface_begin();
  xTaskCreate(tareaEjemplo, "Tarea Ejemplo", 2048, NULL, 1, &tareaHandle);
  esp_task_wdt_add(tareaHandle);
}

void loop() {
    
}
