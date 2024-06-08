#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

Graph *createGraph(int V) {
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->V = V;
    g->edges = (EdgeList *)malloc(V * sizeof(EdgeList));
    for (int i = 0; i < V; i++) {
        g->edges[i].head = NULL;
    }
    return g;
}

void addEdge(Graph *g, int from, int to, int weight) {
    EdgeNodePtr newNode = (EdgeNodePtr)malloc(sizeof(struct edgeNode));
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
    fscanf(file, "%d", &V);
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
