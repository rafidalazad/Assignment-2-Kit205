#include <stdio.h>
#include "graph.h"
#include "dijkstra.h"
#include "test_utilities.h"

void testRandomGraph() {
    Graph* g = generateRandomGraph(10, 15); // Generate a random graph with 10 vertices and 15 edges

    int V = g->V;
    int dist[V];

    // Execute Dijkstra's algorithm from vertex 0
    dijkstraGraph(g, 0, dist);
    printf("Dijkstra's Algorithm on Random Graph:\n");
    printSolution(dist, V);

    // Free the dynamically allocated memory
    freeGraph(g);
}

int main() {
    // Run the procedural test
    testRandomGraph();

    return 0;
}
