#include "graph.h"
#include <gtest/gtest.h>

TEST(Graph, create) {
    Graph graph = Graph("shortTest.txt");
    ASSERT_EQ(1, graph[0][0]);    
}
