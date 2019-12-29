
/**
127. Word Ladder


Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.


*/

/**
SOLUTION:
1. each word in the list is a node
2. use the BFS to find the shortest path
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);  //beginWord is not a transformed word.
        int depth = 1;
        unordered_set<string> visited;
        queue<string> strQueue;
        visited.insert(beginWord);
        strQueue.push(beginWord);
        auto neighbours = findNeighbours(wordList);
        while(!strQueue.empty()){
            int size = strQueue.size();
            for(; size > 0; --size){
                auto word = strQueue.front();
                // cout << word << endl;
                strQueue.pop();
                if(word ==  endWord){
                    return depth;
                }

                for(auto neighbour:neighbours[word]){
                    if(visited.find(neighbour) == visited.end()){   // not visited
                        visited.insert(neighbour);
                        strQueue.push(neighbour);
                    }
                }
            }
            cout << "---------" << endl;
            ++depth;    
        }
        
        return 0; 
    }
    
    unordered_map<string,vector<string>> findNeighbours(
        const vector<string>&wordList){
        unordered_set<string> wordSet(wordList.begin(),wordList.end());
        unordered_map<string,vector<string>> neighbours;
        for(auto word : wordList){
            // cout << " word:" << word << " neighbour:";
            vector<string> neighbour;
            for(int pos = 0; pos < word.size(); ++pos){
                for(char i = 'a'; i <= 'z'; ++i){
                    if(i == word[pos]){
                        continue;
                    }
                    auto newWord = word;
                    newWord[pos] = i;
                    if(wordSet.find(newWord) != wordSet.end()){
                        neighbour.push_back(newWord);
                        // cout << " " << newWord << " ";
                    }
                    
                }
            }
            // cout << endl;
            neighbours[word] = neighbour;
        }
        
        return neighbours;
    }
};