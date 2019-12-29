/*
162. Find Peak Element

A peak element is an element that is greater than its neighbors.

Given an input array nums, where nums[i] ≠ nums[i+1], find a peak 
element and return its index.

The array may contain multiple peaks, in that case return the index
to any one of the peaks is fine.

You may imagine that nums[-1] = nums[n] = -∞.

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 1 or 5 
Explanation: Your function can return either index number 1 where the peak element is 2, 
             or index number 5 where the peak element is 6.



*/

/*
SOLUTION:
(1) size == 1, return 0
(2) binary search the whole array, there are four possible situations
    a. peak, return 
    b. increasing, peak is on the right
    c. decreasing, peak is on the left
    d. valley, one peak on the right and one peak on the left
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // if(nums.size() == 0) {}????
        if(nums.size() == 1){
            return 0;
        }
        
        int start = 0;
        int end = nums.size()-1;
        int mid = 0;
        while(start + 1 < end){
            mid = start + (end - start)/2;
            if(isPeak(nums, mid)){
                return mid;
            }
            else if(isIncreased(nums,mid)){ // start...mid...peak...end
                start = mid;
            }
            else{       
                // start...peak...mid...end 
                // or start...peak...mid...peak...end
                end = mid;
            }
        }     
        
        
        if(isPeak(nums,start)){
            return start;
        }
        
        if(isPeak(nums,end)){
            return end;
        }
        
        return -1;
        
    }
    
    bool isIncreased(vector<int>& nums, int index){
        if(index == 0){
            if(nums[index] < nums[index + 1]){
                return true;
            }
            else{
                return false;
            }
        }
        
        if(index == (nums.size()-1)){
            if(nums[index] > nums[index - 1]){
                return true;
            }
            else{
                return false;
            }
        }
        
        if(nums[index] < nums[index + 1] &&
          nums[index] > nums[index - 1])
        {
            return true;
        }
        
        return false; 
    }
    
    
    bool isPeak(vector<int>& nums, int index){
        if(index == 0){
            if(nums[index] > nums[index + 1]){
                return true;
            }
            else{
                return false;
            }
        }
        
        if(index == (nums.size()-1)){
            if(nums[index] > nums[index - 1]){
                return true;
            }
            else{
                return false;
            }
        }
        
        if(nums[index] > nums[index + 1] &&
          nums[index] > nums[index - 1])
        {
            return true;
        }
        
        return false; 
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
        
        int ret = Solution().findPeakElement(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}