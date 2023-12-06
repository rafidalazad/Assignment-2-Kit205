#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

// ... [Your existing graph functions like addEdge, createGraph, readGraph]

// Function to calculate in-degrees of the graph
void calculateInDegrees(Graph *graph, int *inDegrees) {
    for (int i = 0; i < graph->V; i++) {
        EdgeNodePtr current = graph->edges[i].head;
        while (current != NULL) {
            inDegrees[current->edge.to_vertex]++;
            current = current->next;
        }
    }
}

int main() {
    Graph *graph = readGraph();

    // Initialize in-degree array
    int inDegrees[graph->V];
    for (int i = 0; i < graph->V; i++) {
        inDegrees[i] = 0;
    }

    // Calculate in-degrees
    calculateInDegrees(graph, inDegrees);

    // Print in-degrees
    printf("In-Degrees of the vertices:\n");
    for (int i = 0; i < graph->V; i++) {
        printf("Vertex %d: %d\n", i, inDegrees[i]);
    }

    // Free dynamically allocated memory
    for (int i = 0; i < graph->V; i++) {
        EdgeNodePtr current = graph->edges[i].head;
        while (current != NULL) {
            EdgeNodePtr temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(graph->edges);
    free(graph);

    return 0;
}
