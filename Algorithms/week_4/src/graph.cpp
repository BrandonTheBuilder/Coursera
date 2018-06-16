#include "graph.h"

Graph::Graph(std::vector<std::vector<int>> graph){
    _graph = graph;
    for(std::vector<int> node : _graph){
        std::vector<int> ids;
        ids.push_back(node[0]);
        _nodeids.insert(std::make_pair(node[0], ids));
    }
}

std::vector<std::vector<int>> getGraph(const std::string& fileName) {
    std::fstream input(fileName);
    std::string line;
    //std::cout << "Reading File\n"; 
    std::vector<std::vector<int>> graph;
    while(!input.eof()) {
        getline(input, line);
        std::istringstream buffer(line);
        std::vector<int> data = {};
        //std::cout << "-------\n";
        int num;
        while(buffer >> num){
            //std::cout << num << "\n";
            data.push_back(num);
        }

        if(data.size() > 1){
            //std::cout << "data size:" << data.size() << "\n";
            graph.push_back(data);
        }
    }
    return graph;
}

int getMinCut(const std::string& fileName) {
    const std::vector<std::vector<int>> graph = getGraph(fileName);
    int trials = 10 * graph.size() * graph.size();
    std::vector<int> results = {};
    for(int i = 0; i < trials; i++){
        Graph graph_obj = Graph(graph);
        results.push_back(graph_obj.getMinCut());
    }
    int *cut = &*std::min_element(std::begin(results), std::end(results));
    return *cut;
}

int Graph::getMinCut() {
    while(_graph.size() > 2) {
        // shuffle the graph
        int firstNodeIndex = rand() % _graph.size();
        std::vector<int> firstNode = _graph[firstNodeIndex];
        int firstIndex = firstNode[0];
        //print();
        //std::cout << "first node is: " << firstIndex << "\n";
        // remove the node
        _graph.erase(_graph.begin() + firstNodeIndex);
        int secondNodeIndex = rand() % _graph.size();
        std::vector<int> secondNode = _graph[secondNodeIndex];
        int secondIndex = secondNode[0];
        //std::cout << secondIndex << " is the second node\n";
        _graph.erase(_graph.begin() + secondNodeIndex);
        if(_nodeids.count(firstIndex) != 1 ) {
            //std::cout << "First index is not already a super node " << firstIndex << "\n"; 
            std::vector<int> nodes;
            nodes.push_back(firstIndex);
            nodes.push_back(secondIndex);
            //std::cout << "inserting for second index \n";
            for(int x : nodes) {
                //std::cout << x << " ,";
            }
            //std::cout << "\n";
            _nodeids.insert(std::make_pair(firstIndex, nodes));
        }
        else {
            //std::cout << "adding second index to first index \n";
            _nodeids[firstIndex].insert(_nodeids[firstIndex].end(), _nodeids[secondIndex].begin(), _nodeids[secondIndex].end());   
        }
        std::vector<int> ids = _nodeids[firstIndex];            
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
    //std::cout << "done with final contraction\n";
    //print();
    //return the number of edges in the first node, which is its length minus the id
    return _graph[0].size() - 1;
}

void Graph::print() {
    //std::cout << "nodeids!\n";
    for(auto& pair : _nodeids){
        int key = pair.first;
        //std::cout << "key: " << key << "\n";
        for (int val: _nodeids[key]) {
            //std::cout << val << ", ";
        }
        //std::cout << "\n";
    }
    //std::cout << "\n Nodes \n";
    for (std::vector<int> node: _graph){
        //std::cout << "\n";
        for (int val: node) {
            //std::cout << val << ", ";
        }
    }
    //std::cout << "\n";
}
void Graph::combineNodes() {

}
