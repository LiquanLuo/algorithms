/**
63. Unique Paths II

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Note: m and n will be at most 100.

Example 1:

Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
*/

/**
 solution:
 use long!
 */

class Solution {

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rowSize = obstacleGrid.size();
        if(rowSize == 0){
            return 0;
        }
    
        int colSize = obstacleGrid[0].size();
        vector<vector<long>> pathNum;
        for(int i = 0; i < rowSize; ++i){
            vector<long> row(colSize,0);
            pathNum.push_back(row);
        }
        
        bool obsFlg = false;
        for(int row = 0; row < rowSize; ++row){
            if(obstacleGrid[row][0] == 1 || obsFlg){
                obsFlg = true;
                pathNum[row][0] = 0;
            }
            else{
                pathNum[row][0] = 1;
            }
        }
        
        obsFlg = false;
        for(int col = 0; col < colSize; ++col){
            if(obstacleGrid[0][col] == 1 || obsFlg){
                obsFlg = true;
                pathNum[0][col] = 0;
            }
            else{
                pathNum[0][col] = 1;
            }
        }
        
        for(int row  = 1; row < rowSize; ++row){
            for(int col = 1; col < colSize; ++ col){
                if(obstacleGrid[row][col] == 1){
                    pathNum[row][col] = 0;
                }
                else{
                    pathNum[row][col] = pathNum[row - 1][col] + pathNum[row][col - 1];
                }
                
            }
        }
    
        return pathNum[rowSize - 1][colSize - 1];
        
    }
};