/**
611. Valid Triangle Number

Given an array consists of non-negative integers, your task is to count the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.
Example 1:
Input: [2,2,3,4]
Output: 3
Explanation:
Valid combinations are: 
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3
Note:
The length of the given array won't exceed 1000.
The integers in the given array are in the range of [0, 1000].
Accepted

*/

class Solution {
public:
    // small <= mid <= large
    // small + mid > large  ==> {large | small + mid > large}
    int triangleNumber(vector<int>& nums) {
        int count = 0;
        sort(nums.begin(), nums.end());
        if(nums.size() < 3){
            return count;
        }
        
        for(int i = nums.size() - 1; i >= 2; --i){
            auto large = nums[i];
            findTri(large, i-1, nums, count);
        }
        
        return count;
    }
    
    void findTri(int large, int to,vector<int>& nums, int &count){
        int from = 0;
        while(from < to){
            if(nums[from] + nums[to] > large){
                count += (to - from);
                --to;
            }
            else{
                ++from;
            }
        }
    }
    
    

};