/**

64. Minimum Path Sum
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rowSize = grid.size();
        if(rowSize == 0){
            return 0;
        }
        
        int colSize = grid[0].size();
        vector<vector<int>> minSum;
        for(int row = 0; row < rowSize; ++row){
            vector<int> nums(colSize, 0);
            minSum.push_back(nums);
        }
        
        minSum[0][0] = grid[0][0];
        for(int row = 1; row < rowSize; ++row){
            minSum[row][0] = minSum[row - 1][0] + grid[row][0];
        }
        
        for(int col = 1; col < colSize; ++col){
            minSum[0][col] = minSum[0][col - 1] + grid[0][col];
        }
        
        for(int row = 1; row < rowSize; ++row){
            for(int col = 1; col < colSize; ++col){
                minSum[row][col]  = grid[row][col] + 
                    min(minSum[row - 1][col], minSum[row][col - 1]);
            }
        }
        
        // for(auto i : minSum){
        //     for(auto j: i){
        //         cout << " " << j << " ";
        //     }
        //     cout << endl;
        // }
        
        
        return minSum[rowSize - 1][colSize - 1];
        
    }
};  