# Contribuir al proyecto de Robot de Tracción Diferencial

## Para contribuir al proyecto

Hay tres tipos de contribución que se pueden hacer al proyecto:

- Código.
- Documentos.
- Revisiones.

### Contribuir con código y documentos

Los pasos para contribuir son los siguientes:

1. Acceder al tablero del [proyecto en Asana](https://app.asana.com/0/1208084116866643/1208084118983638).
2. Elegir un ticket del tablero que no este asignado. Si el aporte que se desea
   hacer no esta en el tablero, crear un ticket. Supongamos que el ticket
es el RTD-000.
3. Mover el ticket a la columna "En progreso".
4. Clonar el repositorio (si no se ha clonado previamente).
```bash
git clone git@github.com/dcic-sistemas-embebidos/se2024
```
5. Crear una rama con el nombre del ticket.
```bash
git checkout -b RTD-000
```
6. Trabajar en el aporte.
7. Hacer un commit con los cambios realizados.
```bash
git add .
git commit -m "RTD-000: Comentario sobre los cambios realizados"
```
8. Subir los cambios al repositorio.
```bash
git push origin RTD-000
```
9. Crear un Pull Request (PR) en GitHub.
10. Copiar el link al PR y pegarlo en el ticket de Asana en el campo _Pull
   Request_.
11. Mover el ticket a la columna "Revisión".
12. Esperar a que el PR sea revisado por un par.
13. Realizar los cambios solicitados en el PR y repetir desde el paso 6.
14. Mover el ticket a la columna "Aceptación".
15. Esperar a que el PR sea aprobado por un docente.
16. Una vez aprobado, realizar el _merge_ del PR.
17. Completado el merge, mover el ticket a la columna "Completo".

## Organización

Se utilizara la metodología Scrum con sprints de dos semanas, se hara un
control de avance todos los lunes, miércoles y viernes. Sesión de refinamiento el
primer viernes del sprint. Planificación del próximo sprint y retrospectiva el
último viernes del sprint.

## Metodología de trabajo

La metodología de trabajo será Test Driven Development, es una metodología de
desarrollo de software que se enfoca en escribir pruebas automatizadas antes de
escribir el código real. El proceso comienza con la creación de una prueba que
describe una funcionalidad o comportamiento esperado

## Branching model

Se utiliza _trunk-based development_ contra la rama _main_.

- Una Rama Principal: En TBD, todo el trabajo se realiza en una única rama
  principal (a menudo llamada "trunk", "main" o "master"). En lugar de crear
ramas de larga duración para nuevas características o correcciones, los
desarrolladores integran sus cambios directamente en esta rama principal.

- Integración Continua: Los cambios se integran con frecuencia, idealmente
  varias veces al día. Esto asegura que el código en la rama principal esté
siempre en un estado funcional y que los conflictos se resuelvan de manera
temprana.

- Despliegue Continuo: Como el código en la rama principal siempre está en un
  estado funcional, es más fácil automatizar el despliegue continuo. Esto
significa que el software puede ser desplegado a producción de forma más
frecuente y confiable.

- Pequeños Cambios Incrementales: En lugar de hacer cambios grandes en una rama
  separada, los desarrolladores realizan cambios pequeños y frecuentes. Esto
reduce el riesgo de conflictos y facilita la revisión de código.

- Colaboración y Revisión Rápida: Dado que el trabajo se realiza en la misma
  rama, los equipos deben colaborar estrechamente y revisar el código de manera
continua. Esto promueve una alta calidad del código y una integración más
fluida.

## GitFlow

![gitflow](gitflow.jpg)

Por cada ticket creado, se crea una branch con el nombre del ticket. Al
finalizar la branch, se crea un PR contra main.

Los tickets se identificaran con RTD-XXX, Robot de Tracción Diferencial seguido
del numero de ticket.

Al realizar un commit en el comentario primero se agregara el nombre del ticket
luego algun comentario relacionado a los cambios.

## Comandos utiles

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


