#ifndef TEST_HW_INTERFAZ_H
#define TEST_HW_INTERFAZ_H

void testEntrada();
void testSalida();
void _testLed(int pin_led);
void _testPulsador(int pin_pulsador);
void _testLCD(String txt,int boton_lcd);
void _testLCDButtons(int pin_boton_lcd);
void _testLCDTxt(String txt);

#endif