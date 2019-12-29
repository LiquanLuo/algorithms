/**
103. Binary Tree Zigzag Level Order Traversal
Given a binary tree, return the zigzag level order traversal 
of its nodes' values. (ie, from left to right, then right to 
left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> results;
        if(root == nullptr){
            return results;
        }
        
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        bool leftFlg = true;
        while(!nodeQueue.empty()){   
            vector<int> result;
            auto queueSize = nodeQueue.size();
            for(; queueSize > 0; --queueSize){
                auto node = nodeQueue.front();
                nodeQueue.pop();
                result.push_back(node->val);
                if(node->left != nullptr){
                    nodeQueue.push(node->left);
                }

                if(node->right != nullptr){
                    nodeQueue.push(node->right);
                }
            }
            
            if(leftFlg){
                results.push_back(result);
            }
            else{
                vector<int> reversed;
                auto vrbegin = result.rbegin();
                auto vrend = result.rend();
                for(; vrbegin!= vrend; ++vrbegin){
                    reversed.push_back(*vrbegin);
                }
                results.push_back(reversed);
            }
            
            leftFlg = !leftFlg;
        }
        
        return results;
    }
};