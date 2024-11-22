#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>

#include "planning.h"
using namespace std;

void printPath(std::vector<int>& path, Graph& g) {

    if (path.size() < 1)
    {
        std::cout << "No path found :(\n";
        return;
    }

    std::cout << "Path: ";
    for (int i = 0; i < path.size() - 1; i++)
    {
        std::cout << g.data[path[i]] << " -> ";
    }
    std::cout <<  g.data[path.back()] << "\n";
};

std::vector<int> tracePath(int n, Graph& g) {
    std::vector<int> path;
    int curr = n;
    do {
        path.push_back(curr);
        curr = getParent(curr, g);
    } while (curr != -1);

    // Since we built the path backwards, we need to reverse it.
    std::reverse(path.begin(), path.end());
    return path;
};

std::vector<int> getNeighbors(int n, Graph& g)
{
    return g.edges[n];
}

std::vector<float> getEdgeCosts(int n, Graph& g)
{
    return g.edge_costs[n];
}

int getParent(int n, Graph& g)
{
    // *** Task: Implement this function *** //
    return g.nodes[n].parent;
    return -1;

    // *** End student code *** //
}

void initGraph(Graph& g)
{
    g.nodes.clear();
    for (int i = 0; i < g.data.size(); i++)
    {
        Node n;
        n.city = g.data[i];
        n.visited = false;
        n.distance = 10000000000;
        n.parent;
        g.nodes.push_back(n);
    }

    
}

std::vector<int> bfs(int start, int goal, Graph& g)
{
    initGraph(g);
    vector<int> path;
    queue<int> visit_queue;
    visit_queue.push(start);
    g.nodes[start].visited = true;
    g.nodes[start].queued = true;
    g.nodes[start].parent = -1;
    g.nodes[start].distance = 0;

    while(!visit_queue.empty()){
        int current = visit_queue.front();
        visit_queue.pop();

        if (current == goal){
            path = tracePath(current, g);
            for (int i = 0; i < path.size(); i++){
                cout << path[i] << endl;
            }
            return path;
        }

        vector<int> neighbors = getNeighbors(current, g);
        vector<float> edgeCosts = getEdgeCosts(current, g);

        for (int i = 0; i < neighbors.size(); i++){
            int neighbor = neighbors[i];
            float cost = edgeCosts[i];

            if (g.nodes[neighbor].queued == false && g.nodes[neighbor].visited == false){
                visit_queue.push(neighbor);
                g.nodes[neighbor].queued = true;
                if ((g.nodes[current].distance + cost) < (g.nodes[neighbor].distance)){
                    g.nodes[neighbor].distance = g.nodes[current].distance + cost;
                    g.nodes[neighbor].parent = current;
                }
            }

        }
        g.nodes[current].visited = true;
    }


    
}

std::vector<int> dfs(int start, int goal, Graph& g)
{
    initGraph(g);
    std::vector<int> path;

    std::stack<int> visit_stack;

    // *** Task: Implement this function if completing the advanced extension *** //

    // *** End student code *** //

    return path;
}
