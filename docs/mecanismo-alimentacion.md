## Mecanismo de alimentación del robot

A la hora de definir como alimentaremos nuestro robot diferencial, consideraremos el voltaje necesario que requieren los motores y el ESP32 para funcionar de manera óptima.  
También tendremos en cuenta los consumos de corriente de los componentes para mantener el robot en funcionamiento por un buen periodo de tiempo.  

### Cálculo de voltaje
- Motores: 3V a 6V
- ESP32: 5V a 12V por entrada **Vin** (Utiliza el reductor de voltaje interno [AMS1117-3.3](https://www.alldatasheet.com/datasheet-pdf/view/205691/ADMOS/AMS1117-3.3.html) para bajarlo a 3.3V)

### Cálculo de corriente
- Motor: Consumo nominal 140mA x 2 = **280mA**
- Driver: **36mA**
- ESP32: **130mA** (Utilizando el Bluetooth)

  **Total:** 280mA + 36mA + 130mA = 446mA ~ **450mA**

Se utilizarán 4 pilas AA de tipo Ni-Mh para alimentar los dos motores y el driver, las cuales proveen 1.25V cada una y tienen una capacidad de 2500mAh.
Conectando las mismas en serie obtendremos 5V y 2500mAh totales, dándonos una autonomía de aproximadamente 8 horas (2500/316).

Por otro lado, utilizaremos una batería recargable de 9V para alimentar el ESP32. El voltaje se reducirá a 3.3V por medio del reductor de voltaje que tiene incorporado internamente.
