/**
145. Binary Tree Postorder Traversal
Given a binary tree, return the postorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [3,2,1]
Follow up: Recursive solution is trivial, could you do it iteratively?
 */


/**
SOLUTION:
(1) if two stacks can be used, its easy, we can do root->right->left in 
one stack, and pop it to another stack, then it will be post travese

(2) if only one stack is allowed.
a. moving towards to the most-left node, on its way,
 a.1 push right child
 a.2 push root
b. pop from the stack 
 b.1 if right child exists and it equals to the next top on the stack, which means
 its right tree has not been traversed, we have to push the current node back to stack
 and we need to set currentnode to right child, go back to a
 b.2 otherwise, the right tree has been traversed, we can push the current node to result
 and set the current node to null, go back to a
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == nullptr){
            return result;
        }
        
        stack<TreeNode*> nodeStack;
        auto currentNode = root;
        while(currentNode != nullptr||
             !nodeStack.empty()){
            while(currentNode != nullptr){
//                cout << currentNode->val << endl;
                if(currentNode->right != nullptr){
                    nodeStack.push(currentNode->right);
                }
                nodeStack.push(currentNode);
                currentNode = currentNode->left;
            }
            // cout << "--------" << endl;
            
            currentNode = nodeStack.top();
            nodeStack.pop();
            TreeNode *nextNode = nullptr;
            if(!nodeStack.empty()){             // it could be an empty stack
                nextNode = nodeStack.top();
            }
            
            if(currentNode->right != nullptr && 
              currentNode->right == nextNode ){ // right child is still in the stack, has not been traversed
                nodeStack.pop();
                nodeStack.push(currentNode);
                currentNode = currentNode->right;
            }
            else{
                result.push_back(currentNode->val);
                currentNode = nullptr;          // set to nullptr
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
        
        vector<int> ret = Solution().postorderTraversal(root);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
