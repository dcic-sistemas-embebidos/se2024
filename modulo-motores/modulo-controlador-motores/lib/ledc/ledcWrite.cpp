static int mock_channel_write;
static int mock_duty;
static bool ledcWrite_called = false;

// Implementación del mock para ledcWrite
void ledcWrite(int channel, int duty) {
    mock_channel_write = channel;
    mock_duty = duty;
    ledcWrite_called = true;  // Indica que la función fue llamada
}

// Funciones para verificar en los tests
bool was_ledcWrite_called() {
    return ledcWrite_called;
}

int get_mock_channel_write() {
    return mock_channel_write;
}

int get_mock_duty() {
    return mock_duty;
}

// Función para resetear el mock entre tests
void reset_ledcWrite_mock() {
    ledcWrite_called = false;
    mock_channel_write = 0;
    mock_duty = 0;
}