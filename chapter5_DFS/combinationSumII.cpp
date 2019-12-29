/**

40. Combination Sum II


Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]

**/

/**
SOLUTION:
1. DFS
2. remove duplicates in the same level

*/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        sort(candidates.begin(), candidates.end());
        int startIdx = 0;
        int sum = 0;
        vector<int> combin;
        combinationSum2Aux(candidates, target, results, startIdx, sum, combin);
        return results;
    }
    
    void combinationSum2Aux(vector<int> &candidates, 
                            int target, 
                            vector<vector<int>> &results, 
                            int startIdx, 
                            int sum,
                            vector<int> combin){
        if(sum == target){
            results.push_back(combin);
        }
        
        for(int i = startIdx; i < candidates.size(); ++i){
            int curVal = candidates[i];
            if(i != startIdx && curVal == candidates[i-1]){ 
                // remove duplicates in the same level
                continue;
            }
            
            if(sum + curVal > target){
                continue;
            }
            combin.push_back(curVal);
            combinationSum2Aux(candidates, target, results, i + 1,
                               sum + curVal, combin);
            combin.pop_back();
        }
        
    }
};


