#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
QUESTION 78 Subsets:
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

/*
SOLUTION:
(1) This problem can be solved by using DFS algorithm
(2) The root node is [] empty set and keep adding numbers
(3) In order to keep the results unique, we can make it
    sorted. To make them sorted, we can make a rule, only
    larger numbers can be added. To make it simple, we can
    sort the original vector at the begining, and only adding
    numbers at larger index
(4) we can implement it using recursion
(5) edge case, empty set
(6) recursion (a) the definition of the recursion(using one sentence to define the problem): find all the subsets which start with 			 the initial subset
		      (b) break down the problem( transform the question from n to n-1):  finding the subsets start with [ ] to finding 	                 the subsets start with [1] [2] [3] and [] itself
		      (c) the exit of the recursion
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> results;
        sort(nums.begin(),nums.end());
        vector<int> init_set{};
        size_t start_idx = 0;
        
        subsets_impl(nums,init_set,start_idx,results);
        
        return results;
    }
    
    void subsets_impl(const vector<int>& nums,vector<int> init_set,
                      size_t start_idx,vector<vector<int>> &results){
        results.push_back(init_set);
        
        for(;start_idx < nums.size(); ++start_idx){
            init_set.push_back(nums[start_idx]);
            subsets_impl(nums,init_set,start_idx+1,results);
            init_set.pop_back();
        }
    }
    
};

void print(vector<vector<int>> v){
	cout << "size of v is " << v.size() <<endl;
	for(auto i: v){
		cout << "[ " ;
		for(auto j:i){
			cout << j;
		}
		cout << " ]";
	}
	cout << endl;
}

int main()
{
    std::vector<int> v{1,2,3};
    Solution sol;
    auto result = sol.subsets(v);
    print(result);
}
