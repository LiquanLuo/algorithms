
/**
605. Sequence Reconstruction

Check whether the original sequence org can be uniquely 
reconstructed from the sequences in seqs. The org sequence 
is a permutation of the integers from 1 to n, with 1 ≤ n ≤ 10^4.
Reconstruction means building a shortest common supersequence of 
the sequences in seqs (i.e., a shortest sequence so that all sequences
in seqs are subsequences of it). Determine whether there is only one 
sequence that can be reconstructed from seqs and it is the org sequence.

Example
Example 1:

Input:org = [1,2,3], seqs = [[1,2],[1,3]]
Output: false
Explanation:
[1,2,3] is not the only one sequence that can be reconstructed, because [1,3,2] is also a valid sequence that can be reconstructed.
Example 2:

Input: org = [1,2,3], seqs = [[1,2]]
Output: false
Explanation:
The reconstructed sequence can only be [1,2].
Example 3:

Input: org = [1,2,3], seqs = [[1,2],[1,3],[2,3]]
Output: true
Explanation:
The sequences [1,2], [1,3], and [2,3] can uniquely reconstruct the original sequence [1,2,3].
Example 4:

Input:org = [4,1,5,2,6,3], seqs = [[5,2,6,3],[4,1,5,2]]
Output:true
*/

/**

SOLUTION:
1. topological sorting
2. if deque has more than two nodes inside, return false


*/


class Solution {
public:
    /**
     * @param org: a permutation of the integers from 1 to n
     * @param seqs: a list of sequences
     * @return: true if it can be reconstructed only one or false
     */
    bool sequenceReconstruction(vector<int> &org, vector<vector<int>> &seqs) {
        unordered_map<int,int> indegrees = getIndegrees(seqs);
        unordered_map<int,vector<int>> adjacentList = getAdjacentList(seqs);
        queue<int> nodeQueue;
        vector<int> reconSeq;
        for(auto indegree: indegrees){
            cout << "node: " << indegree.first << " indegrer: " <<indegree.second << endl;
            if(indegree.second == 0){
                nodeQueue.push(indegree.first);
                if(nodeQueue.size() > 1){
                    return false;
                }
            }
        }
        
        while(!nodeQueue.empty()){
            auto node = nodeQueue.front();
            nodeQueue.pop();
            reconSeq.push_back(node);
            for(auto neighbour: adjacentList[node]){
                if(--indegrees[neighbour] == 0){
                    nodeQueue.push(neighbour);
                    if(nodeQueue.size() > 1){
                        return false;
                    }
                }
            }
        }
        
        if(reconSeq != org){
            return false;
        }
        
        return true;
    }
    
     unordered_map<int,int> getIndegrees(vector<vector<int>> &seqs) {
        unordered_map<int,int> indegrees;
        
        for(auto seq:seqs){
            for(int i = 0; i < seq.size(); ++i){
                indegrees[seq[i]] = 0;
            }
        }
        
        for(auto seq:seqs){
            for(int i = 0; i+1 < seq.size(); ++i){
                ++indegrees[seq[i+1]];
            }
        }
        
        return indegrees;
        
        
     }
    
    unordered_map<int,vector<int>> getAdjacentList(vector<vector<int>> &seqs) {
        unordered_map<int,vector<int>> adjacentList;
         
        for(auto seq:seqs){
            for(int i = 0; i < seq.size(); ++i){
                auto node = seq[i];
                vector<int> neighbours;
                adjacentList[node] = neighbours;
            }
        }
        
        for(auto seq:seqs){
            for(int i = 0; i+1 < seq.size(); ++i){
                auto from = seq[i];
                auto to = seq[i+1];
                adjacentList[from].push_back(to);
            }
        }
         
        return adjacentList;
         
         
    }
};