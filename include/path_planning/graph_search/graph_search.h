#ifndef PATH_PLANNING_GRAPH_SEARCH_GRAPH_SEARCH_H
#define PATH_PLANNING_GRAPH_SEARCH_GRAPH_SEARCH_H

#include <vector>

#include <path_planning/utils/graph_utils.h>

/**
 * Searches over a graph for a path between two nodes using depth first search. 
 * @param[in, out]  graph The graph to search over.
 * @param  start The start cell.
 * @param  goal The goal cell.
 * @return  A list of cells representing the path.
 */
std::vector<Cell> depthFirstSearch(GridGraph& graph, const Cell& start, const Cell& goal);

/**
 * Searches over a graph for a path between two nodes using breadth first search. 
 * @param[in, out]  graph The graph to search over.
 * @param  start The start cell.
 * @param  goal The goal cell.
 * @return  A list of cells representing the path.
 */
std::vector<Cell> breadthFirstSearch(GridGraph& graph, const Cell& start, const Cell& goal);

/**
 * Searches over a graph for a path between two nodes using iterative deepening search.
 * @param[in, out]  graph The graph to search over.
 * @param  start The start cell.
 * @param  goal The goal cell.
 * @return  A list of cells representing the path.
 */
std::vector<Cell> iterativeDeepeningSearch(GridGraph& graph, const Cell& start, const Cell& goal);

/**
 * Searches over a graph for a path between two nodes using A* search. 
 * @param[in, out]  graph The graph to search over.
 * @param  start The start cell.
 * @param  goal The goal cell.
 * @return  A list of cells representing the path.
 */
std::vector<Cell> aStarSearch(GridGraph& graph, const Cell& start, const Cell& goal);

#endif  // PATH_PLANNING_GRAPH_SEARCH_GRAPH_SEARCH_H
