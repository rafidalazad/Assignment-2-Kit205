#include "dijkstra.h"
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

// Helper function to check if a given point is valid
bool isValid(Point p, int width, int height) {
    return (p.x >= 0) && (p.x < width) && (p.y >= 0) && (p.y < height);
}

// Helper function to check if a point is the destination
bool isDestination(Point p, Point end) {
    return (p.x == end.x && p.y == end.y);
}

// Implementation of Dijkstra's algorithm for 2D grid
int dijkstra(RoadNetwork* network, Point start, Point end) {
    if (!isValid(start, network->width, network->height) || !isValid(end, network->width, network->height)) {
        // Invalid start or end points
        return INT_MAX;
    }

    // Create a distance array and initialize all distances as INFINITE
    int** dist = (int**)malloc(network->height * sizeof(int*));
    for (int i = 0; i < network->height; i++) {
        dist[i] = (int*)malloc(network->width * sizeof(int));
        for (int j = 0; j < network->width; j++) {
            dist[i][j] = INT_MAX;
        }
    }
    dist[start.y][start.x] = network->grid[start.y][start.x];

    // ... rest of the Dijkstra's algorithm implementation ...

    // Cleanup and return the shortest distance
    int result = dist[end.y][end.x];
    for (int i = 0; i < network->height; i++) {
        free(dist[i]);
    }
    free(dist);
    return result;
}
