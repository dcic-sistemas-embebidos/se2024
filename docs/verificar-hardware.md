# Verificación del Hardware


## Test Driven Development (TDD) 
Utilizar esta técnica nos mejora la calidad del software desarrollado. Brinda un diseño enfocado a las necesidades, contando con un diseño más simple. Permite una mayor productividad y un menor tiempo invertido en depuración. 

### 1. Tipos de prueba: cuáles son las tareas que se realizan para evaluar el sistema.
* *Funcionalidad*: hace lo que tiene que hacer
* *Interfaces*: la comunicación con otros sistemas
* *Carga y estrés*: llevarlo al límite si el proyecto lo requiere
* *Seguridad*

### 2. Nivel de prueba: quién realiza la prueba 

## F.I.R.S.T
* *Fast*: los test deben correr rápido.
* *Isolated*: no debe haber dependencia entre los test.
* *Repeteable*: Se debe poder repetir el test n veces y obtener el mismo resultado.
* *Selft-checking*: el propio test debe determinar si el resultado es correcto o no.
* *Timely*: se deben escribir al mismo tiempo que el código de producción.

## Unit test: 
Es un paradigma que establece que primero se escriben las pruebas y luego el código que hace que las pruebas sean exitosas. Estas pruebas se pueden implementar con lenguajes estructurados, de objetos o assembler.

Contamos con los lenguajes:

### 1. *C*:
* Unity: [ThrowTheSwitch/Unity: Simple Unit Testing for C (github.com)](https://github.com/ThrowTheSwitch/Unity)
(Es compatible con varios compiladores)
* Ejemplo en ESP32: [esp-idf/examples/system/unit_test at master · espressif/esp-idf (github.com)](https://github.com/espressif/esp-idf/tree/master/examples/system/unit_test)
* CMock para lo generado en Unity: [ThrowTheSwitch/CMock: CMock - Mock/stub generator for C (github.com)](https://github.com/ThrowTheSwitch/CMock)
* CException: [ThrowTheSwitch/CException: Lightweight exception implementation for C (github.com)](https://github.com/throwtheswitch/cexception)

### 2. *Ruby*:
* Ceedling: [ThrowTheSwitch/Ceedling: Ruby-based unit testing and build system for C projects (github.com)](https://github.com/ThrowTheSwitch/Ceedling)
(Integra todo lo de arriba)

### 3. *C++:*
* CPPUnit: [cppunit/cppunit: CPlusPlusUnit - Tiny single source file C++ Unit Testing TDD framework with the output message format like Python unittest http://cppunit.github.io](https://github.com/Cppunit/cppunit)

_Ambas opciones son mas apropiadas para pruebas de software con el que podemos asegurar calidad y estabilidad._

### 4. *Python:*
* CocoTB: [Quickstart Guide — cocotb 1.9.0 documentation](https://docs.cocotb.org/en/stable/quickstart.html)

_Es la opción cuando se tiene que validad y verificar diseños de hardware, especialmente a nivel de ciclos de reloj._

## Caso de prueba:
Entorno VSC con PlatformioIO que cuenta con Unity: https://docs.platformio.org/en/latest/integration/ide/vscode.html#installation

Dispositivo Arduino UNO: https://docs.platformio.org/en/latest/tutorials/core/unit_testing_blink.html

## Conclusión
Si el proyecto necesita verificar hardware utilizaremos _CocoTB_ pero, en el caso que se necesiten realizar pruebas de software dependerá del grupo con el lenguaje que se sienta más cómodo trabajar. 
