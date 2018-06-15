#include "graph.h"

Graph::Graph(const std::string& fileName){
    std::fstream input(fileName);
    std::string line;
    std::cout << "Reading File\n"; 
    while(!input.eof()) {
        getline(input, line);
        std::istringstream buffer(line);
        std::vector<int> data = {};
        std::cout << "-------\n";
        int num;
        while(buffer >> num){
            std::cout << num << "\n";
            data.push_back(num);
        }

        if(data.size() > 1){
            std::cout << "data size:" << data.size() << "\n";
            _graph.push_back(data);
        }
    }
}

int Graph::getMinCut(int trials) {
    std::vector<int> results = {};
    for(int i = 0; i < trials; i++){
        auto rng = std::default_random_engine {};
        std::map<int, std::vector<int>> nodeIds;
        while(_graph.size() >= 2) {
            // shuffle the graph
            std::shuffle(_graph.begin(), _graph.end(), rng);
            std::vector<int> firstNode = _graph.back();
            int firstIndex = firstNode[0];
            // remove the node
            _graph.pop_back();
            std::vector<int> secondNode = _graph.back();
            int secondIndex = secondNode[0];
            _graph.pop_back();
            if(nodeIds.count(firstIndex) != 1 ) {
                std::cout << "First index is not already a super node " << firstIndex << "\n"; 
                std::vector<int> nodes;
                nodes.push_back(firstIndex);
                nodes.push_back(secondIndex);
                nodeIds.insert(std::make_pair(firstIndex, nodes));
            }
            else {
                nodeIds[firstIndex].push_back(secondIndex);   
            }
            std::vector<int> ids = nodeIds[firstIndex];            
            std::vector<int> superNode = {};
            // set the index of the super node with the index from the first node. 
            superNode.push_back(firstIndex);
            for(int i = 1; i < firstNode.size(); i++) {
                int val = firstNode[i];
                if(std::find(ids.begin(), ids.end(), val) == ids.end()){
                    superNode.push_back(val);
                }
            }
            for(int i = 1; i < secondNode.size(); i++){
                int val = secondNode[i];
                // if the id is included in the super node nodeids remove the loopback
                if(std::find(ids.begin(), ids.end(), val) == ids.end()){
                    superNode.push_back(val);
                }
            }
            _graph.push_back(superNode);
        }
        results.push_back(_graph[0].size());
    }
    int *cut = &*std::min_element(std::begin(results), std::end(results));
    std::cout << "Found a cut of " << *cut << "\n";
    return *cut;
}

void Graph::combineNodes() {

}
