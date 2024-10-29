# Controlador de LCD

## Pines de conexión

Para la pantalla 

| ESP32 | LCD |
|-------|-----|
| D5 | 8 |
| D18 | 9 |
| D19 | 10 |
| D21 | 11 |
| D22 | 7 |
| D23 | 6 |

![lcd conexion](/lcd_conexion.png)


La alimentación de la pantalla, que son los pines que se encuentran debajo de la misma, al lado de la botonera.

Asumiendo que **el primer pin es el pin 0**. Esta consideración es para ambas conexiones.

| ESP32 | LCD |
|-------|-----|
| 3V3 | 1 |
| Vin | 2 |
| GND | 3 |
