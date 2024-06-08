#ifndef TEST_MAIN_H
#define TEST_MAIN_H

#include "road_network.h"

// Function prototypes for testing
void runDijkstraTest(RoadNetwork* network, Point start, Point end);
void runApproximateTest(RoadNetwork* network, Point start, Point end);
void compareSolutions(RoadNetwork* network, Point start, Point end);
void testDijkstra();
void testApproximateSolution();

#endif // TEST_MAIN_H
