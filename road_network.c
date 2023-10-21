#include "road_network.h"
#include <stdlib.h>  // For dynamic memory allocation and deallocation

RoadNetwork* initializeRoadNetwork(int rows, int cols) {
    RoadNetwork* network = (RoadNetwork*)malloc(sizeof(RoadNetwork));
    if (!network) {
        // Handle memory allocation failure
        return NULL;
    }

    network->rows = rows;
    network->cols = cols;

    // Allocate memory for the 2D grid
    network->grid = (int**)malloc(rows * sizeof(int*));
    if (!network->grid) {
        // Handle memory allocation failure
        free(network);
        return NULL;
    }
    
    for (int i = 0; i < rows; i++) {
        network->grid[i] = (int*)malloc(cols * sizeof(int));
        if (!network->grid[i]) {
            // Handle memory allocation failure for a specific row
            for (int j = 0; j < i; j++) {
                free(network->grid[j]);
            }
            free(network->grid);
            free(network);
            return NULL;
        }
    }

    // Optionally, initialize the grid with default values or load from some source

    return network;
}

void freeRoadNetwork(RoadNetwork* network) {
    if (!network) return;

    // Free the 2D grid memory
    for (int i = 0; i < network->rows; i++) {
        free(network->grid[i]);
    }
    free(network->grid);

    // Free the network structure itself
    free(network);
}
