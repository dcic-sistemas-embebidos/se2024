#include <unity.h>
#include <fakeit.hpp>
#include <Memoria.h>
#include <Preferences.h>

using namespace fakeit;

Mock<Preferences> preferencesMock;



void setUp(void){}

void tearDown(void){}

void test_GuardarDatos(void){

    When(Method(preferencesMock, begin)).AlwaysReturn();
    When(Method(preferencesMock, end)).AlwaysReturn();
    When(Method(preferencesMock, putString)).AlwaysReturn();   
    set_preferences(&preferencesMock.get()); 
    GuardarDatos("address", "codigo");
    Verify(Method(preferencesMock, begin)).Exactly(1);
    Verify(Method(preferencesMock, putString)).Exactly(2);
    Verify(Method(preferencesMock, end)).Exactly(1);
    Verify(Method(preferencesMock, getString)).Exactly(0);
}

void test_ObtenerMac(void){
     When(Method(preferencesMock, begin)).AlwaysReturn();
     When(Method(preferencesMock, getString)).AlwaysReturn();
     When(Method(preferencesMock, end)).AlwaysReturn();
     set_preferences(&preferencesMock.get());
     String mac= ObtenerMAC();
     Verify(Method(preferencesMock, getString)).Exactly(1);
     Verify(Method(preferencesMock, putString)).Exactly(2);
     Verify(Method(preferencesMock, begin)).Exactly(2);
     Verify(Method(preferencesMock, end)).Exactly(2);     
}


void test_ObtenerCodigo(void){
     When(Method(preferencesMock, begin)).AlwaysReturn();
     When(Method(preferencesMock, getString)).AlwaysReturn();
     When(Method(preferencesMock, end)).AlwaysReturn();
     set_preferences(&preferencesMock.get());
     String cod= ObtenerCodigo();
     Verify(Method(preferencesMock, getString)).Exactly(2);
     Verify(Method(preferencesMock, putString)).Exactly(2);
     Verify(Method(preferencesMock, begin)).Exactly(3);
     Verify(Method(preferencesMock, end)).Exactly(3); 
}

int main(int argc, char **argv){
    UNITY_BEGIN();

    RUN_TEST(test_GuardarDatos);
    RUN_TEST(test_ObtenerMac);
    RUN_TEST(test_ObtenerCodigo);

    UNITY_END();

    return 0;
}