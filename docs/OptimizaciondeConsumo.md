# Optimización de Consumo en un Robot con ESP32

## Propuesta para la optimización
Viendo las [técnicas para reducir el consumo de nuestro robot](#técnicas-para-reducir-el-consumo-energético-del-robot). Mi propuesta para optimizar el consumo de nuestro robot es implementar el modo **Light Sleep** del ESP32.

A continuación muestro una forma de poder implementar el modo light sleep en nuestro proyecto.

## Implementación Básica del Modo Light Sleep
1. **Configuración:** Añadir el modo light sleep. Esto se hace principalmente en el archivo principal del código (`main.cpp`).
2. **Activación del modo light sleep:** A continuación, se presenta un ejemplo de cómo configurar el modo de sueño ligero para que el ESP32 entre en este estado y despierte luego de un tiempo determinado (con un temporizador de 1 segundo en el ejemplo).

```cpp
#include <Arduino.h>
#include "esp_sleep.h"  // Biblioteca para control de sueño en el ESP32

void setup() {
  Serial.begin(115200);
  // Configuración inicial del robot
}

void loop() {
  // Condiciones de activación del modo light sleep, como inactividad de sensores.
  
  // Configuración del temporizador para despertar
  esp_sleep_enable_timer_wakeup(1000000);  // Temporizador para despertar cada 1 segundo
  
  // Entra en modo light sleep
  esp_light_sleep_start();  // Activa el modo de sueño ligero

  // Este mensaje se imprimirá cada vez que despierte
  Serial.println("Despertó del modo light sleep");
}
```

Este código configura el ESP32 para entrar en **light sleep** y despertarse cada 1 segundo.  
También es posible despertar el ESP32 mediante una interrupción externa en un GPIO.

### Ejemplo de configuración para GPIO:

```cpp
#include <Arduino.h>
#include "esp_sleep.h"

#define SENSOR_PIN GPIO_NUM_X  // Reemplazar X con el número de GPIO

void setup() {
  Serial.begin(115200);

  // Configurar el pin como entrada
  pinMode(SENSOR_PIN, INPUT_PULLUP);

  // Configurar el despertado con GPIO
  esp_sleep_enable_ext0_wakeup(SENSOR_PIN, 0);  // Despierta al nivel bajo
}

void loop() {
  // Entrar en light sleep hasta que un evento en GPIO despierte el ESP32
  esp_light_sleep_start();

  Serial.println("Despertó por una señal en el GPIO");
}
```

## Comparación Temporizador vs GPIO
Para un robot de tracción diferencial, la opción de despertado más adecuada depende de los requerimientos específicos de la aplicación:

- **Temporizador**: es ideal si el robot necesita verificar su entorno regularmente.
- **GPIO**: es preferible si el robot solo necesita activarse cuando un evento externo, como la detección de un objeto, lo requiere.

## Conclusión
En nuestro caso creo que la opción que deberíamos elegir es despertarlo con una interrupción externa mediante un GPIO.  
Descarto las otras técnicas ya que no creo que valga la pena implementarlas en este punto del proyecto. Las dejo presentadas por si en un futuro son necesarias.

---

## Técnicas para Reducir el Consumo Energético del Robot

### 1. El ESP32 cuenta con modos de bajo consumo
- **Modo Deep Sleep del ESP32**  
  El ESP32 tiene varios modos de bajo consumo, siendo el más eficiente el **Deep Sleep**. En este modo, el procesador principal (CPU) y la mayoría de los periféricos se apagan, dejando subsistemas como el temporizador RTC o algunos pines GPIO activos para mantener la funcionalidad básica.  
  En **Deep Sleep**, el ESP32 puede consumir tan solo 10 µA o menos. El dispositivo puede despertar mediante un temporizador, un evento en un pin GPIO, o incluso por una señal Bluetooth.

- **Modo Light Sleep del ESP32**  
  El modo **Light Sleep** es una opción intermedia entre el funcionamiento normal y el **Deep Sleep**. En este modo, el procesador se suspende, pero los periféricos de bajo consumo, el Wi-Fi y el Bluetooth pueden permanecer activos. El ESP32 puede entrar en **Light Sleep** cuando no está realizando tareas críticas, pero aún necesita responder rápidamente a eventos externos.  
  En este modo, el ESP32 consume unos pocos miliamperios, lo que lo convierte en una opción útil si necesitas mantener una comunicación activa sin consumir tanta energía como en el modo normal.

### 2. Bluetooth Low Energy (BLE)
Si el robot se controla mediante Bluetooth, cambiar a **Bluetooth Low Energy (BLE)** puede disminuir significativamente el consumo energético. A diferencia del Bluetooth clásico, BLE mantiene la mayoría de los dispositivos en estado de reposo, despertando brevemente para enviar o recibir datos, lo que reduce el uso de energía.

### 3. Optimización del Control de Motores
- **PWM eficiente para controlar motores**  
  El control de motores mediante modulación por ancho de pulso (**PWM**) permite ajustar la velocidad y el consumo energético. El ciclo de trabajo del PWM define cuánto tiempo está activo el motor, lo que puede reducir significativamente el consumo si no se requiere operar a máxima velocidad.

- **Apagado automático de motores**  
  Los motores pueden apagarse por completo cuando el robot no está en movimiento para ahorrar energía. Esto puede hacerse utilizando transistores MOSFET o relés controlados por el ESP32.
