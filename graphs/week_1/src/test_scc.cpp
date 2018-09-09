#include <gtest/gtest.h>
#include "scc.h"

TEST(getFinishingTime, simpleInput) {
    std::vector<std::vector<int>> graph_input = {
        {0,1,0},
        {1,0,0},
        {0,1,0},
    };
}

TEST(graph, createGraph) {
    Graph graph(10);
    ASSERT_EQ(graph(0,0), 0);
    ASSERT_EQ(graph(9,9), 0);
}
