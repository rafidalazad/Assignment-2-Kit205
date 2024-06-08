#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "graph.h"

// Each point in the grid has x and y coordinates
typedef struct {
    int x;
    int y;
} Point;

// Structure to represent the road network or 2D grid
typedef struct {
    int** grid;         // 2D array representing the grid weights
    int width;          // Width of the grid
    int height;         // Height of the grid
} RoadNetwork;

// Function to initialize the road network with given dimensions
RoadNetwork* initializeRoadNetwork(int width, int height);

// Function to free the memory allocated for the road network
void freeRoadNetwork(RoadNetwork* network);

// Function to compute the shortest path in the road network using Dijkstra's algorithm
// between the specified start and end points. Returns the total weight/cost of the computed path.
int dijkstra(RoadNetwork* network, Point start, Point end);

// Function to find the vertex with minimum distance value, from the set of vertices not yet included in the shortest path tree
int minDistance(int dist[], bool sptSet[], int V);

// Implementation of Dijkstra's algorithm for finding the shortest path from a source vertex to all other vertices
void dijkstraGraph(Graph* g, int src, int dist[]);

// Function to print the shortest distances from the source to all vertices
void printSolution(int dist[], int V);

// Function to execute Dijkstra's algorithm and demonstrate its functionality
void executeDijkstraGraph(Graph* g);

#endif // DIJKSTRA_H

