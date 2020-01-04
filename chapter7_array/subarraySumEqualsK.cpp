/*
560. Subarray Sum Equals K


Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2
Note:
The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].

*/

/**
SOLUTION 1:
BRUTE FORCE
time: O(n2)  space: O(1)

SOLUTION 2:
hash map
time: O(n)   space: O(n)

 */

class Solution {
public:
    // Brute Force
//     int subarraySum(vector<int>& nums, int k) {
//         int count = 0;
        
//         for(int start = 0; start < nums.size(); ++start){
//             int sum = 0;
//             for(int end = start; end < nums.size(); ++end){
//                 sum += nums[end];
//                 // cout << sum << endl;
//                 if(sum == k){
//                     ++count;
//                 }
//             }
//         }
        
//         return count;
//     }
    
    
    // hash map
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> presumMap;
        int count = 0;
        int sum = 0;
        presumMap[0] = 1;
        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i];
            
            if(presumMap.find(sum - k) != presumMap.end()){
                count += presumMap[sum - k];
            }
            
            if(presumMap.find(sum) != presumMap.end()){
                ++presumMap[sum];
            }
            else{
                presumMap[sum] = 1;
            }
            
        }
        
        return count;
    }
};