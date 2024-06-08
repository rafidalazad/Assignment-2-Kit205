#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "graph.h"
#include "dijkstra.h"
#include "approximate_solution.h"
#include "road_network.h"
#include "test_utilities.h"

// Timer functions for performance measurement
static clock_t start_time;

void startTimer() {
    start_time = clock();
}

double getTimeElapsed() {
    clock_t end_time = clock();
    return (double)(end_time - start_time) / CLOCKS_PER_SEC;
}

// Function to test Dijkstra's algorithm
void testDijkstra(Graph *g) {
    int V = g->V;
    int dist[V];

    // Execute Dijkstra's algorithm from vertex 0
    dijkstraGraph(g, 0, dist);
    printf("Dijkstra's Algorithm:\n");
    printSolution(dist, V);
}

// Function to test the Approximate solution algorithm
void testApproxAlgorithm() {
    RoadNetwork *network = initializeRoadNetwork(5, 5);
    if (!network) {
        printf("Failed to initialize the road network.\n");
        return;
    }

    // Initialize the network with some weights
    for (int i = 0; i < network->rows; i++) {
        for (int j = 0; j < network->cols; j++) {
            network->grid[i][j] = rand() % 10 + 1; // Random weights between 1 and 10
        }
    }

    Point start = {0, 0};
    Point end = {4, 4};

    // Time the Approximate solution algorithm
    startTimer();
    int approxDist = approximateSolution(network, start, end);
    printf("Approximate Solution Distance: %d\n", approxDist);
    printf("Approximate Solution took %lf seconds.\n", getTimeElapsed());

    freeRoadNetwork(network);
}

// Main function to execute the tests and demonstrate the algorithms
int main() {
    // Read the graph from file
    Graph *g = readGraph("input.txt");
    if (!g) {
        return 1; // Exit if the graph cannot be read
    }

    // Test Dijkstra's algorithm on the graph
    testDijkstra(g);

    // Initialize the road network for the additional tests
    int rows = 5, cols = 5;
    RoadNetwork *network = initializeRoadNetwork(rows, cols);
    if (!network) {
        printf("Failed to initialize the road network.\n");
        return 1;
    }

    // Set all grid values to 1 for simplicity
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            network->grid[i][j] = 1;
        }
    }

    // Define start and end points for pathfinding
    Point start = {0, 0};
    Point end = {4, 4};

    // Time Dijkstra's algorithm on the road network
    startTimer();
    int dijkstraDist = dijkstra(network, start, end);
    printf("Dijkstra's Algorithm Distance: %d\n", dijkstraDist);
    printf("Dijkstra's Algorithm took %lf seconds.\n", getTimeElapsed());

    // Time the Approximate Solution on the road network
    testApproxAlgorithm();

    // Compare the paths
    printf("Dijkstra's distance: %d\n", dijkstraDist);

    // Run additional tests for Dijkstra's algorithm
    printf("\nRunning Dijkstra tests on random graph:\n");
    testDijkstraOnRandomGraph();

    // Free the dynamically allocated memory
    freeRoadNetwork(network);
    freeGraph(g);

    return 0;
}
