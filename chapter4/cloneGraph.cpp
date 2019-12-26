/**
133. Clone Graph

Given a reference of a node in a connected undirected graph, 
return a deep copy (clone) of the graph. Each node in the graph
 contains a val (int) and a list (List[Node]) of its neighbors.
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr){
            return nullptr;
        }

        vector<Node*> cloneNeighbors;
        auto cloneRoot = new Node(node->val, cloneNeighbors);
        unordered_map<Node*,Node*> nodeMap;
        nodeMap[node] = cloneRoot;

        cloneNodes(node, nodeMap);
        cloneEdges(nodeMap);
        
        return cloneRoot;
    }
    
    void cloneNodes(Node* start, unordered_map<Node*,Node*> &nodeMap){
        queue<Node*> nodeQueue;
        nodeQueue.push(start);
        
        while(!nodeQueue.empty()){
            auto node = nodeQueue.front();
            nodeQueue.pop();
            
            if(nodeMap.find(node) == nodeMap.end()){
                vector<Node*> cloneNeighbors;
                auto cloneNode = new Node(node->val, cloneNeighbors);
                nodeMap[node] = cloneNode;
            }
            
            for(auto neighbour: node->neighbors){
                if(nodeMap.find(neighbour) == nodeMap.end()){
                    nodeQueue.push(neighbour);
                }
            }
        }
    }
    
    void cloneEdges(unordered_map<Node*,Node*> &nodeMap){
        auto mbegin = nodeMap.cbegin();
        auto mend = nodeMap.cend();
        for(; mbegin != mend; ++mbegin){
            auto node = mbegin->first;
            auto cloneNode = mbegin->second;
            auto &cloneNeighbours = cloneNode->neighbors;
            for(Node* neighbour: node->neighbors){
                Node* cloneNeighbour = nodeMap[neighbour];
                cloneNeighbours.push_back(cloneNeighbour);
            }
        }
    }

    
};