#include <iostream>

#include <gtest/gtest.h>

#include <planning.h>
#include <path_planning/utils/graph_utils.h>
#include <path_planning/graph_search/graph_search.h>

/**
 * Runs BFS on a graph and asserts that the path goes from start to goal and contains all valid edges.
 * @param  start_name The name of the starting node.
 * @param  goal_name The name of the goal node.
 * @param  graph_file The relative file path to the graph file.
 */
void testMichiganBfs(std::string start_name, std::string goal_name, std::string graph_file) {
    Graph graph = createGraph(graph_file);
    int start_index = nameToIdx(start_name, graph.data);
    int goal_index = nameToIdx(goal_name, graph.data);
    std::vector<int> path = bfs(start_index, goal_index, graph);
    
    // Check size, start, and goal.
    ASSERT_GE(path.size(), 2);
    ASSERT_EQ(path[0], start_index);
    ASSERT_EQ(path[path.size()-1], goal_index);

    // Check all path connections are edges in the graph.
    for (int i = 0; i < path.size()-1; ++i) {
        bool is_neighbor = false;
        std::vector<int> neighbors = getNeighbors(path[i], graph);
        for (const int neighbor_node_index : neighbors) {
            if (path[i+1] == neighbor_node_index) is_neighbor = true;
        }
        ASSERT_TRUE(is_neighbor);
    }
}

/**
 * Loads a map into a graph and asserts that findNeighbors() returns the correct neighbors for a given node.
 * @param  node_index The index of the node to get the neighbors of.
 * @param  correct_neighbor_indicies The indicies of the correct neighbors of the given node.
 * @param  map_file The map file to load into a graph.
 */
void testFindNeighbors(const int node_index, const std::vector<int> &correct_neighbor_indicies,
                       const std::string &map_file) {
    GridGraph graph;
    loadFromFile(map_file, graph);
    std::vector<int> neighbor_indicies = findNeighbors(node_index, graph);
    ASSERT_EQ(neighbor_indicies.size(), correct_neighbor_indicies.size());
    for (size_t i = 0; i < neighbor_indicies.size(); ++i) {
        ASSERT_EQ(neighbor_indicies[i], correct_neighbor_indicies[i]);
    }
}

/**
 * Loads a map into a graph, runs bfs() between two nodes on the graph, and asserts that the output path is correct.
 * @param  correct_i The correct i indicies of the Cells in the path in order.
 * @param  correct_j The correct j indicies of the Cells in the path in order.
 * @param  map_file The map file to load into a graph.
 */
void testGridGraphBreadthFirstSearch(const std::vector<int> correct_i, const std::vector<int> correct_j, const std::string &map_file) {
    std::vector<Cell> correct_path;
    Cell current;
    for (size_t i = 0; i < correct_i.size(); ++i) {
        current.i = correct_i[i];
        current.j = correct_j[i];
        correct_path.push_back(current);
    }
    GridGraph graph;
    loadFromFile(map_file, graph);
    std::vector<Cell> path = breadthFirstSearch(graph, correct_path.front(), correct_path.back());

    for (size_t i = 0; i < path.size(); i++) {
        std::cout << path[i].i << ", ";
    }
    std::cout << std::endl;

    for (size_t i = 0; i < path.size(); i++) {
        std::cout << path[i].j << ", ";
    }

    ASSERT_EQ(path.size(), correct_path.size());
    for (size_t i = 0; i < path.size(); ++i) {
        ASSERT_EQ(path[i].i, correct_path[i].i);
        ASSERT_EQ(path[i].j, correct_path[i].j);
    }
}
