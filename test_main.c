#include <stdio.h>
#include <assert.h>
#include "dijkstra.h"
#include "approximate_solution.h"
#include "road_network.h"
#include "graph.h"
#include "time.h"
#include "test_main.h"
#include "test_utilities.h"

void runDijkstraTest(Graph *graph, int startVertex);
void runApproximateTest(Graph *graph, int startVertex);
void compareSolutions(Graph *graph, int startVertex);

int main() {
    // Prompt the user to select a dataset
    int choice;
    printf("Select a dataset to test:\n");
    printf("1. Random 5x5 Grid\n");
    printf("2. Belgium Road Network\n");
    printf("3. Minnesota Road Network\n");
    scanf("%d", &choice);

    Graph *graph = NULL;
    int V = 0;
    switch(choice) {
        case 1:
            graph = generateRandomGraph(5, 5); // Random 5x5 grid
            V = graph->V;
            break;
        case 2:
            graph = readGraph("road-belgium-osm.mtx");
            if (!graph) {
                printf("Failed to load Belgium road network\n");
                return 1;
            }
            V = graph->V;
            break;
        case 3:
            graph = readGraph("road-minnesota.mtx");
            if (!graph) {
                printf("Failed to load Minnesota road network\n");
                return 1;
            }
            V = graph->V;
            break;
        default:
            printf("Invalid choice\n");
            return 1;
    }

    printf("Enter starting vertex: ");
    int startVertex;
    scanf("%d", &startVertex);

    // Run the Dijkstra's test with timing
    printf("\nRunning Dijkstra's Algorithm...\n");
    startTimer();
    runDijkstraTest(graph, startVertex);
    stopTimer();
    printf("Time elapsed for Dijkstra's Algorithm: %f seconds\n", getTimeElapsed());

    // Run the approximate solution test with timing
    printf("\nRunning Approximate Solution...\n");
    startTimer();
    runApproximateTest(graph, startVertex);
    stopTimer();
    printf("Time elapsed for Approximate Solution: %f seconds\n", getTimeElapsed());

    // Compare solutions
    printf("\nComparing Solutions...\n");
    compareSolutions(graph, startVertex);

    // Measure memory usage
    int memoryUsage = getMemoryUsage();
    printf("Memory usage: %d KB\n", memoryUsage);

    // Run unit tests for both algorithms
    printf("\nRunning Dijkstra's Algorithm Tests...\n");
    testDijkstra();

    printf("\nRunning Approximate Solution Tests...\n");
    testApproximateSolution();

    printf("\nAll tests completed!\n");

    // Free the dynamically allocated memory
    freeGraph(graph);

    return 0;
}

void runDijkstraTest(Graph *graph, int startVertex) {
    int V = graph->V;
    int dist[V];
    dijkstraGraph(graph, startVertex, dist);
    printf("Dijkstra's distances from vertex %d:\n", startVertex);
    for (int i = 0; i < V; i++) {
        printf("Vertex %d: %d\n", i, dist[i]);
    }
}

void runApproximateTest(Graph *graph, int startVertex) {
    // Note: Approximate solution function needs to be adapted to work with Graph structure
    // Placeholder for approximate solution code
    printf("Approximate solution is not implemented for Graph structure.\n");
}

void compareSolutions(Graph *graph, int startVertex) {
    int V = graph->V;
    int dijkstraDist[V];
    dijkstraGraph(graph, startVertex, dijkstraDist);
    // Placeholder for comparison code
    printf("Comparison between Dijkstra and Approximate solution is not implemented for Graph structure.\n");
}

void testDijkstra() {
    RoadNetwork* testNetwork = initializeRoadNetwork(5, 5);
    initializeFixedGraph(testNetwork, 1);  // Initialize with all 1s
    Point start = {0, 0};
    Point end = {4, 4};
    assert(dijkstra(testNetwork, start, end) == 8);  // shortest path for a 5x5 grid with all 1s
    freeRoadNetwork(testNetwork);
}

void testApproximateSolution() {
    RoadNetwork* testNetwork = initializeRoadNetwork(5, 5);
    initializeFixedGraph(testNetwork, 1);  // Initialize with all 1s
    Point start = {0, 0};
    Point end = {4, 4};
    assert(approximateSolution(testNetwork, start, end) >= 8);  
    freeRoadNetwork(testNetwork);
}
