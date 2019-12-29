/*
QUESTION:
33. Search in Rotated Sorted Array

Suppose an array sorted in ascending order is rotated at some 
pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array 
return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1


*/

/*
SOLUTION:
using binary search, there are four situations
a. mid is on the left of minimum(mid > end)
(1) start...target...mid...minimum...end
(2) start...mid..target...minimum...end

b. mid is on the right of minimum(mid <= end)
(3) start...minimum...mid...target...end
(4) start...minimum...target...mid...end

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
            
            if(nums[mid] > nums[end]){  // on the left of minimum
                if(nums[mid] > target && target >= nums[start]){
                    // start...target...mid...minimum...end
                    end = mid;
                }
                else{
                    // start...mid..target...minimum...end
                    start = mid;
                }
            }
            else{                       // on the right of minimum
                if(nums[mid] < target && target <=nums[end]){
                    // start...minimum...mid...target...end
                    start = mid;
                }
                else{
                    // start...minimum...target...mid...end
                    end = mid;
                }
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