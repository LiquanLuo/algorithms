/**
51. N-Queens

The n-queens puzzle is the problem of placing n queens on an n×n 
chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, 
where 'Q' and '.' both indicate a queen and an empty space respectively.

Example:

Input: 4
Output: [
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.


*/

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>>solutions;
        vector<int> solution;
        int rowNum = 0;
        solveNQueensAux(n, solution, solutions, rowNum);
        auto results = drawChessBorad(solutions, n);
        return results;
    }
    
    vector<vector<string>> drawChessBorad(vector<vector<int>> &solutions,
                                         int n){
        vector<vector<string>> results;
        for(auto solution : solutions){
            // cout << "---------" << endl;
            vector<string> result;
            for(int col = 0; col < n; ++col){
                int queenPlace = solution[col];
                string colStr(n,'.');
                colStr[queenPlace] = 'Q';
                result.push_back(colStr);
                // cout << colStr << endl;
            }
            // cout << "---------" << endl;
            results.push_back(result);
        }
        
        return results;
    }
        
    
    void solveNQueensAux(int n, 
                         vector<int> &solution,
                         vector<vector<int>> &solutions,
                         int rowNum){
        if(rowNum >= n){
            solutions.push_back(solution);
            return;
        }
        
        for(int i = 0; i < n; ++i){
            if(validSolution(solution, rowNum, i)){
                solution.push_back(i);
                solveNQueensAux(n, solution, solutions, rowNum+1);
                solution.pop_back();
            }
        }
    }
    
    // test if put Queen in (x, y) is valid
    bool validSolution(const vector<int> &solution,
                       int x,
                       int y){
        for(int row = 0; row < solution.size(); ++row){
            int col = solution[row];
            if(col == y){               // same column
                return false;
            }  
            
            if( row + col == x + y){    // diagonally attack
                return false;
            }
            
            if( row - col == x - y){    // diagonally attack
                return false;
            }
            
        }
        
        return true;
    }

};