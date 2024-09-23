### Requerimientos

Como requerimiento se puede mencionar la utilización de una rama principal, desde la cual nacerán todas las ramas y luego de su desarrollo serán mergeadas a la rama principal. Estas nuevas ramas deben ser de corta vida y sin mantenimiento, es decir, si nuestro nuevo código luego de ser mergeado tiene un bug en la release, el arreglo debe ser pusheado a la rama principal o crear una nueva rama para ese bug.
En una implementación ideal de este método de desarrollo se haría pair programming y se utilizarían test automatizados, esto permitiría pushear el código a trunk directamente sin necesidad de crear otra rama. En caso de no poder hacer pair programming se suelen crear nuevas ramas con las que luego se piden merge request o pull request, esto genera la necesidad de una revisión por otro integrante del equipo. Se busca que los desarrolladores comenten el código y se aseguren de que funciona bien antes de mergear a trunk.

### Integración continua y rechazo de merges que introducen errores de compilación

La Integración continua requiere el uso de test automatizados. Hay distintos tipos de test que pueden correr en los diferentes estados del pipeline.
Las pruebas unitarias y de integración de ejecución corta se ejecutan durante el desarrollo y tras la fusión del código. Las pruebas de ejecución más prolongada, de pila completa y de extremo a extremo se ejecutan en fases posteriores de la canalización contra un entorno de ensayo o producción completo.

### Feature toggles

Los feature toggles se utilizan para esconder o deshabilitar secciones de código. Esto permite hacer un release sin la necesidad de que todo el código sea funcional, favoreciendo la integración continua.

Implementaciones:
- Se puede implementar en código utilizando variables específicas, no es recomendable porque para realizar el toggle se necesita otro build.
- Se puede utilizar la aplicacion que controla el robot, nuestra app al momento de ejecutar consultará las secciones habilitadas.
- Se puede implementar por hardware utilizando las entradas del microcontrolador.