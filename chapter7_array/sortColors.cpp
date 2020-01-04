/**
75. Sort Colors

Given an array with n objects colored red, white or blue, sort them
 in-place so that objects of the same color are adjacent, with the colors 
 in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, 
and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Follow up:

A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite 
array with total number of 0's, then 1's and followed by 2's.
Could you come up with a one-pass algorithm using only constant space?
*/

/**
solution:
1. count sort
2. three pointers
 */

class Solution {
public:
//     // three pointers
//     void sortColors(vector<int>& nums) {
//         int start = 0;
//         int end = nums.size() - 1;
//         int cur = 0;
//         while(cur <= end){
//             if(nums[cur] == 0){
//                 swap(nums[cur], nums[start]);
//                 ++cur;
//                 ++start;
//             }
//             else if(nums[cur] == 2){
//                 swap(nums[cur], nums[end]);
//                 --end;
//             }
//             else{
//                 ++cur;
//             }
//         }
//     }
    
    // count sort
     void sortColors(vector<int>& nums){
         vector<int> count(3,0);
         for(auto i:nums){
             ++count[i];
         }
         
         int i = 0;
         while(i < count[0] ){
             nums[i] = 0;
             ++i;
         }
         
         while(i < count[0] + count[1] ){
             nums[i] = 1;
             ++i;
         }
         
         while(i < (count[0] + count[1] + count[2]) ){
             nums[i] = 2;
             ++i;
         }
         
         
     }
    
};