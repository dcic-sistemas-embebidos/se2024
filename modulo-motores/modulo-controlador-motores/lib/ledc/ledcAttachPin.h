#ifndef LEDC_ATTACH_PIN_H
#define LEDC_ATTACH_PIN_H

void ledcAttachPin(int pin, int channel);
bool was_ledcAttachPin_called();
int get_mock_pin();
int get_mock_channel();
void reset_ledcAttachPin_mock();

#endif