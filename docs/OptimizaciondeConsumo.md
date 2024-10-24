# Optimización de Consumo en un Robot con ESP32

En este documento se describen varias técnicas para reducir el consumo energético en un robot de tracción diferencial.
Luego, en caso de que algunas de estas tecnicas quieran ser aplicadas, se deberá estudiar e investigar de que manera aplicarlas al proyecto.

## 1. El ESP32 cuenta con modos de bajo consumo

### a) Modo Deep Sleep del ESP32

El ESP32 tiene varios modos de bajo consumo, siendo el más eficiente el 'Deep Sleep'. En este modo, el procesador principal (CPU) y la mayoría de los periféricos se apagan, dejando subsistemas como el temporizador RTC o algunos pines GPIO activos para mantener la funcionalidad básica.

En 'Deep Sleep', el ESP32 puede consumir tan solo 10 µA o menos. El dispositivo puede despertar mediante un temporizador, un evento en un pin GPIO, o incluso por una señal Bluetooth.

### b) Modo Light Sleep del ESP32

El modo 'Light Sleep' es una opción intermedia entre el funcionamiento normal y el 'Deep Sleep'. En este modo, el procesador se suspende, pero los periféricos de bajo consumo, el Wi-Fi y el Bluetooth pueden permanecer activos. El ESP32 puede entrar en 'Light Sleep' cuando no está realizando tareas críticas, pero aún necesita responder rápidamente a eventos externos.

En este modo, el ESP32 consume unos pocos miliamperios, lo que lo convierte en una opción útil si necesitas mantener una comunicación activa sin consumir tanta energía como en el modo normal.

## 2. Bluetooth Low Energy (BLE)

Si el robot se controla mediante Bluetooth, cambiar a Bluetooth Low Energy (BLE) puede disminuir significativamente el consumo energético. A diferencia del Bluetooth clásico, BLE mantiene la mayoría de los dispositivos en estado de reposo, despertando brevemente para enviar o recibir datos, lo que reduce el uso de energía.

## 3. Optimización del Control de Motores

### a) PWM eficiente para controlar motores

El control de motores mediante modulación por ancho de pulso (PWM) permite ajustar la velocidad y el consumo energético. El ciclo de trabajo del PWM define cuánto tiempo está activo el motor, lo que puede reducir significativamente el consumo si no se requiere operar a máxima velocidad.

### b) Apagado automático de motores

Los motores pueden apagarse por completo cuando el robot no está en movimiento para ahorrar energía. Esto puede hacerse utilizando transistores MOSFET o relés controlados por el ESP32.
