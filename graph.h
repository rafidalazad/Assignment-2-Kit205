#ifndef GRAPH_H
#define GRAPH_H

// Structure to represent an edge in the graph
typedef struct edge {
    int to_vertex;  // Destination vertex
    int weight;     // Weight of the edge
} Edge;

// Structure for a node in the edge linked list
typedef struct edgeNode {
    Edge edge;                      // Edge data
    struct edgeNode *next;          // Pointer to the next node in the list
} *EdgeNodePtr;

// Structure for the edge linked list
typedef struct edgeList {
    EdgeNodePtr head;               // Pointer to the head node of the list
} EdgeList;

// Structure to represent the graph
typedef struct graph {
    int V;                          // Number of vertices
    EdgeList *edges;                // Array of edge lists
} Graph;

// Function to create a graph with V vertices
Graph *createGraph(int V);

// Function to add an edge to the graph
void addEdge(Graph *g, int from, int to, int weight);

// Function to read a graph from a file
Graph *readGraph(const char *filename);

// Function to calculate the in-degrees of vertices in the graph
void calculateInDegrees(Graph *graph, int *inDegrees);

// Function to free all dynamically allocated memory for the graph
void freeGraph(Graph *g);

#endif // GRAPH_H
