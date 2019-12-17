/*

28. Implement strStr()
Implement strStr().

Return the index of the first occurrence of needle in haystack,
 or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2

*/

/*
Clarification:

What should we return when needle is an empty string?
This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. 
This is consistent to C's strstr() and Java's indexOf().

*/

/*
(1) Is it possible that the needle string is longer than the haystack?
(2) Remember to create basic test cases
*/

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0){
            return 0; 
        }
        
        if(needle.size() > haystack.size()){
            return -1;
        }
            
        for(int i = 0; i < haystack.size(); ++i){
            bool diff_flag = false;
            for(int k = i, j = 0; j < needle.size(); ++j,++k){
                if(haystack[k] != needle[j]){
                    diff_flag = true;
                    break;
                }    
            }
            
            if(!diff_flag){
                return i;
            }     
        }
        
        return -1;     
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string haystack = stringToString(line);
        getline(cin, line);
        string needle = stringToString(line);
        
        int ret = Solution().strStr(haystack, needle);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}