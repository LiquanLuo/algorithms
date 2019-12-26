
/**
107. Binary Tree Level Order Traversal II

Given a binary tree, return the bottom-up level order 
traversal of its nodes' values. (ie, from left to right, 
level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> results;
        if(root == nullptr){
            return results;
        }
        
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        while(!nodeQueue.empty()){
            vector<int> result;
            auto queueSize = nodeQueue.size();
            cout << queueSize << endl;
            for(; queueSize > 0; --queueSize){
                auto node = nodeQueue.front();
                nodeQueue.pop();
                result.push_back(node->val);
                cout << "node->val "<< node->val << endl;
                if(node->left != nullptr){
                    nodeQueue.push(node->left);
                }
                
                if(node->right != nullptr){
                    nodeQueue.push(node->right);
                }
            }
            
            results.push_back(result);
        }
        
        reverse(results.begin(), results.end());
        
        return results;
        
        
    }
};