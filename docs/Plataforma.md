## **Elección de la plataforma**

Para el presente proyecto elegimos la plataforma ESP 32, ya que, tiene un consumo moderadamente bajo; soporta entornos de desarrollo como Arduino IDE y PlatformIO; mayor capacidad de computo que arduino. Además, tiene un consumo menor que  Raspberry Pi y se sigue fabricando a diferencia de galileo que se ha descontinuado, lo que limita su uso en nuevos proyectos. 
A continuación se darán las características de cada una de las plataformas, sus ventajas y desventajas. 

### Características de las posibles plataformas a utilizar

#### Arduino UNO

El Arduino Uno es una placa de microcontrolador de código abierto basado en el microchip
ATmega328P y desarrollado por Arduino.cc.
La placa está equipada con conjuntos de pines de E/S digitales y analógicas que pueden
conectarse a varias placas de expansión y otros circuitos. Algunas otras características:

- Microcontrolador: ATMega328P.
- Velocidad de reloj: 16 MHz.
- Voltaje de trabajo: 5V.
- Voltaje de entrada: 7,5 a 12 voltios.
- Pinout: 14 pines digitales (6 PWM) y 6 pines analógicos.
- 1 puerto serie por hardware.
- Memoria: 32 KB Flash (0,5 para bootloader), 2KB RAM y 1KB Eeprom.
- Corriente DC por Pin de E/S: 20 mA.
- Corriente CC para Pin de 3.3V: 50 mA.
- No posee Bluetooth incorporado.

#### ESP32

Diseñado para ser escalable y adaptable. La integración de Bluetooth, Bluetooth LE y Wi-Fi garantiza que se pueda abordar una amplia gama de aplicaciones y que el módulo sea polivalente: el uso de Wi-Fi permite un gran alcance físico y la conexión directa a Internet a través de un router Wi-Fi, mientras que el uso de Bluetooth permite al usuario conectarse cómodamente al teléfono o emitir balizas de baja energía para su detección. Algunas otras características son:

- Voltaje de alimentación: 3.3 V (máx 3.6 V).
- Consumo de corriente:
   - Tipíco: 80 mA.
   - Sleepmode: 5 uA.
- Frecuencia del reloj: 40 MHz.
- Procesador Tensilica Xtensa 32bits LX6 hasta 240MHz.
- Memoria ROOM: 448 KB.
- Memoria SRAM: 520 KB.
- Memoria Flash: 16 MB.
- RTC slow SRAM: 8 KB.
- RTC fast SRAM: 8 KB.
- eFuse: 1 Kbit.
- WiFi:
   - Protocolos: 802.11 b/g/n (802.11n @150 Mbps), A-MPDU and A-MSDU.
   - Rango de frecuencia: 2.4 GHz ~ 2.5 GHZ.
   - Potencia transmisión Tx: 14 dBm máx.
   - Sensibilidad: -69 dBm ~ -98 dBm.
   - Certificado: Wi-Fi Alliance.
- Bluethoot:
   - Protocolos: Bluetooth v4.2 BR/EDR y BLE.
   - Recepción: NZIF @–97 dBm.
   - Transmisión: Class-1, class-2 y class-3.
   - AFH.
   - Audio CVSD and SBC.
- Interfaces: SD card, UART, SPI, SDIO, I2C, LED PWM, Motor PWM, I2S, IR, pulse counter, GPIO,Sensor táctil capacitivo, ADC, DAC.
- Sensor Hall integrado.
- Antena integrada (onboard).
- Rango de temperatura: -40 °C ~ +85 °C.
- Dimensiones: 18 mm x 25.5 mm x 3.10 mm.

#### Raspberry PI

Consiste en una placa base que soporta distintos componentes de un ordenador como un procesador ARM de hasta 1500 MHz, un chip gráfico y una memoria RAM de hasta 8 GB. Algunas otras características son:

- Gracias a sus puertos y entradas, permite conectar dispositivos periféricos. Por ejemplo, una pantalla táctil, un teclado e incluso un televisor.
- Contiene un procesador gráfico VideoCoreIV, con lo que permite la reproducción de vídeo -incluso en alta definición-
- Permite la conexión a la red a través del puerto de Ethernet, y algunos modelos permiten conexión Wifi y Bluetooth.
- Consta de una ranura SD que permite instalar, a través de una tarjeta microSD, sistemas operativos libres.
- Generalmente, está recomendada la instalación de Raspberry Pi OS -anteriormente, Raspbian-. Sin embargo, también es compatible con Linux y una versión específica de Windows -Windows 10 IoT-.
- Alimentación: Como máximo, 15.3 W (5.1 Volt. / 3 Amp.)

#### Galileo

Galileo es la primera placa base en la arquitectura Intel® diseñada para ser compatible con hardware y software con shields Arduino diseñados para el Uno R3. Algunas otras características son:
- CPU x86
- Pin de Arduino Uno Rev3
- Host USB
- Puerto mini PCI-express
- Tarjeta Micro SD
- Muchos shields Arduino son compatibles
- Procesador Intel SoC Quark X1000 Aplicación. 400MHz, Pentium de 32 bits
- 16 KBytes en el chip caché L1
- 512 Kbytes de en el chip SRAM incrustado
- Fácil de programar: hilo individual, de un solo núcleo, velocidad constante
- ACPI estados de reposo compatible con CPU
- Un reloj de tiempo real integrado (RTC), con una batería de 3V "tipo botón" opcional para la operación en ciclos.
- 256MB DDR3 DRAM
- PSoC (sistema programable en el chip) de Cypress, el chip de expansión E / S I2C controlado
- 10/100 Mbit conector Ethernet
- Conector USB 2.0 Host
- Conector USB 2.0 Cliente
- 8 MB de Flash
- Cabezal 10-pin estándar JTAG para depuración
- I2C, SPI, UART, ICSP
- Hay dos botones:
   - Botón Reiniciar: para reiniciar el procesador
   - Botón Restablecer: para restablecer el boceto y los escudos adjuntos

### Ventajas y desventajas de cada una de las placas

#### Arduino UNO

##### Ventajas:

- **Consumo Energético:** Bajo consumo energético, ideal para proyectos que requieren eficiencia energética.
- **Facilidad de Testeo:** Muy fácil de testear y depurar, especialmente para principiantes. Cuenta con una gran cantidad de ejemplos y bibliotecas preexistentes.
- **Comunidad:** Gran comunidad y recursos en línea, lo que facilita encontrar soluciones a problemas comunes.
- **Costo:** Relativamente barato, ideal para proyectos simples.

##### Desventajas:

- **Capacidad de Procesamiento:** Limitado en términos de procesamiento y memoria (8- bit MCU con 2 KB de RAM), lo que lo hace inadecuado para aplicaciones más complejas.
- **Conectividad:** Sin conectividad Wi-Fi o Bluetooth incorporada, requiere módulos adicionales para estas funcionalidades.


#### ESP32

##### Ventajas:

- **Consumo Energético:** Moderadamente bajo con modos de bajo consumo energético (deep sleep), adecuado para proyectos IoT.
- **Facilidad de Testeo:** Relativamente fácil de testear, con un entorno de desarrollo similar a Arduino. Soporta entornos de desarrollo como Arduino IDE y PlatformIO.
- **Conectividad:** Conectividad Wi-Fi y Bluetooth integrada, lo que lo hace ideal para aplicaciones IoT.
- **Capacidad de Procesamiento:** Mucho más potente que el Arduino UNO (32-bit dualcore, hasta 240 MHz), con más memoria RAM y almacenamiento.

##### Desventajas:

- **Complejidad:** Más complejo que el Arduino UNO, lo que puede ser un desafío para principiantes.
- **Comunidad:** Aunque la comunidad está creciendo, no es tan grande como la de Arduino UNO.

#### Raspberry Pi

##### Ventajas:

- **Capacidad de Procesamiento:** Mucho más potente, con capacidad de ejecutar un sistema operativo completo (Linux), lo que lo hace adecuado para proyectos complejos y aplicaciones que requieren mucho procesamiento.
- **Facilidad de Testeo:** Puede testearse con un entorno de desarrollo completo en la propia plataforma, lo que facilita el desarrollo de software más avanzado.
- **Conectividad:** Conectividad Ethernet, Wi-Fi y Bluetooth (en modelos más recientes), ideal para proyectos que requieren comunicación intensiva.
- **Versatilidad:** Soporta una amplia variedad de lenguajes de programación y aplicaciones.

##### Desventajas:

- **Consumo Energético:** Mucho más alto en comparación con Arduino y ESP32, lo que lo hace menos adecuado para aplicaciones que requieren bajo consumo.
- **Costo:** Más caro que las otras plataformas, especialmente en proyectos donde no se necesita tanta potencia.
- **Complejidad:** Mucho más complejo de configurar y usar, especialmente para principiantes.


#### Intel Galileo
##### Ventajas:

- **Capacidad de Procesamiento:** Ofrece una potencia intermedia con un procesador Intel Quark x86, lo que lo hace compatible con software más avanzado y con una arquitectura más abierta que Arduino.
- **Conectividad:** Tiene conectividad Ethernet integrada y soporte para shields de Arduino, lo que facilita su integración en proyectos ya existentes.
- **Compatibilidad:** Compatible con las bibliotecas y shields de Arduino, lo que permite reutilizar mucho del ecosistema de Arduino.

##### Desventajas:

- **Consumo Energético:** Mayor que Arduino y ESP32, aunque menor que Raspberry Pi.
- **Comunidad:** Comunidad más pequeña y menos soporte comparado con Arduino y Raspberry Pi.
- **Disponibilidad:** Ya no es tan fácil de conseguir, ya que Intel descontinuó la plataforma, lo que limita su uso en nuevos proyectos.
