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

    int V, from, to, weight;
    if (fscanf(file, "%d", &V) != 1) {
        printf("Error reading number of vertices\n");
        fclose(file);
        return NULL;
    }

    Graph *g = createGraph(V);
    
    while (fscanf(file, "%d,%d,%d", &from, &to, &weight) == 3) {
        addEdge(g, from, to, weight);
    }
    
    fclose(file);
    return g;
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

    free(g->edges);
    free(g);
}
