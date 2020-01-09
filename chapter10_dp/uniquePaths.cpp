/**
62. Unique Paths
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Above is a 7 x 3 grid. How many possible unique paths are there?

Note: m and n will be at most 100.

Example 1:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right
Example 2:

Input: m = 7, n = 3
Output: 28

 */

/**
state: number of paths to this point
func: f(x, y) = f(x - 1, y) + f(x, y - 1)
initial: f(1, 1) == f(x, 1) == f(1, y) == 1
return: f(colSize, rowSize)
 */

class Solution {
    using Node = pair<int,int>;

    struct NodeHash{
        size_t operator()(Node node) const{
            return node.first + node.second;
        }
    };
    
public:
    int uniquePaths(int colSize, int rowSize) {
        unordered_map<Node, int, NodeHash> pathNum;
        pathNum[Node(1,1)] = 1;
        for(int col = 1; col <= colSize; ++col){
            pathNum[Node(1,col)] = 1;
        }
        
        for(int row = 1; row <= rowSize; ++row){
            pathNum[Node(row,1)] = 1;
        }
        
        for(int row = 2; row <= rowSize; ++row){
            for(int col = 2; col <= colSize; ++col){
                pathNum[Node(row, col)] = pathNum[Node(row - 1, col)] + 
                    pathNum[Node(row, col - 1)];
            }
        }
        
        return pathNum[Node(rowSize, colSize)];
        
    }
};