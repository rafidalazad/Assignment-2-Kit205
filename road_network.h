#ifndef ROAD_NETWORK_H
#define ROAD_NETWORK_H

// Structure to represent a point with x and y coordinates
typedef struct {
    int x;
    int y;
} Point;

// Structure to represent the road network or 2D grid
typedef struct {
    int** grid; // 2D array representing the grid weights
    int rows;   // Number of rows in the grid
    int cols;   // Number of columns in the grid
} RoadNetwork;

// Function to initialize the road network
// Allocates memory for the grid and initializes it
RoadNetwork* initializeRoadNetwork(int rows, int cols);

// Function to free the allocated memory for the road network
void freeRoadNetwork(RoadNetwork* network);

// Function to load the road network from an .mtx file
// The .mtx file format is expected to be a sparse matrix format
RoadNetwork* loadRoadNetworkFromFile(const char* filename);

#endif // ROAD_NETWORK_H
