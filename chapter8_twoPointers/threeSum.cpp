/**
15. 3Sum

Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

*/

/**
 a < b < c
 loop through array find a smallest number , convert this problem to twoSum problem
 */




class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size() < 3){
            return result;
        }
        
        // small < mid < large
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-2; ++i){
            auto small = nums[i];
            if(i > 0 && small == nums[i-1]){
                continue;
            }
            
            twoSum(i+1, -small, nums, result);
        }
        
        return result;
    }
    
    void twoSum(int from, int target, vector<int>& nums, vector<vector<int>> &result){
        // cout << "-----------" << endl;
        // cout << "target : " << target << endl;
        int to = nums.size() - 1;
        while(from < to){
            // cout << "from :" << from << "to: " << to << endl;
            auto middle = nums[from];
            auto large = nums[to];
            if(middle + large == target){
                vector sol{-target, middle, large};
                result.push_back(sol);
                ++from;
                --to;
                while(from < to && nums[from] == nums[from - 1]){
                    ++from;
                }
                
                while(to > from && nums[to] == nums[to + 1]){
                    --to;
                }
            }
            else if(middle + large < target){
                ++from;
            }
            else{
                --to;
            }
        }
        
    }
    
};