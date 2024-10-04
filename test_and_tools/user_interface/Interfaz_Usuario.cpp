#include <Arduino.h>
#include <LiquidCrystal.h>
#include <string.h>
#include <Preferences.h>

// Definicion de leds
#define LedAmarillo 15
#define LedVerde 2
#define LedRojo 4

// Definicion del display
LiquidCrystal lcd(22, 23, 21, 19, 18, 5); // select the pins used on the LCD panel

// Definicion del pulsador
int pin_pulsador = 13; // Pin del pulsador

// Definicion para el uso de la memoria NVS
Preferences preferences;

String codigoobtenido= "";
String macobtenida= "";

// Metodo para guardar los datos; direccion MAC y codigo de seguridad
void GuardarDatos(String direccionMAC, String codigo){
  preferences.begin("robot", false);
  preferences.putString("direcmac", direccionMAC);
  preferences.putString("codseg", codigo);
  preferences.end();
}

// Metodo para obtener la mac
String ObtenerMAC(){
  preferences.begin("robot", false);
  String MAC= preferences.getString("direcmac","");
  preferences.end();
  return MAC;
}

// Metodo para ontener el codigo de seguridad
String ObtenerCodigo(){
  preferences.begin("robot", false);
  String codigo= preferences.getString("codseg","");
  preferences.end();
  return codigo;
}

void setup() {  
  Serial.begin(115200);
  pinMode(pin_pulsador, INPUT_PULLDOWN);
  pinMode(LedAmarillo, OUTPUT);
  pinMode(LedVerde, OUTPUT);
  pinMode(LedRojo, OUTPUT);

  lcd.begin(16, 2); // start the library
  lcd.setCursor(0,0); // set the LCD cursor position
  lcd.print("Apretar pulsador"); // print a simple message on the LCD  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  codigoobtenido= ObtenerCodigo();
  macobtenida= ObtenerMAC();
  if(codigoobtenido == "" || macobtenida == ""){
    Serial.println("No existe una mac guardada");
    digitalWrite(LedRojo, HIGH);
    delay(5000);
    digitalWrite(LedRojo, LOW);
  }
  else{
    Serial.print("Mac: ");
    Serial.println(macobtenida);
    Serial.print("Codigo: ");
    Serial.println(codigoobtenido);
    digitalWrite(LedVerde, HIGH);
    delay(5000);
    digitalWrite(LedVerde, LOW);
  }
   

  digitalWrite(LedAmarillo, HIGH);
  delay(1000);
  digitalWrite(LedAmarillo, LOW);
  digitalWrite(LedVerde, HIGH);
  delay(1000);
  digitalWrite(LedVerde, LOW);
  digitalWrite(LedRojo, HIGH);
  delay(1000);
  digitalWrite(LedRojo, LOW);
  
  lcd.setCursor(9,1); // move cursor to second line "1" and 9 spaces over
  lcd.print(millis()/1000); // display seconds elapsed since power-up
  
    
  int v_state = digitalRead(pin_pulsador);
  if (v_state == HIGH){
    Serial.println("Pulsado!");
    lcd.setCursor(0,1); // move to the begining of the second line
    lcd.print("Pulsado..");
    digitalWrite(LedAmarillo, HIGH);
    digitalWrite(LedVerde, HIGH);
    digitalWrite(LedRojo, HIGH);
    delay(1000);
    digitalWrite(LedAmarillo, LOW);
    digitalWrite(LedVerde, LOW);
    digitalWrite(LedRojo, LOW);
    delay(100);
    GuardarDatos("", "");
    
  }  
  else{
    lcd.setCursor(0,1); // move to the begining of the second line
    lcd.print("         ");    
    GuardarDatos("00:01:32:63:44:95", "codigo de seguridad");
  }

 }

