
/**

16. 3Sum Closest
Given an array nums of n integers and an integer target, find three integers 
in nums such that the sum is closest to target. Return the sum of the three 
integers. You may assume that each input would have exactly one solution.

Example:

Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

 */

/**
 solution:
 convert the problem to two sum closest
 */



class Solution {
public:
    // a <= b <= c
    int threeSumClosest(vector<int>& nums, int target) {
        int minDiff = INT_MAX;
        int result = 0;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size() - 2; ++i){
            int small = nums[i];
            auto closestTwoSum = twoSumClosest(target - small, i + 1, nums);
            // cout << "close to " << target-small << " is :" << closestTwoSum << endl;
            if(abs(closestTwoSum + small - target) < minDiff){
                minDiff = abs(closestTwoSum + small - target);
                result = closestTwoSum + small;
            }
        }
        
        return result;
    }
    
    
    int twoSumClosest(int target, int from, vector<int>& nums){
        int minDiff = INT_MAX;
        int result = 0;
        int to = nums.size() - 1;
        while(from < to){
            int sum = nums[from] + nums[to];
            if( sum == target){
                return target;
            }
            else if (sum < target){
                if(abs(sum - target) < minDiff){
                    minDiff = abs(sum - target);
                    result = sum;
                }  
                
                ++from;
            }else{
                if(abs(sum - target) < minDiff){
                    minDiff = abs(sum - target);
                    result = sum;
                }   
                
                --to;
            }
        }
        
        return result;
    }
    
};