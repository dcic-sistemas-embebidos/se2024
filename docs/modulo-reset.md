# Módulo Reset

## Watchdog Timer

**esp_task_wdt_init()**: determina el tiempo que debe transcurrir para el wdt reinicie el sistema. 

**esp_task_wdt_reset()**: se llama en el bucle de la tarea para informar si la tarea se sigue ejecutando. Esta es la función que, si no se llama en el tiempo determinado en la función de arriba, se produce el reinicio del sistema.

**esp_task_wdt_add()**: añade las tareas al watchdog timer para que verifiquen que no se quedó colgada o bloqueada la tarea.

## Tareas

Dentro de la tarea, tengo que llamar al _esp_task_wdt_reset()_ para evitar reinicios.

Dentro del _reset_interface_begin()_, para poder crear tareas necesito las librerias de 
```
#include "freertos/FreeRTOS.h" 
#include "freertos/task.h"
```
Y luego, declarar un manejador de tareas 

```
TaskHandle_t tareaHandle;
```
Por último, creo la tarea

```
xTaskCreate (
		nombre_funcion,
		"nombre descriptivo",
		tamaño de la pila de la tarea (bytes),
		parametros de la funcion, en caso de no requerir, NULL,
		numero de prioridad, mas alto el numero, mayor prioridad,
		&manejador de la tarea, para poder suspenderla mas adelante. En caso de no requerir, NULL,
)
```

