#include "dijkstra.h"
#include "graph.h"
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

int minDistance(int dist[], bool sptSet[], int V) {
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < V; v++)
        if (!sptSet[v] && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

void dijkstra(Graph* g, int src, int dist[]) {
    int V = g->V;
    bool sptSet[V];
    
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
    dist[src] = 0;
    
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet, V);
        sptSet[u] = true;
        
        for (EdgeNodePtr current = g->edges[u].head; current != NULL; current = current->next) {
            int v = current->edge.to_vertex;
            int weight = current->edge.weight;
            if (!sptSet[v] && dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }
}

void printSolution(int dist[], int V) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t %d\n", i, dist[i]);
}

void executeDijkstra(Graph* g) {
    int V = g->V;
    int dist[V];

    // Assuming a starting point for the pathfinding
    int start = 0;
    dijkstra(g, start, dist);

    printf("Shortest distances from vertex %d:\n", start);
    printSolution(dist, V);
}
