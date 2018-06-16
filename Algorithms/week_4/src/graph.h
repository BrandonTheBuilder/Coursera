#include <stdlib.h>
#include <time.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <random>
#include <map>
#include <future>

int getMinCut(const std::string& fileName);
std::vector<std::vector<int>> getGraph(const std::string& fileName);

class Graph {
public:
    Graph(std::vector<std::vector<int>> graph);
    int getMinCut();
    int size() {return _graph.size();}
    std::vector<int> operator[](int i){return _graph[i];}
private:
    void combineNodes();
    void print();
    std::vector<std::vector<int>> _graph = {};
    std::map<int, std::vector<int>> _nodeids;

};
