
/**
QUESTION:
144. Binary Tree Preorder Traversal

Given a binary tree, return the preorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,2,3]
Follow up: Recursive solution is trivial, could you do it iteratively?
 */

/**
SOLUTION:
use a stack
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

// v1: recursion
// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> result;
//         if(root == nullptr){
//             return result;
//         }
        
//         result.push_back(root->val);
        
//         auto left = preorderTraversal(root->left);
//         auto right = preorderTraversal(root->right);
        
//         for(auto i:left){
//             result.push_back(i);
//         }
        
//         for(auto j:right){
//             result.push_back(j);
//         }
        
//         return result;
//     }
// };

//v2 iteratively
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == nullptr){
            return result;
        }
        
        stack<TreeNode*> nodeStack;
        nodeStack.push(root);
        
        while(!nodeStack.empty()){
            auto topNode = nodeStack.top();
            result.push_back(topNode->val);
            nodeStack.pop();
            
            if(topNode->right != nullptr){
                nodeStack.push(topNode->right);
            }
            
            if(topNode->left != nullptr){
                nodeStack.push(topNode->left);
            }
                
        }
        
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

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        
        vector<int> ret = Solution().preorderTraversal(root);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}