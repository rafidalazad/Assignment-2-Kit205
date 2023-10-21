// test_dijkstra.c
#include "dijkstra.h"
#include "test_utilities.h"
#include <assert.h>
#include <stdio.h>

void testDijkstraOnRandomGraph() {
    RoadNetwork* network = generateRandomGraph(5, 5); // Random 5x5 grid

    // Test with random start and end points. Simplified: they're fixed in this example.
    Point start = {0, 0};
    Point end = {4, 4};

    int distance = dijkstra(network, start, end);
    printf("Dijkstra's distance on random graph: %d\n", distance);

    // Here you should have logic comparing 'distance' with an expected value,
    // which can be hard with random data. Consider known cases.

    freeRoadNetwork(network);
}

// Add more test cases, for example:
// - Graphs with no possible path
// - Extremely large graphs
// - Single-node graph
// ...
