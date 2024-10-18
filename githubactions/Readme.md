# GitHub Actions para Integración Continua

GitHub Actions es una plataforma de integración continua y entrega continua (CI/CD) que permite automatizar flujos de trabajo directamente en tu repositorio de GitHub. Puedes usar GitHub Actions para construir, probar y desplegar tu código cada vez que se realiza un cambio en el repositorio.

## Conceptos Clave

1. **Flujos de Trabajo (Workflows)**
   - Son procesos automatizados definidos en archivos YAML dentro del directorio `.github/workflows` de tu repositorio.
   - Los flujos de trabajo se pueden activar por diferentes eventos, como push, pull request, o en un horario específico.

2. **Jobs**
   - Un flujo de trabajo puede estar compuesto por uno o más jobs.
   - Los jobs se ejecutan en entornos de ejecución (runners) y pueden ejecutarse en paralelo o secuencialmente, dependiendo de la configuración.

3. **Steps**
   - Cada job se compone de steps (pasos), que son comandos o acciones individuales a ejecutar dentro del job.
   - Los steps pueden incluir comandos shell, scripts personalizados o acciones reutilizables.

4. **Actions**
   - Las acciones son unidades reutilizables de código que pueden ser combinadas en tus workflows.
   - Puedes utilizar acciones predefinidas desde el GitHub Marketplace o escribir tus propias acciones personalizadas.

5. **Runners**
   - Los runners son servidores que ejecutan tus jobs.
   - GitHub proporciona runners hospedados en la nube, o puedes utilizar runners auto-hospedados en tu propia infraestructura.

## Ejemplo de Flujo de Trabajo para Integración Continua

A continuación, un ejemplo de archivo YAML para un flujo de trabajo de integración continua que muestra un mensaje:

```yaml
name: Integracion Continua

 on:
   push:
    branches:
      - main
  #pull_request:
  # branches:
  #  - main

jobs:
  build:
    runs-on: ubuntu-latest

    steps:
    - name: Echo message
      run: |
        echo "Bienvenido Ingenieros 2024"

```

***Name***: Define el nombre del flujo de trabajo como "Integracion Continua". Este nombre aparece en la interfaz de GitHub Actions y ayuda a identificar el flujo de trabajo en la lista de workflows.

***On***: Especifica los eventos que desencadenan la ejecución del flujo de trabajo.
- push:: El flujo de trabajo se activa cada vez que se realiza un push a la rama main.
- branches:: Define que el flujo de trabajo solo se activará para push en la rama main.
- pull_request: (comentado): Esta sección está comentada, lo que significa que actualmente está inactiva. Si se descomentara, el flujo de trabajo también se activaría en eventos de pull_request hacia la rama main.

***jobs***: Define los trabajos (jobs) que se ejecutarán como parte del flujo de trabajo.
- build:: Es el nombre del job. Puede ser nombrado de cualquier manera que refleje la tarea del job.
- runs-on:: Especifica el entorno en el que se ejecutará el job. En este caso, ubuntu-latest indica que el job se ejecutará en un runner con la última versión de Ubuntu.


***Steps***: Define una lista de pasos (steps) que se ejecutarán dentro del job.
- name: Echo message: Asigna un nombre al paso, en este caso, "Echo message". Este nombre se muestra en la interfaz de GitHub Actions para identificar el paso.
- run:: Especifica los comandos que se ejecutarán en este paso.
        echo "Bienvenido Ingenieros 2024": Ejecuta el comando shell echo, que imprime el mensaje "Bienvenido Ingenieros 2024" en la consola.