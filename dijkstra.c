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

    // The 4 possible movement directions: top, right, bottom, left
int dX[] = {-1, 0, 1, 0};
int dY[] = {0, 1, 0, -1};

// A utility function to find the vertex with minimum distance value, from the set of vertices not yet included in the shortest path tree
Point minDistance(int** dist, bool** sptSet, int width, int height) {
    int min = INT_MAX;
    Point min_index = {-1, -1};

    for (int v = 0; v < height; v++) {
        for (int u = 0; u < width; u++) {
            if (!sptSet[v][u] && dist[v][u] <= min) {
                min = dist[v][u];
                min_index.x = u;
                min_index.y = v;
            }
        }
    }

    return min_index;
}

// ... Inside the dijkstra() function ...

// sptSet will be true if the vertex is included in the shortest path tree
bool** sptSet = (bool**)malloc(network->height * sizeof(bool*));
for (int i = 0; i < network->height; i++) {
    sptSet[i] = (bool*)malloc(network->width * sizeof(bool));
    for (int j = 0; j < network->width; j++) {
        sptSet[i][j] = false;
    }
}

for (int count = 0; count < network->width * network->height - 1; count++) {
    Point u = minDistance(dist, sptSet, network->width, network->height);

    // Mark the picked vertex as processed
    sptSet[u.y][u.x] = true;

    // Update dist value of the adjacent vertices of the picked vertex
    for (int k = 0; k < 4; k++) {  // iterate through possible directions
        int newX = u.x + dX[k];
        int newY = u.y + dY[k];
        Point v = {newX, newY};

        if (isValid(v, network->width, network->height) && 
            !sptSet[newY][newX] &&
            dist[u.y][u.x] != INT_MAX &&
            dist[u.y][u.x] + network->grid[newY][newX] < dist[newY][newX]) {
            dist[newY][newX] = dist[u.y][u.x] + network->grid[newY][newX];
        }
    }
}

// Cleanup sptSet after the loop
for (int i = 0; i < network->height; i++) {
    free(sptSet[i]);
}
free(sptSet);


    // Cleanup and return the shortest distance
    int result = dist[end.y][end.x];
    for (int i = 0; i < network->height; i++) {
        free(dist[i]);
    }
    free(dist);
    return result;
}
void executeDijkstra(RoadNetwork* network)
 {
    // Assuming a starting and ending point for the pathfinding
    Point start = {0, 0};
    Point end = {network->width - 1, network->height - 1};

    int shortestDistance = dijkstra(network, start, end);
    printf("Shortest distance from start to end: %d\n", shortestDistance);
}
