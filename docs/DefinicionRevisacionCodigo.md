# Guía para la Revisión de Código en un Proyecto

## Introducción
La revisión de código (code review) es una etapa crucial en un proyecto de software. Permite mejorar la calidad del código, garantizar el cumplimiento de las normas de codificación y facilitar la colaboración dentro del equipo. Esta guía explica cómo realizar una revisión de código efectiva.

## Objetivos de la revisión de código
- **Detectar errores o anomalías potenciales**
- **Mejorar la calidad y legibilidad del código**
- **Asegurar que el código respete las normas del equipo**
- **Facilitar el mantenimiento y la comprensión a largo plazo**

## Pasos para revisar el código

### 1. Preparación
Antes de comenzar la revisión:
- **Entender el contexto**: Asegúrate de comprender bien la funcionalidad que el código debe implementar. Lee la descripción del ticket o la tarea asociada para informarte.
- **Descargar la última versión del código**: Asegúrate de tener la rama o pull request más reciente para evitar revisar código obsoleto.
bash
git checkout nombre-de-la-rama
git pull

Más explicaciones en el [Contributing](https://github.com/dcic-sistemas-embebidos/se2024/blob/main/CONTRIBUTING.md)

### 2. Lectura inicial del código
Comienza con una primera lectura general:
- **Verifica la estructura general** del código.
- **Asegúrate de que los nombres de variables, funciones y clases** sean claros y descriptivos.
- **Identifica la lógica global** y asegúrate de que el código sea fácil de seguir.

// Incorrecto
int x, y;
void f() {}

// Correcto
int ancho, alto;
void dibujarRectangulo() {}


### 3. Cumplimiento de las convenciones de codificación
Asegúrate de que el código siga las convenciones definidas por el equipo:
- **Indentación y formato**: ¿El código está correctamente indentado? ¿Las líneas no son demasiado largas?
- **Nombres de variables y funciones**: ¿Siguen las convenciones de nomenclatura (camelCase, snake_case, etc.)?
- **Comentarios**: ¿El código está bien comentado, con explicaciones cuando es necesario? Los comentarios deben aclarar, no simplemente repetir lo que hace el código.

// Incorrecto
if(cond) { cout << "Ok"; }

// Correcto
if (condicion) {
    cout << "Ok";
}

### 4. Calidad del código
Verifica si el código sigue buenas prácticas:
- **Legibilidad**: ¿El código es simple de leer y entender? Evita estructuras de código demasiado complejas.
- **Modularidad**: ¿Las funciones o métodos son demasiado largos? Si una función hace varias cosas, podría ser una señal de que debe dividirse en funciones más pequeñas.
- **Reutilización**: ¿Hay código duplicado? Si es así, sugiere una abstracción o la creación de una función reutilizable.

// Función demasiado larga
void procesar() {
  // Muchas operaciones
}

// Mejor modularización
void cargarDatos() {}
void procesarDatos() {}

### 5. Rendimiento y eficiencia
- **Optimización**: ¿El código es eficiente? ¿Hay bucles o llamadas a funciones innecesarias?
- **Complejidad**: Si es posible, evalúa la complejidad algorítmica (tiempo y espacio) y revisa si se puede mejorar.

### 6. Seguridad y manejo de errores
- **Validación de entradas**: Asegúrate de que las entradas del usuario estén correctamente verificadas y validadas.
- **Manejo de excepciones**: ¿El código maneja correctamente errores y excepciones? No debe haber riesgos de fallos no gestionados.
- **Seguridad**: Si el código maneja información sensible, asegúrate de que sigue las buenas prácticas de seguridad.

// Sin validación
void procesar(int input) { /* ... */ }

// Con validación
void procesar(int input) {
  if (input < 0) throw invalid_argument("Entrada inválida");
}

### 7. Feedback constructivo
Al dejar comentarios:
- **Sé preciso**: Evita comentarios vagos. Indica exactamente lo que puede mejorarse, por ejemplo: "Esta función podría ser refactorizada para reducir la duplicación de código".
- **Sé amable**: Destaca también los aspectos positivos, especialmente si el código está bien estructurado o sigue buenas prácticas.
- **Propón soluciones**: Si es posible, sugiere mejoras o ejemplos para ayudar al autor a corregir el código.

### 8. Solicitud de aclaraciones
Si alguna parte del código no está clara o no entiendes la intención detrás de una implementación:
- **Haz preguntas**: En lugar de suponer que algo está mal, pide al autor que explique su lógica.

### 9. Finalización
Una vez que la revisión esté completa:
- **Apropiación de las sugerencias**: Discute con el autor si hay puntos en desacuerdo y busca un consenso.
- **Validación de los cambios**: Después de las correcciones, relee rápidamente el código para asegurarte de que todo se ha tomado en cuenta antes de la aprobación final.

## Conclusión
La revisión de código es una responsabilidad compartida en un equipo. Refuerza la colaboración, asegura la calidad del proyecto y mejora las habilidades de cada miembro. Siguiendo estos pasos, podrás realizar una revisión eficiente mientras fomentas un buen ambiente de trabajo.

#### 10. Pruebas ( opcional )
- **Pruebas unitarias**: ¿Existen pruebas para cada funcionalidad crítica? Si no, sugiere añadir pruebas.
- **Pruebas automatizadas**: Verifica si se han escrito pruebas automatizadas y si cubren bien las diferentes funcionalidades.
- **Ejecución de pruebas**: ¿El código ha pasado todas las pruebas? Si alguna prueba falla, identifica por qué.
