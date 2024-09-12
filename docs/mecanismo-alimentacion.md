## Mecanismo de alimentación del robot

A la hora de definir como alimentaremos nuestro robot diferencial, debemos considerar el voltaje necesario que requieren los motores y el ESP32 para funcionar de manera óptima.  
También tenemos que tener en cuenta los consumos de corriente de los componentes para mantener el robot en funcionamiento por un buen periodo de tiempo.  

### Cálculo de voltaje
- Motores: 3V a 6V
- ESP32: 5V por entrada Vin (Utiliza un reductor de voltaje interno para bajarlo a 3.3V)

### Cálculo de corriente
- Motor: Consumo nominal 140mA x 2 = **280mA**
- Driver: **36mA**
- ESP32: **130mA** (Utilizando el Bluetooth)

  **Total:** 280mA + 36mA + 130mA = 446mA ~ **450mA**

Se utilizarán 5 pilas AA de tipo Ni-Mh, las cuales proveen 1.2V cada una y tienen una capacidad de 2700mAh. 
Conectando las mismas en serie obtendremos 6V (suficientes para alimentar los motores) y 2700mAh totales, permitiéndonos utilizar el robot por aproximadamente 6 horas (2700/450).  

Debemos agregar un [reductor de voltaje](https://articulo.mercadolibre.com.ar/MLA-901287123-fuente-lm2596-step-down-dc-dc-125-35v-3a-arduino-led-stock-_JM#polycard_client=search-nordic&position=4&search_layout=grid&type=item&tracking_id=3ff69e03-45cf-4475-ae97-fb8b40f66e3a) (fuente step-down) para bajar de 6V a 5V y que el ESP32 pueda trabajar a valores óptimos.
