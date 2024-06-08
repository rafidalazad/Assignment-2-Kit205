#include "approximate_solution.h"
#include "graph.h"
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct {
    Point position;
    int gCost;
    int hCost;
    int fCost;
    Point parent;
} Node;

int heuristic(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

bool isValid(Point p, int width, int height) {
    return (p.x >= 0) && (p.x < width) && (p.y >= 0) && (p.y < height);
}

int approximateSolution(RoadNetwork* network, Point start, Point end) {
    int V = network->rows;
    if (!isValid(start, V, V) || !isValid(end, V, V)) {
        return INT_MAX;
    }

    Node nodes[V][V];
    bool openSet[V][V];
    bool closedSet[V][V];

    for (int y = 0; y < V; y++) {
        for (int x = 0; x < V; x++) {
            nodes[y][x].position = (Point){x, y};
            nodes[y][x].gCost = INT_MAX;
            nodes[y][x].hCost = heuristic((Point){x, y}, end);
            nodes[y][x].fCost = INT_MAX;
            openSet[y][x] = false;
            closedSet[y][x] = false;
        }
    }

    nodes[start.y][start.x].gCost = 0;
    nodes[start.y][start.x].fCost = nodes[start.y][start.x].hCost;
    openSet[start.y][start.x] = true;

    Point moves[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    Point getLowestFCostNode(bool openSet[V][V], Node nodes[V][V], int V) {
        int lowestFCost = INT_MAX;
        Point lowestPoint = {-1, -1};
        for (int y = 0; y < V; y++) {
            for (int x = 0; x < V; x++) {
                if (openSet[y][x] && nodes[y][x].fCost < lowestFCost) {
                    lowestFCost = nodes[y][x].fCost;
                    lowestPoint = nodes[y][x].position;
                }
            }
        }
        return lowestPoint;
    }

    while (true) {
        Point currentNodePos = getLowestFCostNode(openSet, nodes, V);
        
        if (currentNodePos.x == -1 && currentNodePos.y == -1) {
            return INT_MAX;
        }
        
        openSet[currentNodePos.y][currentNodePos.x] = false;
        closedSet[currentNodePos.y][currentNodePos.x] = true;
        
        if (currentNodePos.x == end.x && currentNodePos.y == end.y) {
            break;
        }
        
        for (int i = 0; i < 4; i++) {
            Point neighborPos = {currentNodePos.x + moves[i].x, currentNodePos.y + moves[i].y};
            if (!isValid(neighborPos, V, V) || closedSet[neighborPos.y][neighborPos.x]) {
                continue;
            }
            
            int tentativeGCost = nodes[currentNodePos.y][currentNodePos.x].gCost + network->grid[currentNodePos.y][currentNodePos.x];
            if (tentativeGCost < nodes[neighborPos.y][neighborPos.x].gCost) {
                nodes[neighborPos.y][neighborPos.x].parent = currentNodePos;
                nodes[neighborPos.y][neighborPos.x].gCost = tentativeGCost;
                nodes[neighborPos.y][neighborPos.x].fCost = nodes[neighborPos.y][neighborPos.x].gCost + nodes[neighborPos.y][neighborPos.x].hCost;
                
                if (!openSet[neighborPos.y][neighborPos.x]) {
                    openSet[neighborPos.y][neighborPos.x] = true;
                }
            }
        }
    }

    int pathCost = 0;
    Point current = end;
    while (!(current.x == start.x && current.y == start.y)) {
        pathCost += network->grid[current.y][current.x];
        current = nodes[current.y][current.x].parent;
    }

    return pathCost;
}


