# Protocolo de Comunicación entre Aplicación y ESP32

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
La aplicación envía un **PING** periódicamente:
`PING`
El ESP32 responde con un **PONG**:
`PONG`

## 6. Validación de Mensajes con Checksum
Para validar los mensajes, se puede agregar un campo de checksum al final.

### Ejemplo con Checksum:
`MOV;FWD;SPEED=100;CHECKSUM=3A`

### Respuesta del ESP32:
- Si el mensaje es correcto:
`ACK`
- Si el mensaje es incorrecto:
`NACK`
