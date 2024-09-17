### Feature toggles

Los feature toggles se utilizan para esconder o deshabilitar secciones de código. Esto permite hacer un release sin la necesidad de que todo el código sea funcional, favoreciendo la integración continua.

Implementaciones:
- Se puede implementar en código utilizando variables específicas, no es recomendable porque para realizar el toggle se necesita otro build.
- Se puede utilizar un servicio, nuestra app al momento de ejecutar consultará al servicio las secciones habilitadas.
- Se puede implementar por hardware utilizando las entradas del microcontrolador.