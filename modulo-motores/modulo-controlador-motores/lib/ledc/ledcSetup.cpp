static int mock_channel_setup;
static int mock_frequency;
static int mock_resolution;
static bool ledcSetup_called = false;

void ledcSetup(int channel, int freq, int resolution) {
    mock_channel_setup = channel;
    mock_frequency = freq;
    mock_resolution = resolution;
    ledcSetup_called = true;
}

// Funciones para verificar en los tests
bool was_ledcSetup_called() {
    return ledcSetup_called;
}

int get_mock_channel_setup() {
    return mock_channel_setup;
}

int get_mock_frequency() {
    return mock_frequency;
}

int get_mock_resolution() {
    return mock_resolution;
}

// Función para resetear el mock entre tests
void reset_ledcSetup_mock() {
    ledcSetup_called = false;
    mock_channel_setup = 0;
    mock_frequency = 0;
    mock_resolution = 0;
}