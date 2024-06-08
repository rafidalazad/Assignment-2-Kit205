#include "test_utilities.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

RoadNetwork* generateRandomGraph(int rows, int cols) {
    RoadNetwork* network = initializeRoadNetwork(rows, cols);
    srand(time(NULL));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            network->grid[i][j] = rand() % 10 + 1; // Random values between 1 and 10
        }
    }

    return network;
}

void initializeFixedGraph(RoadNetwork* network, int value) {
    for (int i = 0; i < network->rows; i++) {
        for (int j = 0; j < network->cols; j++) {
            network->grid[i][j] = value; // Set all grid values to the specified value
        }
    }
}

void printGrid(RoadNetwork* network) {
    for (int i = 0; i < network->rows; i++) {
        for (int j = 0; j < network->cols; j++) {
            printf("%d ", network->grid[i][j]);
        }
        printf("\n");
    }
}
