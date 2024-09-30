# Elección de Framework, biblioteca o Sistema operativo

## Conclusión
Para el proyecto que se plantea como objetivo a alcanzarcon una arquitectura con Round-Robin con interrupciones, se alcanza la meta propuesta. Esta arquitectura es propuesta por el _framework de Arduino_, que además incluye el _ESP-IDF framework_. Ambos frameworks ofrecen abundante información y recursos, facilitando considerablemente el desarrollo y la programación del proyecto.

Se descarta la arquitectura _Round-Robin sin interrupciones_ ya que como queremos controlar un robot por medio de un dispositivo, cuando le enviamos la oden de que se mueva para alguna dirección, debería responder ante la interrupción que esta haciendo el dispositivo en cuestión. 

El descartar los _sistemas de tiempo real_ es porque es mucho mas complejo de implementar pero en el caso de que el robot evolucione a un sistema mucho mas complejo, como agregandole disintas funcionalidades que requieran que el sistema tenga que poder sincronizar y planificar los procesos, va a ser necesario utilizarlo. Pero por el momento, tanto el primer alcance como el alcance a futuro, este tipo de arquitectura es sobrada para lo que se necesita. 

El descartar _function-queue-scheduling_ es porque es un poco más compleja de implementar que RR con interrupciones, además de que hay que contemplar que al manejar prioridades puede suceder la inanición. Sumado a que no se cuenta con tanta información como RTOS o RR con interrupciones. 

## Arquitecturas disponibles

Para poder realizar [el proyecto](https://github.com/dcic-sistemas-embebidos/se2024/blob/main/docs/alcance-version1.md) contamos con las siguientes arquitecturas posibles:
* **Round-Robin**: no intervienen las interrupciones. Los eventos ocurridos se lo consultan de forma periódica, para verificar si este sucedió y es recomendado para pocos dispositivos.
* **Round-Robin con interrupciones**: cada tarea tiene la misma prioridad. El ISR realiza la respuesta inicial y el resto de eventos, son realizados por funciones llamadas en el bucle, entonces el ISR indica con flags la necesidad de procesado.
* **Function-Queue-Scheduling**: cada ISR de cada tarea, añade un puntero a la función que lleva a cabo dicha tarea a una cola con prioridad. Las tareas de mayor prioridad se ejecutan primero pero esto genera, riesgo de inanición. 
* **RTOS (Real-Time Operating System)**: se utiliza cuando son escenarios complejos. La aplicación se estructura en un conjunto de ISRs y tareas que se sincronizan. Este mecanismo es provisto por el Sistema Operativo. Las ISRs señalizan a las tareas y estas son planificadas por el RTOS(prioridades, apropiación, etc)

## Criterios de evaluación

El proyecto a realizar es un robot de dos ruedas con tracción diferencial controlado por Bluetooth por medio de un dispositivo móvil que realice movimientos básicos. 

Con el objetivo en mente, se conoce que este necesita el manejo de interrupciones, ya que cuando el dispositivo que controle el movimiento, le ordene realizar una acción, este tendrá que atender esa acción. El prototipo inicial cuenta con pocos dispositivos de E/S y con los alcances a futuro propuestos, seguirá siendo uno con pocos dispositivos. 

## Comparación entre arquitecturas

| Arquitecturas                  | Propiedades                                                                                                            | Peor tiempo de respuesta para el código de tarea                                                                          | Estabilidad a los cambios                                                  | Simplicidad                                                                       |
| ------------------------------ | ---------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------- | --------------------------------------------------------------------------------- |
| Round-Robin                    | Ninguna.                                                                                                               | Suma de todos los códigos de tareas.                                                                                      | Pobre.                                                                     | Muy simple.                                                                       |
| Round-Robin con interrupciones | Rutinas de interrupciones en orden de prioridad, entonces todo el código de tareas tienen el mismo orden de prioridad. | Tiempo de ejecución total para todos los códigos de tarea (más el tiempo de ejecución para las rutinas de interrupciones) | Bueno para las rutinas de interrupciones; pobre para las tareas de código. | Información compartida entre la rutina de interrupciones y el código de tareas.   |
| Function-queue-scheduling      | Rutinas de interrupciones en orden de prioridad, por lo tanto, el código de tareas también tiene orden de prioridad.   | Tiempo de ejecución para las funciones más largas.                                                                        | Relativamente bueno.                                                       | La información es compartida y debe ser escrita en el código de la función queue. |
| Real-time Operating system     | Rutinas de interrupciones en orden de prioridad, por lo tanto, el código de tareas también tiene orden de prioridad.   | Cero (más el tiempo de ejecución para las rutinas de interrupciones)                                                      | Muy bueno.                                                                 | Más complejo.                                                                     |

## Tener en cuenta

* Tienen datos compartidos entre rutinas de interrupciones y el código de tarea.
* Cuenta con tiempos largos de respuesta, si justo ocurre el evento inmediatamente después de que se paso el polling del flag.
* En el proyecto, no hay tiempos de procesamiento demasiados elevados en respuesta a eventos.

## A futuro

En el caso que más adelante se mejore el proyecto, agregando sensonres para la detección de obstáculos o para realizar un comportamiento simple, sigue siendo uno con pocos dispositivos. Por lo tanto, esta arquitectura sigue siendo útil.
