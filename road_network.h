#ifndef ROAD_NETWORK_H
#define ROAD_NETWORK_H

// Represents the road network as a 2D grid
typedef struct {
    int** grid;        // A pointer to a 2D array representing the network
    int width, height; // Dimensions of the grid
} RoadNetwork;

// Function to initialize the road network with the given dimensions
RoadNetwork* initRoadNetwork(int width, int height);

// Function to free any memory allocated for the road network
void freeRoadNetwork(RoadNetwork* network);

#endif // ROAD_NETWORK_H
