/**
QUESTION:
210. Course Schedule II

There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

Example 1:

Input: 2, [[1,0]] 
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished   
             course 0. So the correct course order is [0,1] .
Example 2:

Input: 4, [[1,0],[2,0],[3,1],[3,2]]
Output: [0,1,2,3] or [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both     
             courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. 
             So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .
Note:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.

*/

/**
SOLUTION:

1. use adjacent list to store the graph;
2. use indegree to solve the problem, put the node whose indegree is zero into the 
queue and do the BFS.
3. if the result's size is less than number of given courses, there must be a loop
and this is not a tree.
*/


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> results;
        auto indegree = getIndegree(numCourses,prerequisites);        
        auto adjacentList = getAdjacnetList(numCourses,prerequisites);

        queue<int> deleteQueue;
        for(int id = 0; id < numCourses; ++id){
            if(indegree[id] == 0){
                deleteQueue.push(id);
            }
        }
        
        while(!deleteQueue.empty()){
            int id = deleteQueue.front();
            deleteQueue.pop();
            results.push_back(id);
            for(auto neighbour: adjacentList[id]){
                if(--indegree[neighbour] == 0){
                    deleteQueue.push(neighbour);
                }
            }
        }
        
        if(results.size() != numCourses){
            results.clear();
        }
        return results;
    }
    
    
    vector<int> getIndegree(int numCourses, vector<vector<int>> &prerequisites){
        vector<int> indegree;
        for(int i = 0; i < numCourses; ++i){
            indegree.push_back(0);
        }
        
        for(auto edge:prerequisites){
            ++indegree[edge[0]];
        }
        
        return indegree;
    }
    
    vector<vector<int>> getAdjacnetList(int numCourses, 
                                    vector<vector<int>> &prerequisites){
        vector<vector<int>> adjacentList;
        for(int i = 0; i < numCourses; ++i){
            vector<int> neighbours;
            adjacentList.push_back(neighbours);
        }
        
        for(auto edge:prerequisites){
            auto from = edge[1];
            auto to = edge[0];
            adjacentList[from].push_back(to);
        }
        
        return adjacentList;
    }
    
    
    

};