#ifndef PATH_PLANNING_GRAPH_SEARCH_DISTANCE_TRANSFORM_H
#define PATH_PLANNING_GRAPH_SEARCH_DISTANCE_TRANSFORM_H

#include <vector>

#include <path_planning/utils/graph_utils.h>

/**
 * Updates obstacle distances in the graph using iteration over the full graph.
 * @param[out]  graph The graph to update.
 */
void distanceTransformSlow(GridGraph& graph);

/**
 * Updates obstacle distances in the graph according to manhattan distance.
 * @param[out]  graph The graph to update.
 */
void distanceTransformManhattan(GridGraph& graph);

/**
 * Updates obstacle distances given a single row of obstacle distances.
 * @param  init_dt The initial distances recorded for a row.
 * @return  The updated distances. 
 */
std::vector<float> distanceTransformEuclidean1D(std::vector<float>& init_dt);

/**
 * Updates obstacle distances in the graph according to euclidean distance.
 * @param[out]  graph The graph to update.
 */
void distanceTransformEuclidean2D(GridGraph& graph);

#endif  // PATH_PLANNING_GRAPH_SEARCH_DISTANCE_TRANSFORM_H
