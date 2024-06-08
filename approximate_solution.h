#ifndef APPROXIMATE_SOLUTION_H
#define APPROXIMATE_SOLUTION_H

// Represents a point in the grid with x and y coordinates
typedef struct {
    int x;
    int y;
} Point;

// Represents a node used for pathfinding (like A* algorithm)
typedef struct Node {
    Point position;         // Position of this node
    int gCost;              // Cost from the start node
    int hCost;              // Estimated cost to the end node (heuristic)
    int fCost;              // Total cost (gCost + hCost)
    struct Node* parent;    // Pointer to the parent node for path reconstruction
} Node;

// Represents the road network or 2D grid
typedef struct {
    int** grid;             // 2D array representing the grid weights
    int width;              // Width of the grid
    int height;             // Height of the grid
} RoadNetwork;

// Computes an approximate path in the road network between start and end points using A* algorithm.
// The function returns the total weight/cost of the computed path.
int approximateSolution(RoadNetwork* network, Point start, Point end);

#endif // APPROXIMATE_SOLUTION_H
