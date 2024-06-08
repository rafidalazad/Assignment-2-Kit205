#include "time.h"
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#include <psapi.h>
#else
#include <sys/resource.h>
#endif

// Global variables for performance measurement
static clock_t start_time, end_time;

void startTimer() {
    start_time = clock();
}

void stopTimer() {
    end_time = clock();
}

double getTimeElapsed() {
    return ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
}

int getMemoryUsage() {
#ifdef _WIN32
    PROCESS_MEMORY_COUNTERS pmc;
    if (GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc))) {
        return pmc.WorkingSetSize / 1024; // Returning memory in KB
    }
#else
    struct rusage rusage;
    getrusage(RUSAGE_SELF, &rusage);
    return rusage.ru_maxrss; // Returning memory in KB
#endif
    return -1; // Error condition, failed to get memory usage
}
