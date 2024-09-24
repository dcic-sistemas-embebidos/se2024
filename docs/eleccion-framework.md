# Elección de Framework, biblioteca o Sistema operativo

Para el proyecto que se plantea como [objetivo a alcanzar](https://github.com/dcic-sistemas-embebidos/se2024/blob/main/docs/alcance-version1.md) con una arquitectura con Round-Robin con interrupciones, se alcanza la meta propuesta. Esta arquitectura la propone el _framework de Arduino_ que además dentro de este framework, también se cuenta con el _ESP-IDF framework_.

## Características

* El código de cada tarea corre a la misma prioridad.
* Tienen datos compartidos entre rutinas de interrupciones y el código de tarea.
* Cuenta con tiempos largos de respuesta, si justo ocurre el evento inmediatamente después de que se paso el polling del flag.
* En el proyecto, no hay tiempos de procesamiento demasiados elevados en respuesta a eventos.

## A futuro

En el caso que más adelante se mejore el proyecto, agregando sensonres para la detección de obstáculos o para realizar un comportamiento simple, sigue siendo uno con pocos dispositivos. Por lo tanto, esta arquitectura sigue siendo útil.
