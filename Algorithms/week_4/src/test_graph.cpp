#include "graph.h"
#include <gtest/gtest.h>

TEST(Graph, create) {
    Graph graph = Graph("shortTest.txt");
    ASSERT_EQ(1, graph[0][0]);    
    for (int i = 0; i < graph.size(); i++){
        ASSERT_GE(graph[i].size(), 1);
    }
}

TEST(Graph, min_cut) {
    Graph graph = Graph("shortTest.txt");
    ASSERT_EQ(3, graph.getMinCut(100));   
}

TEST(Graph, largeInput) {
    Graph graph = Graph("kargerMinCut.txt");
    int ans = graph.getMinCut(100);
    std::cout << "The answer is " << ans << "!!\n";
}

TEST(minCut, one) {
    Graph graph = Graph("test_case_one.txt");
    ASSERT_EQ(2, graph.getMinCut(10));
}
