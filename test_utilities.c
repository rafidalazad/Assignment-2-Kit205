// test_utilities.c
#include "road_network.h"
#include <stdlib.h>
#include <time.h>

RoadNetwork* generateRandomGraph(int rows, int cols) {
    srand(time(NULL)); // Seed for random number generation. Call this line in main function of tests if it causes repeated results.
    
    RoadNetwork* network = initRoadNetwork(rows, cols);
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Random weights, assuming they're between 1 and 10 for simplicity
            network->grid[i][j] = (rand() % 10) + 1; 
        }
    }

    return network;
}
