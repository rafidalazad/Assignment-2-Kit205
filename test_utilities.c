#include "graph.h"
#include <stdlib.h>
#include <time.h>

Graph* generateRandomGraph(int V) {
    srand(time(NULL)); // Seed for random number generation. Call this line in the main function of tests if it causes repeated results.
    
    Graph *graph = createGraph(V);

    // Generate random edges
    for (int i = 0; i < V; i++) {
        int edges = rand() % V; // Random number of edges for each vertex
        for (int j = 0; j < edges; j++) {
            int to = rand() % V;
            int weight = (rand() % 10) + 1; // Random weight between 1 and 10
            addEdge(graph, i, to, weight);
        }
    }

    return graph;
}

void initializeFixedGraph(RoadNetwork* network, int value) {
    for (int i = 0; i < network->rows; i++) {
        for (int j = 0; j < network->cols; j++) {
            network->grid[i][j] = value;
        }
    }
}
