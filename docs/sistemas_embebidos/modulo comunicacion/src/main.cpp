#include <Arduino.h>
#include "BluetoothSerial.h"
#include "eleccionorder.h"
#include "messages.h"

char msg ='\0';


void setup() {
  bluetoothsetup();
}

void loop() {
  char msg=orderloop();
  order(msg);
  delay(50);

}