#ifndef LEDC_WRITE_H
#define LEDC_WRITE_H

void ledcWrite(int channel, int duty);
bool was_ledcWrite_called();
int get_mock_channel_write();
int get_mock_duty();
void reset_ledcWrite_mock();

#endif