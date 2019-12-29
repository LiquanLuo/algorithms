/*
QUESTION:
74. Search a 2D Matrix
Write an efficient algorithm that searches for a value in an m x n matrix. 
This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
Example 1:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true
*/


/*
SOLUTION:
Regarding the matrix as an array and using the binary search
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        _rowSize = matrix.size();
        if(_rowSize == 0){
            return false;
        }
        
        _columnSize = matrix[0].size();
        
        if(_columnSize == 0){
            return false;
        }
        
        int start = 0;
        int end = _rowSize * _columnSize -1;
        int mid = 0;
        while(start + 1 < end){
            mid = start + (end - start)/2;
            auto midValue = getValue(matrix,mid);
            if(midValue == target){
                return true;
            }
            else if(midValue < target){ // start...mid..target...end
                start = mid;
            }
            else{                       // start...target...mid...end
                end = mid;
            }
        }
        
        if(getValue(matrix,start) == target){
            return true;
        }
        
        if(getValue(matrix,end) == target){
            return true;
        }
        
        return false;
        
        
        
    }
    
    int getValue(vector<vector<int>>& matrix, int index){
        int rowNumber = index / _columnSize;
        int columnNumber = index % _columnSize;
        return matrix[rowNumber][columnNumber];
    }
    
private:
    int _rowSize = 0;
    int _columnSize = 0;
    
};