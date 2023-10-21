#include <time.h>
#include <stdlib.h> // For some general-purpose functions

#ifdef _WIN32 // Check if on a Windows system
#include <windows.h>
#include <psapi.h>
#else // Assuming a POSIX system (like Linux)
#include <sys/resource.h>
#endif

// Global variable for performance measurement
clock_t start_time, end_time;

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
    #ifdef _WIN32 // For Windows
    PROCESS_MEMORY_COUNTERS pmc;
    if (GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc))) {
        return pmc.WorkingSetSize / 1024; // Returning memory in KB
    }
    #else // For POSIX
    struct rusage rusage;
    getrusage(RUSAGE_SELF, &rusage);
    return rusage.ru_maxrss; // Returning memory in KB
    #endif

    return -1; // Error condition, failed to get memory usage
}

int comparePaths(RoadNetwork* network, Point start, Point end) {
    int dijkstraWeight = dijkstra(network, start, end);
    int approxWeight = approximateSolution(network, start, end);
    return dijkstraWeight - approxWeight;  // Will be 0 if paths are the same weight
}



