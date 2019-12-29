/**

131. Palindrome Partitioning

Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

Example:

Input: "aab"
Output:
[
  ["aa","b"],
  ["a","a","b"]
]



*/

/**
SOLUTION:
1. DFS
2. for a string, there are 1 to size position to split it. 
3. if the left part is a palidrome, for the right part, recursively call the same function.
4. if not continue;
*/


class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> results;
        vector<string> partition;
        partitionAux(s, results, partition);
        
        return results;
    }
    
    
     void partitionAux(string s, 
                       vector<vector<string>> &results, 
                       vector<string> &partition){
         // cout << "string:[" << s << "]size:" << s.size() << endl;
         if(s.size() == 0){
             results.push_back(partition);
             return;
         }
         
         for(int i = 1; i <= s.size(); ++i){
             string left = s.substr(0, i);
             // cout << "left:" << left << endl;
             // cout << "right: " << s.substr(i) << endl;
             if(!(isPalindrome(left))){
                 continue;
             }
             partition.push_back(left);
             partitionAux(s.substr(i), results, partition);
             partition.pop_back();
         }  
    }
    
    bool isPalindrome(const string &s){
        for(int i = 0, j = s.size() -1; i < j; ++i, --j){
            if(s[i] != s[j]){
                return false;
            }
        }
        
        return true;
    }
    
    
    
};