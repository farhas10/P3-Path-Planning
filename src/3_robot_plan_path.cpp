#include <iostream>
#include <cmath>
#include <string>

#include <mbot_bridge/robot.h>

#include <path_planning/utils/graph_utils.h>
#include <path_planning/utils/math_helpers.h>
#include <path_planning/utils/viz_utils.h>
#include <path_planning/graph_search/graph_search.h>
#include <path_planning/graph_search/distance_transform.h>


int main(int argc, char const *argv[])
{
    float goal_x = 0, goal_y = 0;

    if (argc < 2)
    {
        std::cerr << "Please provide the path to a map file as input.\n";
        return -1;
    }

    if (argc == 4)
    {
        goal_x = std::stof(argv[2]);
        goal_y = std::stof(argv[3]);
    }

    std::string map_file = argv[1];
    GridGraph graph;
    loadFromFile(map_file, graph);
    distanceTransformManhattan(graph);
    graph.collision_radius = 0.25;

    Cell goal = posToCell(goal_x, goal_y, graph);

    // Initialize the robot.
    mbot_bridge::MBot robot;
    // Get the robot's SLAM pose.
    std::vector<float> pose = robot.readSlamPose();

    Cell start = posToCell(pose[0], pose[1], graph);

    // std::vector<Cell> path = breadthFirstSearch(graph, start, goal);
    std::vector<Cell> path = aStarSearch(graph, start, goal);
    std::cout << "Found path!\n";
    robot.drivePath(cellsToPoses(path, graph));

    // Save the path output file for visualization in the nav app.
    generatePlanFile(start, goal, path, graph);

    return 0;
}
