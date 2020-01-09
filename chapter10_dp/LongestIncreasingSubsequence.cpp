/**
300. Longest Increasing Subsequence

Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
Note:

There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?

*/

/**
 state: f(x) =  LIS ended with xth element
 function: f(x) = max(f(i)) + 1 | i < x, n[i] < n[x]
 initial: f(0) = 1
 return : max(f(x))
 */

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        vector<int> LIS(nums.size(), 1);
        for(int last = 1; last < nums.size(); ++last){
            for(int pre = last - 1; pre >= 0; --pre){ 
                if(nums[pre] >= nums[last]){
                    continue;
                }
                
                LIS[last] =  max(LIS[last],LIS[pre] + 1);
            }
        }
        
        int maxLIS = 1;
        for(auto i: LIS){
            maxLIS = max(maxLIS, i);
        }
        
        return maxLIS;
    }
};