Assignment 2


This project implements a graph data structure and algorithms to solve shortest path problems in a road network. The main algorithms implemented are Dijkstra's algorithm and an approximate solution algorithm.

Files
- Core Implementation Files:
  - `approximate_solution.c` & `approximate_solution.h`
  - `dijkstra.c` & `dijkstra.h`
  - `graph.c` & `graph.h`
  - `road_network.c` & `road_network.h`
  - `time.c` & `time.h`
- Main Program File:
  - `main.c`
- Testing Files:
  - `test_dijkstra.c`
  - `test_main.c` & `test_main.h`
  - `test_utilities.c` & `test_utilities.h`
  - `tests.c`
use the graphviz.dot file in https://dreampuf.github.io/GraphvizOnline/#digraph%20RoadNetwork%20%7B%0D%0A%20%20%20%20node%20%5Bshape%3Dcircle%5D%3B%0D%0A%20%20%20%200%20-%3E%201%20%5Blabel%3D%221%22%5D%3B%0D%0A%20%20%20%200%20-%3E%202%20%5Blabel%3D%223%22%5D%3B%0D%0A%20%20%20%201%20-%3E%203%20%5Blabel%3D%222%22%5D%3B%0D%0A%20%20%20%201%20-%3E%204%20%5Blabel%3D%224%22%5D%3B%0D%0A%20%20%20%202%20-%3E%203%20%5Blabel%3D%221%22%5D%3B%0D%0A%20%20%20%204%20-%3E%203%20%5Blabel%3D%222%22%5D%3B%0D%0A%20%20%20%204%20-%3E%206%20%5Blabel%3D%226%22%5D%3B%0D%0A%20%20%20%205%20-%3E%206%20%5Blabel%3D%222%22%5D%3B%0D%0A%20%20%20%205%20-%3E%204%20%5Blabel%3D%221%22%5D%3B%0D%0A%7D%0D%0A to visualize the graph

Compilation
Use the following command to compile the project:
```sh
gcc -o main main.c graph.c dijkstra.c approximate_solution.c road_network.c test_utilities.c -lm
