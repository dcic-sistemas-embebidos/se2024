#include <unity.h>
#include <fakeit.hpp>
#include <Memoria.h>
#include <Preferences.h>

using namespace fakeit;

Mock<Preferences> preferencesMock;

void setUp(void){}

void tearDown(void){}

void test_guardardatos(void){

    When(Method(preferencesMock, begin)).AlwaysReturn();
    When(Method(preferencesMock, end)).AlwaysReturn();
    When(Method(preferencesMock, putString)).AlwaysReturn();   
    set_preferences(&preferencesMock.get()); 
    guardardatos("address", "codigo");
    Verify(Method(preferencesMock, begin)).Exactly(1);
    Verify(Method(preferencesMock, putString)).Exactly(2);
    Verify(Method(preferencesMock, end)).Exactly(1);
    Verify(Method(preferencesMock, getString)).Exactly(0);
}

void test_obtenermac(void){
     When(Method(preferencesMock, begin)).AlwaysReturn();
     When(Method(preferencesMock, getString)).AlwaysReturn();
     When(Method(preferencesMock, end)).AlwaysReturn();
     set_preferences(&preferencesMock.get());
     String mac= obtenermac();
     Verify(Method(preferencesMock, getString)).Exactly(1);
     Verify(Method(preferencesMock, putString)).Exactly(2);
     Verify(Method(preferencesMock, begin)).Exactly(2);
     Verify(Method(preferencesMock, end)).Exactly(2);     
}


void test_obtenercodigo(void){
     When(Method(preferencesMock, begin)).AlwaysReturn();
     When(Method(preferencesMock, getString)).AlwaysReturn();
     When(Method(preferencesMock, end)).AlwaysReturn();
     set_preferences(&preferencesMock.get());
     String cod= obtenercodigo();
     Verify(Method(preferencesMock, getString)).Exactly(2);
     Verify(Method(preferencesMock, putString)).Exactly(2);
     Verify(Method(preferencesMock, begin)).Exactly(3);
     Verify(Method(preferencesMock, end)).Exactly(3); 
}

int main(int argc, char **argv){
    UNITY_BEGIN();

    RUN_TEST(test_guardardatos);
    RUN_TEST(test_obtenermac);
    RUN_TEST(test_obtenercodigo);

    UNITY_END();

    return 0;
}
