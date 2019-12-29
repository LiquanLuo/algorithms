
/**
127. Topological Sorting

Given an directed graph, a topological order of the graph nodes is defined as follow:

For each directed edge A -> B in graph, A must before B in the order list.
The first node in the order can be any node in the graph with no nodes direct to it.
Find any topological order for the given graph

*/


/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */

class Solution {
public:
    /*
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*>& graph) {
        vector<DirectedGraphNode*> result;
        unordered_map<DirectedGraphNode*, int> indegrees =  getIndegree(graph);
        queue<DirectedGraphNode*> toBeAdded;
        for(auto indegree: indegrees){
            cout << "indegree.first " << indegree.first << " indegree.second " << indegree.second << endl;
            if(indegree.second == 0){
                toBeAdded.push(indegree.first);
            }
        }
        
        while(!toBeAdded.empty()){
            auto node = toBeAdded.front();
            toBeAdded.pop();
            result.push_back(node);
            
            for(auto neighbour: node->neighbors){
                if(--indegrees[neighbour] == 0){
                    toBeAdded.push(neighbour);
                }
            }
            
        }
        
        return result;
    }
    
    
    unordered_map<DirectedGraphNode*, int> getIndegree(vector<DirectedGraphNode*>& graph){
        unordered_map<DirectedGraphNode*, int> indegrees;
        for(auto fromNode: graph){
            indegrees[fromNode] = 0;
        }
        
        for(auto fromNode: graph){
            for(auto toNode: fromNode->neighbors){
                ++indegrees[toNode];
            }
        }
        
        return indegrees;
    }
    
    
};