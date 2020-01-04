/**
349. Intersection of Two Arrays


Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Note:

Each element in the result must be unique.
The result can be in any order.
*/

/**
SOLUTION1:
HASH SET
time: O(n)  space: O(n)

SOLUTION2:
SORT
time: nlogn + mlogn   space: O(1)

 */

class Solution {
public:
//     // hash set 
//     //time: O(n)  space: O(n)
//     vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> result;
//         unordered_set<int> numSet;
//         for(auto num:nums1){
//             numSet.insert(num);
//         }
        
//         for(auto num:nums2){
//             if(numSet.find(num) != numSet.end()){
//                 result.push_back(num);
//                 numSet.erase(num);
//             }
//         }

//         return result;
//     }
    
    
// sort array and merge 
// time: nlogn + mlogn   space: O(1)
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0;
        int j = 0;
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] == nums2[j]){
                result.push_back(nums1[i]);
                ++i;
                while(i < nums1.size()){
                    if(nums1[i] != nums1[i-1]){
                        break;
                    }
                    ++i;
                }
                
                ++j;
            }
            else if(nums1[i] < nums2[j]){
                ++i;
            }
            else{
                ++j;
            }
        }
        
        return result;
       
        
        
        
    
    }
};