/**
703. Kth Largest Element in a Stream
Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Your KthLargest class will have a constructor which accepts an integer k and an integer array nums, which contains initial elements from the stream. For each call to the method KthLargest.add, return the element representing the kth largest element in the stream.

Example:

int k = 3;
int[] arr = [4,5,8,2];
KthLargest kthLargest = new KthLargest(3, arr);
kthLargest.add(3);   // returns 4
kthLargest.add(5);   // returns 5
kthLargest.add(10);  // returns 5
kthLargest.add(9);   // returns 8
kthLargest.add(4);   // returns 8
Note:
You may assume that nums' length ≥ k-1 and k ≥ 1.

*/

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        _k = k;
        for(auto num : nums){
            add(num);
        }
    }
    
    int add(int val) {
        if(pq.size() < _k){
            pq.push(val);
        }
        else{
            auto kthNum = pq.top();
            if(val > kthNum){
                pq.pop();
                pq.push(val);
            }   
        }
        
        return pq.top();
    }
    
private:
    int _k;
    priority_queue<int, vector<int>, greater<int>> pq;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */