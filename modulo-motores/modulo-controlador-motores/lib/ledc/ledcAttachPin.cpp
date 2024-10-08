static int mock_pin;
static int mock_channel;
static bool ledcAttachPin_called = false;

void ledcAttachPin(int pin, int channel) {
    mock_pin = pin;
    mock_channel = channel;
    ledcAttachPin_called = true;
}

// Funciones para validar en los tests
bool was_ledcAttachPin_called() {
    return ledcAttachPin_called;
}

int get_mock_pin() {
    return mock_pin;
}

int get_mock_channel() {
    return mock_channel;
}

// Función para resetear el mock entre tests
void reset_ledcAttachPin_mock() {
    ledcAttachPin_called = false;
    mock_pin = 0;
    mock_channel = 0;
}