/**
QUESTION:
124. Binary Tree Maximum Path Sum

Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes 
from some starting node to any node in the tree along the parent-child 
connections. The path must contain at least one node and does not need 
to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42
 */

/**
 SOLUTION:
 It can be solved by using trversal + divide && conquer method
 (1) traverse to find the maximum path sum and store it in a global value
 (2) divide && conquer to find the maximum path sum starting from the root

 in each recursion, after finding the left maximum sum from left child and
 right maximum sum from right child, we can update maximum path sum and return 
 maximum path sum starting from root.

    // maximum path sum could be
        // (1) root itself
        // (2) root + left
        // (3) root + right
        // (4) left+root+right
        // (5) original value

    // maximum path sum starting from root
        // (1) root itself
        // (2) root + left
        // (3) root + right

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
    int maxPathSum(TreeNode* root) {
        maxPathSumAux(root);
        return maximumSum;
    }
    
    // return the maximum sum starting from root
    int maxPathSumAux(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        
        int left = maxPathSumAux(root->left);
        int right = maxPathSumAux(root->right);
        
        // result could be
        // (1) root itself
        // (2) root + left
        // (3) root + right
        int result = root->val;
        result = max(result, root->val+left);
        result = max(result, root->val+right);
        
        // maximum could be
        // (1) root itself
        // (2) root + left
        // (3) root + right
        // (4) left+root+right
        // (5) original value
        maximumSum = max(maximumSum, root->val+left+right);
        maximumSum = max(maximumSum, result);
        
    
        return result;
    }
    
private:
    int maximumSum = INT_MIN;
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        
        int ret = Solution().maxPathSum(root);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}