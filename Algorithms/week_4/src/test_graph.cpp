#include "graph.h"
#include <gtest/gtest.h>

TEST(getMinCut, create) {
    std::vector<std::vector<int>> vec = getGraph("shortTest.txt");
    Graph graph = Graph(vec);
    ASSERT_EQ(1, graph[0][0]);    
    for (int i = 0; i < graph.size(); i++){
        ASSERT_GE(graph[i].size(), 1);
    }
}

TEST(simple, simpleGraph) {
    int res = getMinCut("simpleGraph.txt");
    ASSERT_EQ(2, res);
}

TEST(getMinCut, min_cut) {
    int res = getMinCut("shortTest.txt");
    ASSERT_EQ(3, res);   
}

TEST(getMinCut, largeInput) {
    int res = getMinCut("kargerMinCut.txt");
    std::cout << "The answer is " << res << "!!\n";
}

TEST(minCut, one) {
    int res = getMinCut("test_case_one.txt");
    ASSERT_EQ(2, res);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  srand( time(NULL));
  return RUN_ALL_TESTS();
}
