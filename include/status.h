#include <Ticker.h>

JsonDocument status;

int clock_time_original[4] = {0, 0, 0, 0};
int clock_time[4] = {0, 0, 0, 0};
bool power[4] = {true, true, true, true};

Ticker ticker;

void initTimer()
{
    for (int i = 0; i <= 3; i++)
    {
        if (clock_time[i] > 0)
        {
            clock_time[i]--;
        }
    }
}

void timer()
{
    ticker.attach(1, initTimer);
}

JsonDocument updateStatus()
{
    for (int i = 0; i <= 3; i++)
    {
        status["time_original"][i] = clock_time_original[i];
        status["time"][i] = clock_time[i];
        status["power"][i] = power[i];
    }

    return status;
}