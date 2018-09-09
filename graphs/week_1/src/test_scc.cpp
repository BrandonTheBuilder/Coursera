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
    ASSERT_EQ(graph(1,1), 0);
    ASSERT_EQ(graph(10,10), 0);
}

TEST(graph, addEdge) {
    Graph graph(10);
    graph.addEdge(1,1);
    ASSERT_EQ(graph(1,1), 1);
}

TEST(loadFromFile, simpleTest) {
    Graph graph = loadFromFile("data/simpleTest.txt", 9);
    ASSERT_EQ(graph(1,4),1);
    ASSERT_EQ(graph(2,8),1);
    ASSERT_EQ(graph(9,3),1);
    ASSERT_EQ(graph(8,6),1);
}

