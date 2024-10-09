# Protocolo de Comunicación entre Aplicación y ESP32

## El protocolo seleccionado es el Protocolo de mensajes simples basado en ASCII:

### Ejemplos de Comandos:
- **F**: Adelante.
- **B**: Atrás.
- **L**: Izquierda.
- **R**: Derecha.
- **S**: Detener.

### Ejemplos con Parámetros:

`F100 → Adelante a velocidad 100.` 
`B50 → Atrás a velocidad 50.`

### Manejo de Errores

Si el ESP32 detecta un error, enviará un código de error sencillo. Los errores son representados por `ERR` seguido de un número que indica el tipo de error.

#### Ejemplos de mensajes de error:
ERR1 → Batería baja. ERR2 → Falla del motor. ERR3 → Comando no válido.

### 3. Solicitud de Estado

Para solicitar el estado actual del robot, la aplicación envía el comando:
S

El ESP32 responde con un mensaje que incluye la dirección y velocidad actuales, además del estado de la batería.

#### Ejemplo de respuesta:
F100B85 → Adelante a velocidad 100, batería al 85%.

### 4. Ping/Pong para Mantener la Conexión

Para verificar que la conexión sigue activa, se implementa un sistema básico de **Ping/Pong**.

- La aplicación envía:
P

- El ESP32 responde:
O

## Ventajas del Protocolo Basado en ASCII:
- **Simplicidad**: Fácil de implementar y depurar.
- **Bajo consumo de recursos**: Adecuado al nivel de procesamiento del ESP32.
- **Compatibilidad**: Interoperable con distintas plataformas y dispositivos.

## Desventajas del Protocolo Basado en ASCII:
- **Flexibilidad limitada**: No es adecuado para manejar información compleja.
- **Errores de interpretación**: No incluye un mecanismo de validación de mensajes.
- **Difícil de extender**: A medida que se añaden más comandos, la gestión puede volverse más complicada.


## 1. Formato de Mensajes
Utilización de un formato estructurado para los mensajes entre el ESP32 y la aplicación. Cada mensaje tiene la siguiente estructura:

COMANDO;DIRECCIÓN;PARÁMETROS

### Comandos:
- **MOV**: Movimiento.
- **STOP**: Detener.
- **STATUS**: Solicitud de estado.

### Direcciones para el comando MOV:
- **FWD**: Adelante.
- **BACK**: Atrás.
- **LEFT**: Izquierda.
- **RIGHT**: Derecha.

### Parámetros opcionales:
- **SPEED**: Velocidad del movimiento.

### Ejemplos:
- `MOV;FWD;SPEED=100` → Mover hacia adelante a velocidad 100.
- `STOP` → Detener el robot.

## 2. Mensajes Simples Basados en ASCII
Otra opción es usar un formato simple basado en caracteres ASCII para los comandos.

### Ejemplos de Comandos:
- **F**: Adelante.
- **B**: Atrás.
- **L**: Izquierda.
- **R**: Derecha.
- **S**: Detener.

### Ejemplos con Parámetros:

`F100 → Adelante a velocidad 100.` 
`B50 → Atrás a velocidad 50.`

## 3. Confirmación y Feedback
El ESP32 debe enviar un mensaje de confirmación después de ejecutar un comando, para asegurar que la acción se ha completado correctamente.

### Ejemplos de Mensajes de Confirmación:

`OK;FWD;SPEED=100` 
`OK;BACK;SPEED=50`
`OK;STOP`

### Manejo de Errores:
En caso de error (por ejemplo, batería baja), se debe enviar un mensaje de error:

`ERR;LOW_BATTERY` 
`ERR;MOTOR_FAILURE`

## 4. Solicitud de Estado
La aplicación puede solicitar información sobre el estado actual del robot.

### Ejemplo de Solicitud de Estado:
STATUS_REQUEST

### Respuesta del ESP32:
`STATUS;FWD;SPEED=80;BATTERY=85%`

Este mensaje incluye la dirección actual, la velocidad y el estado de la batería.

## 5. Ping/Pong para Mantener Conexión Estable
Para asegurar que la conexión sigue activa, se puede implementar un sistema de ping/pong.

### Proceso:
La aplicación envía un **PING** periódicamente. 
El ESP32 responde con un **PONG**

## 6. Validación de Mensajes con Checksum
Para validar los mensajes, se puede agregar un campo de checksum al final.

### Ejemplo con Checksum:
`MOV;FWD;SPEED=100;CHECKSUM=3A`

### Respuesta del ESP32:
- Si el mensaje es correcto:
`ACK`
- Si el mensaje es incorrecto:
`NACK`
