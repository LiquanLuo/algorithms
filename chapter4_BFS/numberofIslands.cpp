/**
QUESTION:
200. Number of Islands

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3

*/

/**
 SOLUTION:
 1. use node struct
 2. after finding a new node, put it in the searched set immediately
 3. 
 */
int _rowLen;
int _columnLen;

class Solution {

public:
    struct Node{
        int x;
        int y;
        int ID;

        Node(int row, int col){
            x = row;
            y = col;
            ID = row * _columnLen + col;
        }  
    };
         
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        _rowLen = grid.size();
        if(_rowLen == 0){
            
            return result;
        } 
        _columnLen = (grid[0]).size();
        
        if(_columnLen == 0){
            
            return result;
        }
        unordered_set<int> searched;
        
        for(int row = 0; row < _rowLen; ++row){
            for(int col = 0; col < _columnLen; ++col){
                int ID = row * _columnLen + col;
                if(searched.find(ID) == searched.end()){// find a new spot 
                    searched.insert(ID);
                    if(grid[row][col] == '1'){            // new spot is island
                        ++result;                   
                        searchIsland(row,col,searched,grid);
                    }
                }
            }
        }
        
        return result;
    }
    
    
    void searchIsland(int row,
                      int col,
                      unordered_set<int> &searched, 
                      vector<vector<char>> &grid){
        Node start(row, col);
        queue<Node> nodeQueue;
        nodeQueue.push(start);
        while(!nodeQueue.empty()){
            auto node = nodeQueue.front();
            nodeQueue.pop();
            for(int i=0; i < 4; ++i){
                Node newNode = Node(node.x + DirX[i], node.y + DirY[i]);
                if(!validNode(newNode)){
                    continue;
                }

                if(searched.find(newNode.ID) == searched.end()){  
                    searched.insert(newNode.ID);
                    if(grid[newNode.x][newNode.y] == '1'){    // part of island     
                        nodeQueue.push(newNode);
                    }
                }
            }
            
        }
    }
    
    bool validNode(Node node){
        if(node.x >=0 && 
           node.x < _rowLen &&
           node.y < _columnLen&&
          node.y >=0){
            return true;
        }
        
        return false;
    }  
    
private:
    vector<int> DirX{0,1,0,-1};
    vector<int> DirY{1,0,-1,0};
};


