// graph.c
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

Graph *readGraph() {
    int V, E, to, weight;
    scanf("%d", &V);
    Graph *g = createGraph(V);
    for (int i = 0; i < V; i++) {
        scanf("%d", &E);
        for (int j = 0; j < E; j++) {
            scanf("%d,%d", &to, &weight);
            addEdge(g, i, to, weight);
        }
    }
    return g;
}

void calculateInDegrees(Graph *graph, int *inDegrees) {
    for (int i = 0; i < graph->V; i++) {
        inDegrees[i] = 0;
    }
    for (int i = 0; i < graph->V; i++) {
        EdgeNodePtr current = graph->edges[i].head;
        while (current != NULL) {
            inDegrees[current->edge.to_vertex]++;
            current = current->next;
        }
    }
}
