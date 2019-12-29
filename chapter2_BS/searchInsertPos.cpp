/*
QUESTION:
35. Search Insert Position
Given a sorted array and a target value, return the 
index if the target is found. If not, return the index 
where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2
Example 2:

Input: [1,3,5,6], 2
Output: 1
Example 3:

Input: [1,3,5,6], 7
Output: 4
Example 4:

Input: [1,3,5,6], 0
Output: 0
*/


/*
SOLUTION:
(1) size == 0;
(2) target < nums[0]
(3) target > nums[size-1]
(4) nums[0] <= target <= nums[size-1]
*/


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size() == 0){
            return 0;
        }
        
        if(target < nums[0]){
            return 0;
        }
        
        if(target > nums[nums.size()-1]){
            return nums.size();
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
        
        return end;
        
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
        
        int ret = Solution().searchInsert(nums, target);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}