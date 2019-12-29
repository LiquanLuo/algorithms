
/**
QUESTION:
 102. Binary Tree Level Order Traversal

 Given a binary tree, return the level order traversal of 
 its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
*/

/**
 * Definition for a binary tree node.


 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        levelOrderAux(root, 0);
        return result;
    }
    
    void levelOrderAux(TreeNode* root, int depth) {
        if(root == nullptr){
            return;
        }
        
        if(depth >= result.size()){
            vector<int> newDepth{root->val};
            result.push_back(newDepth);
        }
        else{
            result[depth].push_back(root->val);
        }
        
        levelOrderAux(root->left, depth+1);
        levelOrderAux(root->right, depth+1);
    }
    
private:
    vector<vector<int>> result;
};