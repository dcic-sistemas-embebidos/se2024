#ifndef LEDC_SETUP_H
#define LEDC_SETUP_H

void ledcSetup(int channel, int freq, int resolution);
bool was_ledcSetup_called();
int get_mock_channel_setup();
int get_mock_frequency();
int get_mock_resolution();
void reset_ledcSetup_mock();

#endif