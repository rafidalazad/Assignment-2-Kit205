// test_dijkstra.c
#include "dijkstra.h"
#include "test_utilities.h"
#include "road_network.h"
#include <assert.h>
#include <stdio.h>

// Function to test Dijkstra's algorithm on a random graph
void testDijkstraOnRandomGraph() {
    RoadNetwork* network = generateRandomGraph(5, 5); // Random 5x5 grid

    // Test with fixed start and end points for simplicity
    Point start = {0, 0};
    Point end = {4, 4};

    int distance = dijkstra(network, start, end);
    printf("Dijkstra's distance on random graph: %d\n", distance);

    // Note: It's difficult to assert the correctness with random data.
    // For a meaningful test, consider using known graphs with expected outcomes.

    freeRoadNetwork(network);
}

// Function to test Dijkstra's algorithm on a graph with no possible path
void testDijkstraNoPath() {
    RoadNetwork* network = initializeRoadNetwork(5, 5);

    // Create a grid with no path from start to end (e.g., all weights set to a high value)
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            network->grid[i][j] = INT_MAX;
        }
    }

    Point start = {0, 0};
    Point end = {4, 4};

    int distance = dijkstra(network, start, end);
    assert(distance == INT_MAX);
    printf("Dijkstra's algorithm correctly identified no path exists.\n");

    freeRoadNetwork(network);
}

// Function to test Dijkstra's algorithm on a single-node graph
void testDijkstraSingleNode() {
    RoadNetwork* network = initializeRoadNetwork(1, 1);
    network->grid[0][0] = 0;

    Point start = {0, 0};
    Point end = {0, 0};

    int distance = dijkstra(network, start, end);
    assert(distance == 0);
    printf("Dijkstra's distance on single-node graph: %d\n", distance);

    freeRoadNetwork(network);
}

// Main function to execute all tests
int main() {
    printf("Running Dijkstra tests on random graph:\n");
    testDijkstraOnRandomGraph();

    printf("Running Dijkstra tests on graph with no possible path:\n");
    testDijkstraNoPath();

    printf("Running Dijkstra tests on single-node graph:\n");
    testDijkstraSingleNode();

    // Add more test cases as needed
    // - Graphs with specific known shortest paths
    // - Larger graphs for stress testing

    return 0;
}
