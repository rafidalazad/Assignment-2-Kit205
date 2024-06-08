#include <stdio.h>
#include <assert.h>
#include "dijkstra.h"
#include "approximate_solution.h"
#include "road_network.h"
#include "time.h"

// Function prototypes
void runDijkstraTest(RoadNetwork* network, Point start, Point end);
void runApproximateTest(RoadNetwork* network, Point start, Point end);
void compareSolutions(RoadNetwork* network, Point start, Point end);
void testDijkstra();
void testApproximateSolution();

// Timer functions for performance measurement
static clock_t start_time;

void startTimer() {
    start_time = clock();
}

double getTimeElapsed() {
    clock_t end_time = clock();
    return (double)(end_time - start_time) / CLOCKS_PER_SEC;
}

int main() {
    // Initialize the road network
    int rows = 5, cols = 5;
    RoadNetwork* network = initializeRoadNetwork(rows, cols); 

    printf("Enter starting point (x y): ");
    Point start;
    scanf("%d %d", &start.x, &start.y);

    printf("Enter ending point (x y): ");
    Point end;
    scanf("%d %d", &end.x, &end.y);

    // Run the Dijkstra's test with timing
    printf("\nRunning Dijkstra's Algorithm...\n");
    startTimer();
    runDijkstraTest(network, start, end);
    printf("Time elapsed for Dijkstra's Algorithm: %f seconds\n", getTimeElapsed());

    // Run the approximate solution test with timing
    printf("\nRunning Approximate Solution...\n");
    startTimer();
    runApproximateTest(network, start, end);
    printf("Time elapsed for Approximate Solution: %f seconds\n", getTimeElapsed());

    // Compare solutions
    printf("\nComparing Solutions...\n");
    compareSolutions(network, start, end);

    // Run unit tests for both algorithms
    printf("\nRunning Dijkstra's Algorithm Tests...\n");
    testDijkstra();

    printf("\nRunning Approximate Solution Tests...\n");
    testApproximateSolution();

    printf("\nAll tests completed!\n");

    // Free the dynamically allocated memory
    freeRoadNetwork(network);

    return 0;
}

void runDijkstraTest(RoadNetwork* network, Point start, Point end) {
    int dist = dijkstra(network, start, end);
    printf("Dijkstra's distance: %d\n", dist);
}

void runApproximateTest(RoadNetwork* network, Point start, Point end) {
    int dist = approximateSolution(network, start, end);
    printf("Approximate solution distance: %d\n", dist);
}

void compareSolutions(RoadNetwork* network, Point start, Point end) {
    int dijkstraDist = dijkstra(network, start, end);
    int approxDist = approximateSolution(network, start, end);
    printf("Dijkstra's distance: %d\n", dijkstraDist);
    printf("Approximate distance: %d\n", approxDist);
    if (dijkstraDist == approxDist) {
        printf("Both solutions are equal!\n");
    } else {
        printf("The solutions differ!\n");
    }
}

void testDijkstra() {
    RoadNetwork* testNetwork = initializeRoadNetwork(5, 5);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            testNetwork->grid[i][j] = 1;  // setting all grid values to 1 for simplicity
        }
    }
    Point start = {0, 0};
    Point end = {4, 4};
    assert(dijkstra(testNetwork, start, end) == 8);  // shortest path for a 5x5 grid with all 1s
    freeRoadNetwork(testNetwork);
}

void testApproximateSolution() {
    RoadNetwork* testNetwork = initializeRoadNetwork(5, 5);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            testNetwork->grid[i][j] = 1;  // setting all grid values to 1 for simplicity
        }
    }
    Point start = {0, 0};
    Point end = {4, 4};
    assert(approximateSolution(testNetwork, start, end) >= 8);  
    freeRoadNetwork(testNetwork);
}

