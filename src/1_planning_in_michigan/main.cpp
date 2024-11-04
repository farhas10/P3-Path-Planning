#include <stack>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#include "planning.h"

int main() {
    Graph g = createGraph("../data/planning_in_michigan/mi_graph.txt");
    // Graph g = createGraph("data/planning_in_michigan/bereaf23_graph.txt");

    int start = nameToIdx("ann_arbor", g.data);
    int goal = nameToIdx("flint", g.data);
    // int start = nameToIdx("roseville", g.data);
    // int goal = nameToIdx("saipan", g.data);
    std::vector<int> path;

    auto nbrs = getNeighbors(start, g);
    for (auto& n : nbrs) std::cout << n << " ";
    std::cout << std::endl;

    auto costs = getEdgeCosts(start, g);
    for (auto& n : costs) std::cout << n << " ";
    std::cout << std::endl;

    std::cout << "Searching for a path from " << g.data[start];
    std::cout << " (index: " << start << ") to " << g.data[goal];
    std::cout << " (index: " << goal << ")...\n";

    std::cout << "BFS:\n";
    path = bfs(start, goal, g);
    printPath(path, g);

    std::cout << "DFS:\n";
    path = dfs(start, goal, g);
    printPath(path, g);

    return 0;
}
