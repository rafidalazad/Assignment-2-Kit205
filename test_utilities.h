#ifndef TEST_UTILITIES_H
#define TEST_UTILITIES_H

#include "road_network.h"

// Function prototypes
RoadNetwork* generateRandomGraph(int rows, int cols);
void initializeFixedGraph(RoadNetwork* network, int value);
void printGrid(RoadNetwork* network);

#endif // TEST_UTILITIES_H
