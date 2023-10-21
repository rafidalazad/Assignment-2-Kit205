#include <stdio.h>
#include "dijkstra.h"
#include "approximate_solution.h"
#include "road_network.h"
#include "time.h"

int main() {
    // Initialize the road network
    int rows = 5, cols = 5;
    RoadNetwork* network = initRoadNetwork(rows, cols);

    // Let's assume some predefined grid values for this example
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            network->grid[i][j] = 1;  // setting all grid values to 1 for simplicity
        }
    }

    // Define start and end points for pathfinding
    Point start = {0, 0};
    Point end = {4, 4};

    // Time Dijkstra's algorithm
    startTimer();
    int dijkstraDist = dijkstra(network, start, end);
    stopTimer();
    printf("Dijkstra's Algorithm took %lf seconds.\n", getTimeElapsed());

    // Time the Approximate Solution
    startTimer();
    int approxDist = approximateSolution(network, start, end);
    stopTimer();
    printf("Approximate Solution took %lf seconds.\n", getTimeElapsed());

    // Compare the paths
    printf("Dijkstra's distance: %d\n", dijkstraDist);
    printf("Approximate distance: %d\n", approxDist);

    // Clean up memory
    freeRoadNetwork(network);

    return 0;
}
