#include <stdio.h>
#include "dijkstra.h"
#include "approximate_solution.h"
#include "road_network.h"
#include "time.h"

// Function prototypes from tests.c (both versions)
void runDijkstraTest(RoadNetwork* network, Point start, Point end);
void runApproximateTest(RoadNetwork* network, Point start, Point end);
void compareSolutions(RoadNetwork* network, Point start, Point end);
void testDijkstra();
void testApproximateSolution();

int main() {
    RoadNetwork* network = initializeRoadNetwork();  // Assuming this function is provided in road_network.c

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
    stopTimer();
    printf("Time elapsed for Dijkstra's Algorithm: %f seconds\n", getTimeElapsed());

    // Run the approximate solution test with timing
    printf("\nRunning Approximate Solution...\n");
    startTimer();
    runApproximateTest(network, start, end);
    stopTimer();
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

    // Assuming there's a function to free the network resources in road_network.c
    freeRoadNetwork(network);

    return 0;
}
