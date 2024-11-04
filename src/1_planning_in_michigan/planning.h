#ifndef PLANNING_H
#define PLANNING_H

#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>

#define HIGH 1e6

/**
 * Node struct to store information necessary for search algorithm implementation.
 */
struct Node
{
    std::string city;
    
    // *** Task: Add variables necessary for running your search algorithms *** //

    // *** End student code *** //
};

/**
 * Graph to store Nodes and their connectivity. 
 */
struct Graph
{
    std::vector<Node> nodes;
    std::vector<std::string> data;
    std::vector<std::vector<int> > edges;
    std::vector<std::vector<float> > edge_costs;
};

/**
 * Converts a nodes name to its associated index.
 * @param  name The name of the node.
 * @param  v A vector of all the names of the nodes in a graph in order.
 * @return  The index of the name in v. 
 */
static int nameToIdx(std::string name, std::vector<std::string>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == name) return i;
    }
    return -1;
};

/**
 * Creates a graph form a serialized graph file in the format below. 
 * 
 *  NODES
 *  node1
 *  node2
 *  node3
 *  ...
 *  EDGES
 *  node1 node2 edge_cost_1_2
 *  node1 node3 edge_cost_1_3
 *  ...
 * 
 * @param  file_path The relative path to the graph file.
 * @return  A graph with the structure described in the file.
 */
static Graph createGraph(std::string file_path)
{
    Graph g;
    std::ifstream in(file_path);
    if (!in.is_open())
    {
        std::cerr << "ERROR: Failed to load graph from " << file_path << std::endl;
        return g;
    }

    std::string s = "";
    int N = 0;
    while (s != "NODES") in >> s >> N;

    for (int i = 0; i < N; i++)
    {
        in >> s;
        g.data.push_back(s);
    }

    g.edges = std::vector<std::vector<int> >(N, std::vector<int>());
    g.edge_costs = std::vector<std::vector<float> >(N, std::vector<float>());

    while (s != "EDGES") in >> s >> N;

    std::string city1, city2;
    float dist;
    for (int i = 0; i < N; i++)
    {
        in >> city1 >> city2 >> dist;
        int c1 = nameToIdx(city1, g.data);
        int c2 = nameToIdx(city2, g.data);
        g.edges[c1].push_back(c2);
        g.edges[c2].push_back(c1);
        g.edge_costs[c1].push_back(dist);
        g.edge_costs[c2].push_back(dist);
    }

    return g;
};

/**
 * Print the names of the nodes in a path in order.
 * @param  path The path represented as node indicies.
 * @param  g The graph the path is on.
 */
void printPath(std::vector<int>& path, Graph& g);

/**
 * Retrieves the path in terms of indicies.
 * @param  n The index of the node at the end of the path (the goal node).
 * @param  g The associated graph.
 * @return  The path as a list of indicies.
 */
std::vector<int> tracePath(int n, Graph& g);

/**
 * Gets the neighbors of a given node in a graph.
 * @param  n The index of the node.
 * @param  g The associated graph.
 * @return  A list of the indicies of neighboring nodes.
 * 
 * NOTE: Return is parallel to the return of getEdgeCosts() below.
 */
std::vector<int> getNeighbors(int n, Graph& g);

/**
 * Gets the edge costs of the edges connected to a given node in a graph.
 * @param  n The index of the node.
 * @param  g The associated graph.
 * @return  A list of the edge costs of attached edges.
 * 
 * NOTE: Return is parallel to the return of getNeighbors() above.
 */
std::vector<float> getEdgeCosts(int n, Graph& g);

/**
 * Gets the parent of a give node in a graph.
 * @param  n The index of the node.
 * @param  g The associated graph.
 * @return  The index of the parent of the node.
 */
int getParent(int n, Graph& g);

/**
 * Initializes node data in a graph. Intended to be called after createGraph().
 * @param[out]  g The graph to initialize.
 */
void initGraph(Graph& g);

/**
 * Searches for a path from a starting node to a goal node on a graph using breadth first search.
 * @param  start The index of the starting node.
 * @param  goal The index of the goal node.
 * @param  g The associated graph.
 * @return  A list of indicies of nodes that form a path from the starting node to the goal node.
 */
std::vector<int> bfs(int start, int goal, Graph& g);

/**
 * Searches for a path from a starting node to a goal node on a graph using breadth first search.
 * @param  start The index of the starting node.
 * @param  goal The index of the goal node.
 * @param  g The associated graph.
 * @return  A list of indicies of nodes that form a path from the starting node to the goal node.
 */
std::vector<int> dfs(int start, int goal, Graph& g);

#endif  // PLANNING_H
