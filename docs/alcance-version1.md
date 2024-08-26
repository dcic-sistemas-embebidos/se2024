# Alcance de la Versión 1 del Robot de Tracción Diferencial

## Objetivo General
Implementar la primera versión funcional de un robot de dos ruedas con tracción diferencial, controlado por Bluetooth. El objetivo es que el robot pueda ser controlado desde un dispositivo móvil o computadora y que realice movimientos básicos.

## Alcance del Proyecto

### 1. Base del Robot
- **Diseño y construcción** de la estructura física del robot.
- **Integración de motores** para controlar las dos ruedas.
- Asegurar la **estabilidad y funcionalidad básica** del sistema de tracción diferencial.

### 2. Control por Bluetooth
- **Implementación de un módulo de comunicación Bluetooth**:
  - Permitir la conexión y control del robot desde un dispositivo externo.
  - **Desarrollo de una aplicación básica** o utilización de una app existente para enviar comandos de movimiento:
    - Adelante
    - Atrás
    - Giro a la izquierda
    - Giro a la derecha

### 3. Software de Control
- **Programación del microcontrolador**:
  - Gestión de los comandos recibidos vía Bluetooth.
  - Implementación de un **algoritmo básico de control de movimiento**.
- **Manejo de señales de los sensores** (si se incluyen) para tomar decisiones simples.

### 4. Pruebas y Validación
- **Pruebas de funcionamiento**:
  - Validar que el robot responda adecuadamente a los comandos.
  - Asegurar que el robot pueda operar en un entorno controlado.
- **Documentación**:
  - Registro de las pruebas realizadas y los resultados obtenidos.

![537large](https://github.com/user-attachments/assets/983e9fb9-e562-40c8-96d5-fd3497c3e67d)

## A Futuro

### Sensores
- **Integración de sensores básicos**:
  - Un **sensor de distancia** (por ejemplo, un sensor ultrasónico) para detección de obstáculos.
- **Programación de un comportamiento simple**:
  - Detenerse o girar al detectar un obstáculo.
