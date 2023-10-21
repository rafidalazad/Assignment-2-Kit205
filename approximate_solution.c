#include <time.h>

// ... rest of the includes ...

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

// Function to measure memory usage (pseudo code, platform-dependent)
int getMemoryUsage() {
    // return the memory used by the process
    // implementation might vary based on the OS and tools available
}

// Function to compare paths in terms of weights
int comparePaths(RoadNetwork* network, Point start, Point end) {
    int dijkstraWeight = dijkstra(network, start, end);
    int approxWeight = approximateSolution(network, start, end);
    return dijkstraWeight - approxWeight;  // Will be 0 if paths are the same weight
}

// ... rest of the file ...
