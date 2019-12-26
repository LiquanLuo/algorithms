/**
178. Graph Valid Tree

Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

Example
Example 1:

Input: n = 5 edges = [[0, 1], [0, 2], [0, 3], [1, 4]]
Output: true.
Example 2:

Input: n = 5 edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]]
Output: false.
Notice
You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

*/


/**
SOLUTION:
1. [E] = [V] - 1;
2. all nodes are connected, starting from a node, we can go to any node
3. BFS
4. convert edges to a adjacent list

*/
class Solution {
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>> &edges) {
        if(edges.size() != n-1){
            return false;
        }
        
        vector<vector<int>> adjacentList = getAdjacentList(n, edges);
        int start = 0;
        std::queue<int> nodeQueue;
        unordered_set<int> nodeSet;
        nodeQueue.push(start);
        nodeSet.insert(start);
        while(!nodeQueue.empty()){
            auto node = nodeQueue.front();
            nodeQueue.pop();
            cout << "node: " << node << endl;
            for(auto neighbour: adjacentList[node]){
                cout << "neighbour: " << neighbour << endl;
                if(nodeSet.find(neighbour) == nodeSet.end()){
                     nodeQueue.push(neighbour);
                     nodeSet.insert(neighbour);
                }
            }
        }
        
        if(nodeSet.size() == n){
            return true;
        }
        
        return false;
    }
    
    vector<vector<int>> getAdjacentList(int nodeNum, vector<vector<int>> &edges){
        vector<vector<int>> adjacentList;
        for(int i = 0; i < nodeNum; ++i){
            vector<int> neighbours;
            adjacentList.push_back(neighbours);
        }
        
        for(auto edge: edges){
            auto node1 = edge[0];
            auto node2 = edge[1];
            // cout << "node1 " << node1 << "node2 " << node2 << endl;
            adjacentList[node1].push_back(node2);
            adjacentList[node2].push_back(node1);
        }
        
        return adjacentList;
        
    }
    
    
    
    
};