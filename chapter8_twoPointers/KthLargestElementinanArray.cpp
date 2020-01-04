/**
215. Kth Largest Element in an Array
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5
Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/

/**
 solution: quick selection
 partition the array
 */

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargestAux(nums, k, 0, nums.size() - 1);
    }
    
    int findKthLargestAux(vector<int>& nums, int k, int start, int end){
        // cout << "k: " << k << "start: " << start << "end: " << end << endl;
        
        if(end - start + 1 == 1 ){
            return nums[start];
        }
        
        auto pivot = nums[start];
        auto pivotIdx = start;
        auto to = end;
        auto from = start + 1;
    
        while(from < to){
            while(nums[from] <= pivot && from < to){
                ++from;
            }
            
            while(nums[to] >= pivot && to > from){
                --to;
            }
            
            swap(nums[from], nums[to]);
        }
        
        if(nums[from] <= pivot){
            swap(nums[from], nums[start]);
            pivotIdx = from;
            ++from;
            // cout << "pivot go to from" << endl;
        }
        else{
            swap(nums[from - 1], nums[start]);
            pivotIdx = from -1;
            // cout << "pivot go to from-1" << endl;
        }
        // cout << "from: " << from << endl;
        // cout << "to: " << to << endl;
        // for(auto num: nums){
        //     cout << num << ", " ;
        // }
        // cout << endl;
        // cout << "-----------" << endl;
        
        if(end - pivotIdx + 1 == k){
            return pivot;
        }
        else if(end - pivotIdx + 1 > k){
            return findKthLargestAux(nums, k, pivotIdx + 1, end);
        }
        else {
            return findKthLargestAux(nums, k - (end - pivotIdx + 1), start, pivotIdx - 1);
        }
        
        
    }
    

};