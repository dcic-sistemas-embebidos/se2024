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

    Verify(Method(preferencesMock, putString)).Exactly(2);
}

// void test_ObtenerMac(void){
//     When(Method(Preference_mock, Begin));
//     When(Method(Preference_mock, getString));
//     When(Method(Preference_mock, End));
//     Verify(Method(Preference_mock, Begin));
//     Verify(Method(Preference_mock, getString));
//     Verify(Method(Preference_mock, End));
// }

// void test_ObtenerCodigo(void){
//     When(Method(Preference_mock, Begin));
//     When(Method(Preference_mock, getString));
//     When(Method(Preference_mock, End));
//     Verify(Method(Preference_mock, Begin));
//     Verify(Method(Preference_mock, getString));
//     Verify(Method(Preference_mock, End));
    
// }

int main(int argc, char **argv){
    UNITY_BEGIN();

    RUN_TEST(test_GuardarDatos);
    // RUN_TEST(test_ObtenerMac);
    // RUN_TEST(test_ObtenerCodigo);

    UNITY_END();

    return 0;
}