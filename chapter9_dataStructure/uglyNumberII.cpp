/**
264. Ugly Number II

Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

Example:

Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
Note:  

1 is typically treated as an ugly number.
n does not exceed 1690.


**/

/**
 1. use pq, get the min, and push min * 2, min * 3, min * 5 back to the pq
 2. use set to avoid duplicate
 3. use long instead of int
 */


class Solution {
    
public:
    int nthUglyNumber(int n) {
        priority_queue<long, vector<long>, greater<long>> pq;
        unordered_set<long> numSet;
        pq.push(1);
        numSet.insert(1);
        while(--n > 0){
            auto num = pq.top();
            pq.pop();
            if(numSet.find(num * 2) == numSet.end()){
                pq.push(num * 2);
                numSet.insert(num * 2);
            }
            
            if(numSet.find(num * 3) == numSet.end()){
                pq.push(num * 3);
                numSet.insert(num * 3);
            } 
            
            if(numSet.find(num * 5) == numSet.end()){
                pq.push(num * 5);
                numSet.insert(num * 5);
            }
        }
        
        return pq.top();
    }
};