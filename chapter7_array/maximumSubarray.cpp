/**
53. Maximum Subarray

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
*/

/**
solution:
maximum subarray ended with k = presum(n) - minimal_presum_to_n
 */



class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int minPreSum = 0;
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i];
            maxSum = max(maxSum, sum - minPreSum);
            minPreSum = min(minPreSum, sum);
            // cout << "sum: " << sum << " maxsum: " <<
            //     maxSum << " min: " << minPreSum << endl;
        }
    
        return maxSum;
    }
};