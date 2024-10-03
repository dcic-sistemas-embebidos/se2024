
#include <unity.h>
#include <ArduinoFake.h>
#include "Memoria.h"

using namespace fakeit;

struct preference {
    virtual void Begin(void);
    virtual void End(void);
    virtual void putString(void); // variable, valor
    virtual void getString(void);  // variable
};

Mock<preference> Preference_mock;

void Begin (String, boolean){}
void End (void){}
void putString (String, String){}
void getString (String){
Preference_mock.get().getString();
}

void setUp(void){}

void tearDown(void){}


void test_GuardarDatos(void){
    When(Method(Preference_mock, Begin));
    When(Method(Preference_mock, putString));
    When(Method(Preference_mock, putString));
    When(Method(Preference_mock, End));
    Verify(Method(Preference_mock, Begin).Using("robot", "false"));
    Verify(Method(Preference_mock, putString).Using("mac", "01:34:65:95:36:56"));
    Verify(Method(Preference_mock, putString).Using("cod", "026565"));
    Verify(Method(Preference_mock, End));
}

void test_ObtenerMac(void){
    When(Method(Preference_mock, Begin));
    When(Method(Preference_mock, getString));
    When(Method(Preference_mock, End));
    Verify(Method(Preference_mock, Begin).Using("robot", "false"));
    Verify(Method(Preference_mock, getString).Using("mac"));
    Verify(Method(Preference_mock, End));
}

void test_ObtenerCodigo(void){
    When(Method(Preference_mock, Begin));
    When(Method(Preference_mock, getString));
    When(Method(Preference_mock, End));
    Verify(Method(Preference_mock, Begin).Using("robot", "false"));
    Verify(Method(Preference_mock, getString).Using("cod"));
    Verify(Method(Preference_mock, End));
    
}

int main(int argc, char **argv){
    UNITY_BEGIN();

    RUN_TEST(test_GuardarDatos);
    RUN_TEST(test_ObtenerMac);
    RUN_TEST(test_ObtenerCodigo);

    UNITY_END();

    return 0;
}