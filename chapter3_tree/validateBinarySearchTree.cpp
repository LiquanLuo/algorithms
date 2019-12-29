/**
QUESTION:
98. Validate Binary Search Tree

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:

    2
   / \
  1   3

Input: [2,1,3]
Output: true
Example 2:

    5
   / \
  1   4
     / \
    3   6

Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
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
    
    struct resultType{
        int maxVal = INT_MIN;
        int minVal = INT_MAX;
        bool isValid = true;
    };
    
    
public:
    bool isValidBST(TreeNode* root) {
        auto result = isValidBSTAux(root);
        return result.isValid;
    }
    
    resultType isValidBSTAux(TreeNode* root) {
        resultType result;
        if(root == nullptr){
            return result;
        }
        
        auto left = isValidBSTAux(root->left);
        auto right = isValidBSTAux(root->right);
        cout << left.isValid << right.isValid << endl;
        
        
        if(!(left.isValid && right.isValid)){
            result.isValid = false;
        }
        cout << "left.maxVal " << left.maxVal << "root->val " << root->val << endl;
        cout << "right.min " << right.minVal << "root->val " << root->val << endl;
        if(root->left != nullptr &&     // rootvalue could be INT_MAX
           left.maxVal >= root->val){   
            result.isValid = false;
        }
        
        if(root->right != nullptr &&    // rootvalue could be INT_MIN
          right.minVal <= root->val){
            result.isValid = false;
        }
        
        
        result.maxVal = max(left.maxVal, right.maxVal);
        result.maxVal = max(result.maxVal, root->val);
        
        result.minVal = min(left.minVal, right.minVal);
        result.minVal = min(result.minVal, root->val);
        cout << "--------" << endl;
        return result;
    }
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        
        bool ret = Solution().isValidBST(root);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}