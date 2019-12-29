/*

39. Combination Sum


Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]

**/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> results;
        sort(candidates.begin(), candidates.end());
        vector<int> combination;
        int sum = 0;
        int startIdx = 0;
        combinationSumAux(candidates,target,results,combination,sum,startIdx);
        return results;
    }
    
    // DFS
    void combinationSumAux(vector<int> &candidates,
                           int target,
                           vector<vector<int>> &results,
                           vector<int> &combination,
                           int sum,
                           int startIdx){
        if(sum == target){
            results.push_back(combination);
            return;
        }
        
        for(; startIdx < candidates.size(); ++startIdx){
            int currentVal = candidates[startIdx];
            if(sum + currentVal > target){
                continue;
            }
            
            combination.push_back(currentVal);
            combinationSumAux(candidates,target,results,combination,sum +
                              currentVal,startIdx);
            combination.pop_back();
        }
        
        
    }
};

