#define GRAPH_H

typedef struct edge {
    int to_vertex;
    int weight;
} Edge;

typedef struct edgeNode {
    Edge edge;
    struct edgeNode *next;
} *EdgeNodePtr;

typedef struct edgeList {
    EdgeNodePtr head;
} EdgeList;

typedef struct graph {
    int V;
    EdgeList *edges;
} Graph;

Graph *readGraph();
void addEdge(Graph *g, int from, int to, int weight);
Graph *createGraph(int V);
void calculateInDegrees(Graph *graph, int *inDegrees);

#endif // GRAPH_H
