// test_main.c
#include <stdio.h>

// Prototypes of test functions from other files
void testDijkstraOnRandomGraph(); // from test_dijkstra.c
// ... other test functions ...

int main() {
    printf("Running Dijkstra tests...\n");
    testDijkstraOnRandomGraph();
    // ... call other test functions ...

    // Repeat the structure for Approximate Solution tests

    printf("All tests finished.\n");
    return 0;
}
