#include "road_network.h"
#include <stdlib.h>

RoadNetwork* initRoadNetwork(int rows, int cols) {
    RoadNetwork* network = (RoadNetwork*)malloc(sizeof(RoadNetwork));
    network->rows = rows;
    network->cols = cols;
    network->array = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        network->array[i] = (int*)malloc(cols * sizeof(int));
    }
    return network;
}

void freeRoadNetwork(RoadNetwork* network) {
    for (int i = 0; i < network->rows; i++) {
        free(network->array[i]);
    }
    free(network->array);
    free(network);
}
