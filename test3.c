#include <stdio.h>
#include "dijkstra.h"
#include "approximate_solution.h"
#include "road_network.h"
#include "time.h"

int main() {
    // Create a road network with some predefined data
    RoadNetwork* network = initializeRoadNetwork();
    
    // Test Dijkstra's Algorithm
    Point start1 = {1, 1};
    Point end1 = {4, 4};
    int dijkstraResult1 = dijkstra(network, start1, end1);
    printf("Dijkstra's Algorithm Result 1: %d\n", dijkstraResult1);
    
    // Test Approximate Solution
    Point start2 = {1, 1};
    Point end2 = {4, 4};
    int approxResult2 = approximateSolution(network, start2, end2);
    printf("Approximate Solution Result 2: %d\n", approxResult2);
    
    // Free memory
    freeRoadNetwork(network);
    
    return 0;
}
