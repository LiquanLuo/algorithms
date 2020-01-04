/**
4. Median of Two Sorted Arrays

There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/

/**
solution:
prefer to use the recursion
try to find kth number in two sorted array
comparing the start1+k/2 and start2+ k/2 and decide which k/2 number can be removed,
and then in the next recursion, we only need to find k/2th number in the rest numbers
 */


class Solution {
public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         if(nums1.size() > nums2.size()) // compare the size of two vectors
//             return _findMedianSortedArrays(nums2,nums1);
//         else
//             return _findMedianSortedArrays(nums1,nums2);
//     }
    
//     double _findMedianSortedArrays(vector<int>& shortVec, vector<int>& longVec) {
//         int shortLen = shortVec.size();     // search in the shorter vector
//         int longLen = longVec.size();
//         int shortIdx = 0,longIdx = 0;
//         int iMin = 0, iMax = shortLen;
//         int halfLen = (shortLen + longLen + 1)/2;   
//         while(iMin <= iMax)
//         {
//             shortIdx = (iMin + iMax)/2;     // binary search
//             // divde two vectors into two parts with sizes
//             // all the nums in the left part are smaller than the 
//             // nums in the right part
//             longIdx = halfLen - shortIdx;   
//             if(shortIdx < iMax && 
//                shortVec[shortIdx] <= longVec[longIdx-1])    // too small
//             {
//                 iMin = shortIdx +1;
//             }
//             else if(shortIdx > iMin && 
//                shortVec[shortIdx-1] >= longVec[longIdx])    // too large
//             {
//                 iMax = shortIdx -1;
//             }
//             else
//             {
//                 double leftMax = 0.0, rightMin = 0.0;
//                 // all the nums in the shorter vec are in the right part
//                 if(shortIdx == 0)   
//                     leftMax = longVec[longIdx-1];
//                 // all the nums in the longer vec are in the right part
//                 else if(longIdx == 0)
//                     leftMax = shortVec[shortIdx-1];
//                 else
//                 {
//                     leftMax = max(longVec[longIdx-1],shortVec[shortIdx-1]);
//                 }
                
//                 if((shortLen + longLen) % 2)
//                     return leftMax;
                
//                 if(shortIdx == shortLen)
//                     rightMin = longVec[longIdx];
//                 else if(longIdx == longLen)
//                     rightMin = shortVec[shortIdx];
//                 else
//                 {
//                     rightMin = min(longVec[longIdx],shortVec[shortIdx]);
//                 }
                
//                 return (leftMax+rightMin)/2;
                
//             }
//         }
        
//         return 0.0;
//     }
    
    
    // recursion
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int num1Size = nums1.size();
        int num2Size = nums2.size();
        auto totalSize = num1Size + num2Size;
        if(totalSize % 2 == 0){  // even size, find two and get average
            auto num1 = findKth(totalSize/2, nums1, 0, num1Size, nums2, 0, num2Size);
            auto num2 = findKth(totalSize/2 + 1,  nums1, 0, num1Size, nums2, 0, num2Size);
            auto median = (num1 + num2)/2;
            return median;
        }
        else{               // odd, find middle one
            return findKth(totalSize/2 + 1, nums1, 0, num1Size, nums2, 0, num2Size);
        }
    }
    
    
    double findKth(int k, 
                   vector<int>& nums1, int start1, int end1, 
                   vector<int>& nums2, int start2, int end2){
        // cout << " k: " << k << " s1: " <<start1 << 
        //     " end1:  " << end1 << " start2:   " <<
        //     start2  << " end2:  " << end2 << endl;
        if(start1 >= end1){
            return nums2[start2 + k -1];
        }
        
        if(start2 >= end2){
            return nums1[start1 + k -1];
        }
        
        if(k == 1){
            cout << "result: " << min(nums1[start1], nums2[start2]) << endl;
            return min(nums1[start1], nums2[start2]);
        }
        
        if(start1 + k/2 -1 >= end1){
            return findKth(k - k/2,  nums1, start1, end1, nums2, start2 + k/2, end2);
        }
        
        if(start2 + k/2 -1 >= end2){
            return findKth(k - k/2,  nums1, start1 + k/2, end1, nums2, start2, end2);
        }
        
        if(nums1[start1 + k/2 -1] < nums2[start2 + k/2 -1]){
            return findKth(k - k/2,  nums1, start1 + k/2, end1, nums2, start2, end2);
        }
        else{
            return findKth(k - k/2,  nums1, start1, end1, nums2, start2 + k/2, end2);
        }
    }
};