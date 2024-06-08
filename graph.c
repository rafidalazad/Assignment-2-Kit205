#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

Graph *createGraph(int V) {
    Graph *g = (Graph *)malloc(sizeof(Graph));
    if (!g) {
        printf("Memory allocation failed for graph\n");
        exit(EXIT_FAILURE);
    }
    g->V = V;
    g->edges = (EdgeList *)malloc(V * sizeof(EdgeList));
    if (!g->edges) {
        printf("Memory allocation failed for edge lists\n");
        free(g);
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < V; i++) {
        g->edges[i].head = NULL;
    }
    return g;
}

void addEdge(Graph *g, int from, int to, int weight) {
    EdgeNodePtr newNode = (EdgeNodePtr)malloc(sizeof(struct edgeNode));
    if (!newNode) {
        printf("Memory allocation failed for new edge node\n");
        exit(EXIT_FAILURE);
    }
    newNode->edge.to_vertex = to;
    newNode->edge.weight = weight;
    newNode->next = g->edges[from].head;
    g->edges[from].head = newNode;
}

Graph *readGraph(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file!\n");
        return NULL;
    }

    // Skip the header of the Matrix Market file
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if (line[0] != '%') {
            break;
        }
    }

    // Read the dimensions and the number of edges
    int V, E;
    if (sscanf(line, "%d %d %d", &V, &V, &E) != 3) {
        printf("Error reading graph dimensions\n");
        fclose(file);
        return NULL;
    }

    Graph *g = createGraph(V);
    
    int from, to;
    while (fscanf(file, "%d %d", &from, &to) == 2) {
        from--; // Convert to 0-based index
        to--;   // Convert to 0-based index
        addEdge(g, from, to, 1); // Assume weight is 1 if not provided
        addEdge(g, to, from, 1); // Since the graph is undirected
    }
    
    fclose(file);
    return g;
}

void calculateInDegrees(Graph *graph, int *inDegrees) {
    for (int i = 0; i < graph->V; i++) {
        EdgeNodePtr current = graph->edges[i].head;
        while (current != NULL) {
            inDegrees[current->edge.to_vertex]++;
            current = current->next;
        }
    }
}

void freeGraph(Graph *g) {
    for (int i = 0; i < g->V; i++) {
        EdgeNodePtr current = g->edges[i].head;
        while (current != NULL) {
            EdgeNodePtr temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(g->edges);
    free(g);
}
