# Elección del Toolchain

**Elección del toolchain, Sistemas Embebidos 2024.**  
*Bautista Graff Bohn*

## ¿Qué es el toolchain?

Conjunto de programas utilizados para desarrollar software, que se encuentran encadenados por fases específicas.  
Se les llama toolchain porque tradicionalmente la salida de una herramienta era la entrada de la otra, formando una cadena. Actualmente, este término se utiliza para el conjunto de herramientas, cumplan o no esta condición.

Debido a la elección de utilizar el microchip ESP32, que integra conectividad Wi-Fi y Bluetooth, el toolchain que mejor se adapta es: **Espressif IoT Development Framework (ESP-IDF)**, el toolchain nativo para este microchip.

ESP-IDF puede ser utilizado tanto en sistemas operativos Windows, Linux y macOS.

## Componentes Principales del Toolchain:

1. **GCC para Xtensa (esp32-esp-elf-gcc):** Compilador para el procesador Xtensa del ESP32.
2. **CMake:** Herramienta para la configuración y generación de archivos de construcción.
3. **Ninja:** Herramienta de construcción rápida que coordina el proceso de compilación.
4. **OpenOCD (Open On-Chip Debugger):** Actúa como un servidor de depuración y es el intermediario entre la computadora (donde se ejecuta GDB) y el microcontrolador ESP32. Se encarga de la comunicación directa con el hardware mediante JTAG o interfaces similares, permitiendo controlar el microcontrolador a bajo nivel.
5. **Python y Scripts de Espressif:** Scripts que facilitan la gestión del proceso de compilación y flasheo.

## IDE Recomendadas

La IDE puede ser tanto **Eclipse** como **Microsoft Visual Studio Code**, aunque la última presenta ciertas ventajas sobre Eclipse, como por ejemplo:

- **Interfaz Modernizada y Personalizable:** VS Code tiene una interfaz moderna, ligera y rápida comparada con Eclipse. Además, su sistema de extensiones permite personalizar el entorno fácilmente para diferentes lenguajes y herramientas.
- **Extensión PlatformIO:** PlatformIO es una extensión poderosa en VS Code que simplifica mucho el desarrollo para el ESP32. Ofrece integración con ESP-IDF, gestión de bibliotecas, y un sistema de configuración intuitivo. También permite cambiar entre proyectos basados en ESP-IDF y Arduino sin problemas.
- **Depuración Integrada:** VS Code soporta depuración directa utilizando GDB y OpenOCD, con opciones visuales para inspeccionar variables, ver puntos de ruptura y analizar la pila de llamadas.

## Conclusión

Frente a la elección de trabajar con el microchip ESP32, fue sencillo seleccionar el toolchain a utilizar, ya que **ESP-IDF** es el toolchain desarrollado por Espressif, la empresa creadora del ESP32.  
ESP-IDF proporciona un control total sobre el hardware, brinda acceso directo a las capacidades del microchip (gestión de Wi-Fi, Bluetooth y periféricos integrados), también cuenta con una documentación extensa, es flexible y escalable (funciona para proyectos tanto de pequeña como de gran escala) e incluye herramientas como GDB y OpenOCD para la depuración tanto a nivel de software como a nivel de hardware.

## Referencias

- [Espressif IoT Development Framework (ESP-IDF)](https://www.espressif.com/en/products/sdks/esp-idf)
