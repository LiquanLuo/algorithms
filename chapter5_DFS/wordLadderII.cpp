/**

126. Word Ladder II


Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:

Only one letter can be changed at a time
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
Note:

Return an empty list if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output:
[
  ["hit","hot","dot","dog","cog"],
  ["hit","hot","lot","log","cog"]
]
Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: []

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.

*/


/**

1. a word is a node, find all shortest path from begin node to end node
2. construct adjacent list
3. using BFS find the distance of all nodes to the endword
4. using DFS find all shortes path, in each recursion, only select neighbours
whoses distance is smaller than original distance

*/



class Solution {
public:
    vector<vector<string>> findLadders(string beginWord,
                                       string endWord, 
                                       vector<string>& wordList) {
        vector<vector<string>> result;
        wordList.push_back(beginWord);
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if(wordSet.find(endWord) == wordSet.end()){
           return result; 
        }
        
        auto neighbours = findNeighbours(wordList, wordSet);
        auto distance = findDistance(endWord, wordList, neighbours);
        int startDist = distance[beginWord];
        vector<string> solution;
        solution.push_back(beginWord);
        findSolution(startDist, beginWord, solution, neighbours, distance, result);
        
        return result;
    }
    
    
    unordered_map<string, int> findDistance(string &endWord, 
                                            vector<string>& wordList,
                                            unordered_map<string, vector<string>> neighbours){
        unordered_map<string, int > distance;
        for(auto word : wordList){      // SOME WORDS CANNOT BE REACHED
            distance[word] = INT_MAX;
        }
        
        queue<string> strQueue;
        unordered_set<string> visited;
        strQueue.push(endWord);
        visited.insert(endWord);
        int dist = 0;
        while(!strQueue.empty()){
            int queueSize = strQueue.size();
            for(; queueSize > 0; --queueSize){
                auto word = strQueue.front();
                strQueue.pop();
                // cout << word << endl;
                distance[word] = dist;
                for(auto neighbour : neighbours[word]){
                    if(visited.find(neighbour) == visited.end()){
                        strQueue.push(neighbour);
                        visited.insert(neighbour);
                    }
                }
            }
            
            ++dist;
        }
            
        return distance;
    }
    
    
    unordered_map<string, vector<string>> findNeighbours(
        vector<string>& wordList,
        unordered_set<string> &wordSet){
        unordered_map<string, vector<string>> neighbours;
        for(auto word : wordList){
            vector<string>  neighbour;
            for(int pos = 0; pos < word.size(); ++pos){
                for(char c = 'a'; c <= 'z'; ++c){
                    if(c == word[pos]){
                        continue;
                    }
                    
                    auto newWord = word;
                    newWord[pos] = c;
                    if(wordSet.find(newWord) != wordSet.end()){
                        neighbour.push_back(newWord);
                    }
                }
            }
            
            neighbours[word] = neighbour;       
        }
        
        return neighbours;
    }
    
    void findSolution(int startDist,
                      string &beginWord, 
                      vector<string> &solution, 
                      unordered_map<string, vector<string>> &neighbours, 
                      unordered_map<string, int> &distance, 
                      vector<vector<string>> &result){
        if(startDist  == 0){
            result.push_back(solution);
            return;
        }
        
        for(auto neighbour : neighbours[beginWord]){
            if(distance[neighbour] < startDist){
                solution.push_back(neighbour);
                findSolution(distance[neighbour], neighbour, solution,
                             neighbours, distance, result);
                solution.pop_back();
            }
        }
    }
    
};