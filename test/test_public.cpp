#include <test_utils.h>

TEST(PlanningInMichigan, AnnArborMarquette) {
    testMichiganBfs("ann_arbor", "marquette", "../data/planning_in_michigan/mi_graph.txt");
}

TEST(PlanningInMichigan, SaginawBentonHarbor) {
    testMichiganBfs("saginaw", "benton_harbor", "../data/planning_in_michigan/mi_graph.txt");
}

TEST(FindNeighbors, TestMiddle) {
    int node_index = 6;  // Node in the middle.
    std::vector<int> correct_neighbor_indicies = {0, 5, 10, 1, 11, 2, 7, 12};
    testFindNeighbors(node_index, correct_neighbor_indicies, "../data/test/test_map.map");
}

TEST(FindNeighbors, TestCorner) {
    int node_index = 0;  // Node in the upper left corner.
    std::vector<int> correct_neighbor_indicies = {5, 1, 6};
    testFindNeighbors(node_index, correct_neighbor_indicies, "../data/test/test_map.map");
}

TEST(BFS, TestEmpty) {
    std::vector<int> correct_path_i = {10, 11, 12, 13, 14, 15};
    std::vector<int> correct_path_j = {10, 11, 12, 13, 14, 15};
    testGridGraphBreadthFirstSearch(correct_path_i, correct_path_j, "../data/empty_map.map");
}

TEST(BFS, TestCorner) {
    std::vector<int> correct_path_i = {50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 
                                       63, 64, 65, 66, 67, 67, 67, 67, 66, 66, 65, 64, 63, 
                                       62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50};
    std::vector<int> correct_path_j = {50, 49, 49, 49, 49, 49, 49, 49, 49, 48, 47, 47, 47, 
                                       47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 
                                       34, 33, 32, 31, 30, 29, 28, 28, 28, 28, 28, 28, 28};
    testGridGraphBreadthFirstSearch(correct_path_i, correct_path_j, "../data/maze3.map");
}