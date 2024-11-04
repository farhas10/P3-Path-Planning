cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
project(path_planning)

option(MBOT "Build code for the MBot." OFF)

if(MBOT)
message("Building code for the MBot.")
set(MACHINE_TYPE "OMNI")
else()
message("Building code for laptop.")
set(MACHINE_TYPE "LAPTOP")
endif()

set(CMAKE_BUILD_TYPE RelWithDebInfo)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

# If we're building for the Omnibot, find the Mbot bridge.
if(${MACHINE_TYPE} STREQUAL "OMNI")
  find_package(mbot_bridge REQUIRED)
endif()

# Planning in michigan executable.
add_executable(plan_in_michigan
  src/1_planning_in_michigan/main.cpp
  src/1_planning_in_michigan/planning.cpp
)
target_include_directories(plan_in_michigan PRIVATE
  src/1_planning_in_michigan
)

# Nav app executable.
add_executable(nav_cli src/2_path_planner_cli.cpp
  src/graph_search/graph_search.cpp
  src/graph_search/distance_transform.cpp
  src/utils/graph_utils.cpp
)
target_link_libraries(nav_cli
  ${CMAKE_THREAD_LIBS_INIT}
)
target_include_directories(nav_cli PRIVATE
  include
)

# If we're building for the MBot, build the robot path plan executable.
if(${MACHINE_TYPE} STREQUAL "OMNI")
  add_executable(robot_plan_path src/3_robot_plan_path.cpp
    src/graph_search/distance_transform.cpp
    src/graph_search/graph_search.cpp
    src/utils/graph_utils.cpp
  )
  target_link_libraries(robot_plan_path
    mbot_bridge_cpp
  )
  target_include_directories(robot_plan_path PRIVATE
    include
  )
endif()

# Tests.
enable_testing()

# Public test executable.
add_executable(test_public
  src/1_planning_in_michigan/planning.cpp
  src/graph_search/distance_transform.cpp
  src/graph_search/graph_search.cpp
  src/utils/graph_utils.cpp
  test/test_public.cpp
)
target_link_libraries(test_public
  GTest::gtest_main
)
target_include_directories(test_public PRIVATE
  include
  src/1_planning_in_michigan
  test
)
gtest_discover_tests(test_public)
