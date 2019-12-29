
/**
47. Permutations II


Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

*/


/**
SOLUTION:
if it is a duplicate num, it has to be added
after the previous SAME number has been added


 */

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> results;
        unordered_set<int> visited;
        vector<int> permutation;
        permuteAux(nums, visited, permutation, results);
        
        return results;
    }
    
    void permuteAux(vector<int>& nums, 
                    unordered_set<int> &visited,
                    vector<int> permutation,
                     vector<vector<int>> &results){
        if(permutation.size() == nums.size()){
            results.push_back(permutation);
            return;
        }

        for(int idx = 0; idx < nums.size(); ++idx){
            // cout << "idx: " <<idx <<  " val:"<<nums[idx] << endl;
            if(idx > 0 && 
               nums[idx] == nums[idx-1] && 
               visited.find(idx-1) == visited.end()){   
                // if it is a duplicate num, it has to be added
                // after the previous number has been added
                continue;
            }
            
            if(visited.find(idx) != visited.end()){
                continue;
            }
            
            visited.insert(idx);
            permutation.push_back(nums[idx]);
            permuteAux(nums, visited, permutation, results);
            visited.erase(idx);
            permutation.pop_back();
        }   
    }
};