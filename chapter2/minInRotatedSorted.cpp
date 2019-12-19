
/*
QUESTION:
153. Find Minimum in Rotated Sorted Array
Suppose an array sorted in ascending order is rotated at 
some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

You may assume no duplicate exists in the array.

Example 1:

Input: [3,4,5,1,2] 
Output: 1
Example 2:

Input: [4,5,6,7,0,1,2]
Output: 0

*/

/*
SOLUTION:
(1) sorted array or single element
(2) min is the first element that is less or equal to the last element, binary search
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        //if(nums.size() == 0){} ????
        
        int numsSize = nums.size();
        int lastNum = nums[numsSize-1];
        if(nums[0] <= lastNum){     //sorted or single element
            return nums[0];
        }
        
        int start = 0;
        int end = numsSize - 1;
        int mid = 0;
        while(start+1 < end){
            mid = start + (end - start)/2;
            if(nums[mid] <= lastNum){   // start...min...mid...end
                end = mid;
            }
            else{                       // start...mid...min...end
                start = mid;
            }
        }
        
        if(nums[start] <= lastNum){
            return nums[start];
        }
        
        return nums[end];
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

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        int ret = Solution().findMin(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}