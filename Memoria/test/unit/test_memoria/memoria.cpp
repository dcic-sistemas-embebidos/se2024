
#include <unity.h>
#include <ArduinoFake.h>


using namespace fakeit;

struct Preference {
    virtual int Begin(void);
    virtual void End(void);
    virtual void putString(void);
    virtual void getString(void);
};

Mock<Preference> Preference_mock;

int Begin(void){
   return Preference_mock.get().Begin();
}
void End(void){
    Preference_mock.get().End();
}
void putString (void){
    Preference_mock.get().putString();
}
void getString (void){
    Preference_mock.get().getString();
}

void setUp(void){}

void tearDown(void){}


void test_GuardarDatos(void){
    When(Method(Preference_mock, Begin));
    When(Method(Preference_mock, putString));
    When(Method(Preference_mock, putString));
    When(Method(Preference_mock, End));
    Verify(Method(Preference_mock, Begin));

    Verify(Method(Preference_mock, putString));
    Verify(Method(Preference_mock, putString));
    Verify(Method(Preference_mock, End));
}

void test_ObtenerMac(void){
    When(Method(Preference_mock, Begin));
    When(Method(Preference_mock, getString));
    When(Method(Preference_mock, End));
    Verify(Method(Preference_mock, Begin));
    Verify(Method(Preference_mock, getString));
    Verify(Method(Preference_mock, End));
}

void test_ObtenerCodigo(void){
    When(Method(Preference_mock, Begin));
    When(Method(Preference_mock, getString));
    When(Method(Preference_mock, End));
    Verify(Method(Preference_mock, Begin));
    Verify(Method(Preference_mock, getString));
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