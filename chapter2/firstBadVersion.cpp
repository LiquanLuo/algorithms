/*
QUESTION:
278. First Bad Version

You are a product manager and currently leading a team to develop 
a new product. Unfortunately, the latest version of your product 
fails the quality check. Since each version is developed based 
on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out
the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return
whether version is bad. Implement a function to find the first bad 
version. You should minimize the number of calls to the API.

Example:

Given n = 5, and version = 4 is the first bad version.

call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true

Then 4 is the first bad version. 

*/


/*
SOLUTION:
binary search, find the smallest i that is bad version.
*/



// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        int start = 1;
        int end = n;
        int mid = 1;
        
        while(start + 1 < end){
            mid = start + (end - start)/2;
            if(isBadVersion(mid)){  //start...target...mid...end
                end = mid;
            }
            else{                   //start...mid...target...end
                start = mid;
            }
        }
        
        if(isBadVersion(start)){
            return start;
        }
        
        return end;
        
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        getline(cin, line);
        int bad = stringToInteger(line);
        
        int ret = Solution().firstBadVersion(n, bad);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}