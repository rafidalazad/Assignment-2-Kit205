#include <stdio.h>
#include "graph.h"
#include "dijkstra.h"
#include "test_utilities.h"
#include "test_procedural.h"

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
    // Prompt the user to select a dataset
    int choice;
    printf("Select a dataset to test:\n");
    printf("1. Random Graph\n");
    printf("2. Belgium Road Network\n");
    printf("3. Minnesota Road Network\n");
    scanf("%d", &choice);

    Graph *graph = NULL;
    int V = 0;
    switch(choice) {
        case 1:
            graph = generateRandomGraph(10, 15); // Generate a random graph with 10 vertices and 15 edges
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
    int dist[V];
    dijkstraGraph(graph, startVertex, dist);
    printf("Dijkstra's Algorithm on Selected Dataset:\n");
    printSolution(dist, V);

    // Free the dynamically allocated memory
    freeGraph(graph);

    return 0;
}

