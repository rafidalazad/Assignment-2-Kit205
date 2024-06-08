
#include "road_network.h"
#include <stdlib.h>  // For dynamic memory allocation and deallocation
#include <stdio.h>   // For error handling and debugging

// Function to initialize the road network
RoadNetwork* initializeRoadNetwork(int rows, int cols) {
    RoadNetwork* network = (RoadNetwork*)malloc(sizeof(RoadNetwork));
    if (!network) {
        // Handle memory allocation failure
        printf("Memory allocation failed for RoadNetwork structure\n");
        return NULL;
    }

    network->rows = rows;
    network->cols = cols;

    // Allocate memory for the 2D grid
    network->grid = (int**)malloc(rows * sizeof(int*));
    if (!network->grid) {
        // Handle memory allocation failure
        printf("Memory allocation failed for grid rows\n");
        free(network);
        return NULL;
    }
    
    for (int i = 0; i < rows; i++) {
        network->grid[i] = (int*)malloc(cols * sizeof(int));
        if (!network->grid[i]) {
            // Handle memory allocation failure for a specific row
            printf("Memory allocation failed for grid row %d\n", i);
            for (int j = 0; j < i; j++) {
                free(network->grid[j]);
            }
            free(network->grid);
            free(network);
            return NULL;
        }
    }

    // Optionally, initialize the grid with default values or load from some source
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            network->grid[i][j] = 0; // Initialize with default value
        }
    }

    return network;
}

// Function to free the allocated memory for the road network
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
