#ifndef ROAD_NETWORK_H
#define ROAD_NETWORK_H

typedef struct {
    int** grid;       // A pointer to a 2D array representing the network
    int** array;       // The 2D array representation of the road network.
    int rows, cols;    // Dimensions of the array.
} RoadNetwork;

// Function declarations:
RoadNetwork* initRoadNetwork(int rows, int cols);
void freeRoadNetwork(RoadNetwork* network);

#endif
