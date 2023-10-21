#ifndef TIME_H
#define TIME_H

#include <time.h>

extern clock_t start_time, end_time;

void startTimer();

void stopTimer();

double getTimeElapsed();

int getMemoryUsage();

#endif /* TIME_H */

