# se2024
Primer Proyecto de Sistemas Embebidos2024

##### Proyecto
	 Robot de dos ruedas de tracción diferencial con sensores controlado por Bluetooth
###### Organización
	Se utilizara la metodología Scrum con sprints de dos semanas, se hara un control de avance todos los lunes, miércoles y viernes. Sesión de refinement el primer viernes del sprint. Planificación del próximo sprint y retrospectiva el último viernes del sprint.
###### Metodología de trabajo
	La metodología de trabajo será Test Driven Development, es una metodología de desarrollo de software que se enfoca en escribir pruebas automatizadas antes de escribir el código real. El proceso comienza con la creación de una prueba que describe una funcionalidad o comportamiento esperado
###### Branching model
	Se utiliza trunk-based development.
Principios del Trunk Based Development
- Una Rama Principal: En TBD, todo el trabajo se realiza en una única rama principal (a menudo llamada "trunk", "main" o "master"). En lugar de crear ramas de larga duración para nuevas características o correcciones, los desarrolladores integran sus cambios directamente en esta rama principal.

- Integración Continua: Los cambios se integran con frecuencia, idealmente varias veces al día. Esto asegura que el código en la rama principal esté siempre en un estado funcional y que los conflictos se resuelvan de manera temprana.

- Despliegue Continuo: Como el código en la rama principal siempre está en un estado funcional, es más fácil automatizar el despliegue continuo. Esto significa que el software puede ser desplegado a producción de forma más frecuente y confiable.

- Pequeños Cambios Incrementales: En lugar de hacer cambios grandes en una rama separada, los desarrolladores realizan cambios pequeños y frecuentes. Esto reduce el riesgo de conflictos y facilita la revisión de código.

- Colaboración y Revisión Rápida: Dado que el trabajo se realiza en la misma rama, los equipos deben colaborar estrechamente y revisar el código de manera continua. Esto promueve una alta calidad del código y una integración más fluida.

##### GitFlow
![[Pasted image 20240825204553.png]]

Por cada ticket creado, se crea una branch con el nombre del ticket. Al finalizar la branch, se crea un PR contra main.
Los tickets se identificaran con RTD-XX, Robot de Tracción Diferencial seguido del numero de ticket.
Al realizar un commit en el comentario primero se agregara el nombre del ticket luego algun comentario relacionado a los cambios.

###### Comandos utiles
Creacion de nueva rama
```
	git checkout -b <ticket-id>
```
Añadimos todos los archivos para el commit

```
	git add .
```

Hacemos el primer commit

```
	git commit -m "<ticket-id> Comentario sobre los cambios realizados"
```

subimos al repositorio

```
	git push origin <ticket-id>
```

## Presentación de los diferentes componentes

https://docs.google.com/document/d/1RHFMF1OluXj8oUJZgIbuiNv1oARzYT1C4UHMbYxQ5N0/edit?usp=sharing
