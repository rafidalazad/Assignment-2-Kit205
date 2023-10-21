#include "approximate_solution.h"
#include "road_network.h"
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

// A simple structure for nodes in A*
typedef struct {
    Point position;
    int gCost; // Cost from the start
    int hCost; // Heuristic cost to the end
    int fCost; // Total cost (gCost + hCost)
    Point parent; // Parent node for path reconstruction
} Node;

// Heuristic function for A* - Manhattan Distance
int heuristic(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

bool isValid(Point p, int width, int height) {
    return (p.x >= 0) && (p.x < width) && (p.y >= 0) && (p.y < height);
}

// A* pathfinding algorithm using Manhattan distance heuristic
int approximateSolution(RoadNetwork* network, Point start, Point end) {
    // If start or end is out of bounds, return infinity
    if (!isValid(start, network->width, network->height) || !isValid(end, network->width, network->height)) {
        return INT_MAX;
    }

    // For this example, we will just use arrays, but in a full-scale application
    // more efficient data structures like priority queues would be used for the open set

    Node nodes[network->height][network->width];
    bool openSet[network->height][network->width] = { false };
    bool closedSet[network->height][network->width] = { false };

    // Initialize nodes
    for (int y = 0; y < network->height; y++) {
        for (int x = 0; x < network->width; x++) {
            nodes[y][x].position = (Point){x, y};
            nodes[y][x].gCost = INT_MAX;
            nodes[y][x].hCost = heuristic((Point){x, y}, end);
            nodes[y][x].fCost = INT_MAX;
        }
    }

    // Starting node
    nodes[start.y][start.x].gCost = 0;
    nodes[start.y][start.x].fCost = nodes[start.y][start.x].hCost;
    openSet[start.y][start.x] = true;

    // Possible moves (up, down, left, right)
    Point moves[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    // Helper function to get the node with the lowest fCost from the open set
Point getLowestFCostNode(bool openSet[network->height][network->width], Node nodes[network->height][network->width], int width, int height) {
    int lowestFCost = INT_MAX;
    Point lowestPoint = {-1, -1};
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (openSet[y][x] && nodes[y][x].fCost < lowestFCost) {
                lowestFCost = nodes[y][x].fCost;
                lowestPoint = nodes[y][x].position;
            }
        }
    }
    return lowestPoint;
}

// Main loop for A* algorithm
while (true) {
    // Find the node in the open set with the lowest fCost
    Point currentNodePos = getLowestFCostNode(openSet, nodes, network->width, network->height);
    
    // If we couldn't find a node, pathfinding failed
    if (currentNodePos.x == -1 && currentNodePos.y == -1) {
        return INT_MAX; // No path found
    }
    
    // Move currentNode from the open set to the closed set
    openSet[currentNodePos.y][currentNodePos.x] = false;
    closedSet[currentNodePos.y][currentNodePos.x] = true;
    
    // If the current node is the target, we're done
    if (currentNodePos.x == end.x && currentNodePos.y == end.y) {
        break;
    }
    
    // Check each neighbor
    for (int i = 0; i < 4; i++) {
        Point neighborPos = {currentNodePos.x + moves[i].x, currentNodePos.y + moves[i].y};
        if (!isValid(neighborPos, network->width, network->height) || closedSet[neighborPos.y][neighborPos.x]) {
            continue;
        }
        
        int tentativeGCost = nodes[currentNodePos.y][currentNodePos.x].gCost + network->grid[neighborPos.y][neighborPos.x];
        if (tentativeGCost < nodes[neighborPos.y][neighborPos.x].gCost) {
            nodes[neighborPos.y][neighborPos.x].parent = currentNodePos;
            nodes[neighborPos.y][neighborPos.x].gCost = tentativeGCost;
            nodes[neighborPos.y][neighborPos.x].fCost = nodes[neighborPos.y][neighborPos.x].gCost + nodes[neighborPos.y][neighborPos.x].hCost;
            
            // If neighbor is not in open set, add it
            if (!openSet[neighborPos.y][neighborPos.x]) {
                openSet[neighborPos.y][neighborPos.x] = true;
            }
        }
    }
}

// Here we would determine the shortest path's weight by following the parent pointers from the end node
int pathCost = 0;
Point current = end;
while (!(current.x == start.x && current.y == start.y)) {
    pathCost += network->grid[current.y][current.x];
    current = nodes[current.y][current.x].parent;
}

return pathCost;


    // For simplicity, we will just return the fCost of the end node
    return nodes[end.y][end.x].fCost;
}


