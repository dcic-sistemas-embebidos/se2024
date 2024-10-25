#include "notifier_interface.h"

// Configura las salidas de las notificaciones
int setup(){
    //Llama al setup del display los leds
}

// Notificaciones
void start(){
    //Envia mensaje de inicio para el display y los leds
}
void reset(){
    //Muestra algun mensaje o codigo sobre el reinicio
}
void powerOff(){
    //Envia mensaje de apagado sin errores
}
void conection(char type){
    switch ( type )
    {
        case 'A':
        // Conexion establecida
        break;
        case 'B':
        // Perdida de conexion
        break;
        case 'C':
        // Conexion Finalizada
        break;
    }
}
void motor_move(int type){
    switch ( type )
    {
        case 'A':
        // Izquierda
        break;
        case 'W':
        // Avanzar
        break;
        case 'S':
        // Parar
        break;
        case 'D':
        // Derecha
        break;
    }
}
void low_battery(){
    // Envia mesaje de poca bateria
}