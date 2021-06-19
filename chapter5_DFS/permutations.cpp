
/**
46. Permutations


Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

*/

// 1.definition: find all the permutations and add them into results
// 2.n -> n - 1: for permutation of n numbers, add any un-visited number into current permutation, then find permutaiton of n-1 numbers
// 3. exit: if current permutation contains all the numbers, add it to results


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
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

        for(auto num: nums){
            if(visited.find(num) != visited.end()){
                continue;
            }
            visited.insert(num);
            permutation.push_back(num);
            permuteAux(nums, visited, permutation, results);
            visited.erase(num);
            permutation.pop_back();
        }

        
    }
    
    
    
};
