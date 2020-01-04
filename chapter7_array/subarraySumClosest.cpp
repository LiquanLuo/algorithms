/*
139. Subarray Sum Closest


Given an integer array, find a subarray with sum closest to zero. Return the indexes of the first number and last number.

Example
Example1

Input: 
[-3,1,1,-3,5] 
Output: 
[0,2]
Explanation: [0,2], [1,3], [1,1], [2,2], [0,4]
Challenge
O(nlogn) time

**/

/**
1. get the presum array
2. sort array
3. compare the adjacent elements
 */


class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    // target is k, k > 0
    // vector<int> subarraySumClosest(vector<int> &nums) {
    //     int target = 0;
    //     // presum can be equal, so multimap is needed
    //     // <presum, index> 
    //     multimap<int, int> preSumMap;        
    //     preSumMap.insert(pair<int,int>(0,-1));
    //     int sum = 0;
    //     for(int i = 0; i < nums.size(); ++i){
    //         sum += nums[i];
    //         preSumMap.insert(pair<int,int>(sum, i));
    //     }
        
    //     multimap<int,int>::iterator from = preSumMap.begin();
    //     auto to = preSumMap.begin();
    //     ++to;
    //     int minDiff = INT_MAX;
    //     int minFrom = -1;
    //     int minTo = 0;
    //     while(from != preSumMap.end()){
    //         while(to->first - from->first <= target && to != preSumMap.end()){
    //             // cout << " from_val: " << from->first  << 
    //             //         " from_idx: " << from->second <<
    //             //         " to_val: " << to->first  << 
    //             //         " to_idx: " << to->second << endl;
                     
    //             auto diff = to->first - from->first;
    //             if(diff < minDiff && from != to){
    //                 minDiff = diff;
    //                 minFrom = min(from->second, to->second);    // the order does not matter
    //                 minTo = max(from->second, to->second);
    //             }
    //             ++to;
    //         }
            
    //         if(to != preSumMap.end()){
    //             // cout << " from_val: " << from->first  << 
    //             //         " from_idx: " << from->second <<
    //             //         " to_val: " << to->first  << 
    //             //         " to_idx: " << to->second << endl;
    //             auto diff = to->first - from->first;
    //             if(diff < minDiff && from != to){
    //                 minDiff = diff;
    //                 minFrom = min(from->second, to->second);
    //                 minTo = max(from->second, to->second);
    //             }
    //         }else{
    //             --to;
    //         }
            
    //         ++from;
    //     }
        
    //     cout << minDiff << endl;
    //     vector<int> result;
    //     result.push_back(minFrom+1);
    //     result.push_back(minTo);
        
    //     return result;
        
    // }
    
    // targe is 0, only need to compare the diff of adjacent elements
    vector<int> subarraySumClosest(vector<int> &nums) {
        multimap<int, int> preSumMap;
        preSumMap.insert(pair<int,int>(0,-1));      // <presum,index>
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i];
            preSumMap.insert(pair<int,int>(sum,i));
            
        }
        
        auto from = preSumMap.begin();
        auto to = preSumMap.begin();
        ++to;
        int minDiff = INT_MAX;
        int minFrom = -1;
        int minTo = 0;
        while(to != preSumMap.end()){
            if(to->first - from->first < minDiff){
                minDiff = to->first - from->first;
                minFrom = min(to->second, from->second);
                minTo = max(to->second, from->second);
            }
            ++from;
            ++to;
        }
        
        vector<int> result;
        result.push_back(minFrom + 1);
        result.push_back(minTo);
        return result;
    }
};