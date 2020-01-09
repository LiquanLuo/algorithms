/**
120. Triangle

Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:

Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

**/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int triSize = triangle.size();
        if(triSize == 0){
            return 0;
        }        
        
        vector<vector<int>> minSum;
        for(int row = 0; row < triSize; ++row){
            vector<int> nums(triSize, 0);
            minSum.push_back(nums);
        }
        
        minSum[0][0] = triangle[0][0];
        for(int row = 1; row < triSize; ++row){
            minSum[row][0] =  minSum[row - 1][0] + triangle[row][0];
            minSum[row][row] = minSum[row - 1][row - 1] + triangle[row][row];
        }
        
        for(int row = 2; row < triSize; ++row){
            for(int col = 1; col < row; ++ col){
                minSum[row][col] = min(minSum[row - 1][col - 1], 
                                       minSum[row - 1][col]) +
                    triangle[row][col];
            }
        }
        
        int result = INT_MAX;
        for(int i = 0; i < triSize; ++i){
            result = min(result, minSum[triSize - 1][i]);
        }
        
        return result;
    }
};