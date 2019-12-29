/*
QUESTION:
704. Binary Search
Given a sorted (in ascending order) integer array nums of n elements 
and a target value, write a function to search target in nums. 
If target exists, then return its index, otherwise return -1.


Example 1:

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
*/



/*
SOLUTION:

(1) sorted 
(2) any/first/last position?
(3) O(logn) <——> binary search 
(4) too deep recursion, stack overflow
(5) start + 1 < end (start < end can cause infinite loop, [2,2] find last 2)
(6) instead of using (start + end)/2, use  start+(end-start)/2, prevent overflow
(7) A[mid], < , > , ==
(8) A[start] A[end] ? target
(9) xxxxooooo, find the first o, or the last x

*/


class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0){
            return -1;
        }
            
        int start = 0;
        int end = nums.size()-1;
        int mid = 0;
        while(start + 1 < end){
            mid = start + (end - start)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){    // start...mid...target...end
                start = mid;
            }
            else{                           // start...target...mid...end
                end = mid;
            }
        }
        
        if(nums[start] == target){
            return start;
        }
        
        if(nums[end] == target){
            return end;
        }
        
        return -1;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);
        
        int ret = Solution().search(nums, target);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}