#ifndef DIJKSTRA_H
#define DIJKSTRA_H

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

// Function to compute the shortest path in the road network using Dijkstra's algorithm
// between the specified start and end points.
// Returns the total weight/cost of the computed path.
int dijkstra(RoadNetwork* network, Point start, Point end);

#endif // DIJKSTRA_H
