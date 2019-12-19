/*

WOOD CUT
QUESTION:

Given n pieces of wood with length L[i] (integer array).
Cut them into small pieces to guarantee you could have equal 
or more than k pieces with the same length. What is the longest
length you can get from the n pieces of wood? Given L & k, return 
the maximum length of the small pieces.

Example
Example 1

Input:
L = [232, 124, 456]
k = 7
Output: 114
Explanation: We can cut it into 7 pieces if any piece is 114cm long, 
however we can't cut it into 7 pieces if any piece is 115cm long.
Example 2

Input:
L = [1, 2, 3]
k = 7
Output: 0
Explanation: It is obvious we can't make it.
Challenge
O(n log Len), where Len is the longest length of the wood.

*/

/*
SOLUTION:
(1) binary search result in range[0, longestwood]
(2) first we need to sort to get the longestwood, this cost O(nlogn) time
(3) we need to search in [0,longestwood], this costs O(log(Len))
(4) for each value retrived, we need to decide whether it meets the requirement, this cost O(n) 
(5) so the time complexity is O(nlogn) + O(n)*O(log(len)) = O(nlogn) + O(nlogLen)
*/



class Solution {
public:
    /**
     * @param logs: Given n pieces of wood with length L[i]
     * @param woodNeeded: An integer
     * @return: The maximum length of the small pieces
     */
    int woodCut(vector<int> &logs, int woodNeeded) {
        // if(woodNeeded == 0) ??? what should it return?
        if(logs.size() == 0 && woodNeeded != 0){
            return 0;
        }
        sort(logs.begin(),logs.end());
        
        auto longestwood = *(logs.end()-1);
        
        int start  = 0;
        int end = longestwood;
        int mid = 0;
        while(start + 1 < end){
            mid = start + (end - start)/2;
            if(canCut(logs,woodNeeded,mid)){    // start...mid...target...end
                start = mid;
            }
            else{                               // start...target...mid...end
                end = mid;
            }
        }
        
        if(canCut(logs,woodNeeded,end)){
            return end;
        }
        
        if(canCut(logs,woodNeeded,start)){
            return start;
        }
        
        return 0;
    }
    
    
    bool canCut(vector<int> &logs, int woodNeeded, int length){
        if(woodNeeded == 0 || length == 0){
            return true;
        }
        
        if(logs.size() == 0){
            return false;
        }
        
        int woodNumber = 0;
        for(auto log:logs){
            woodNumber += (log/length);
        }
        
        if(woodNumber >= woodNeeded){
            return true;
        }
        
        return false;
    }
};