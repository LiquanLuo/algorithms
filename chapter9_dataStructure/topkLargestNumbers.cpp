/**
544. Top k Largest Numbers

Given an integer array, find the top k largest numbers in it.

Example
Example1

Input: [3, 10, 1000, -99, 4, 100] and k = 3
Output: [1000, 100, 10]
Example2

Input: [8, 7, 6, 5, 4, 3, 2, 1] and k = 5
Output: [8, 7, 6, 5, 4]
*/

class Solution {
public:
    /**
     * @param nums: an integer array
     * @param k: An integer
     * @return: the top k largest numbers in array
     */
    vector<int> topk(vector<int> &nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto num : nums){
            if(pq.size() < k){
                pq.push(num);
                continue;
            }
            
            auto minNum = pq.top();
            if(num > minNum){
                pq.pop();
                pq.push(num);
            }
        }
        
        vector<int> result;
        while(!pq.empty()){
            auto num = pq.top();
            pq.pop();
            result.push_back(num);
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};