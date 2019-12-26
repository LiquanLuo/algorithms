
/**
 450. Delete Node in a BST
 Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
Note: Time complexity should be O(height of tree).

Example:

root = [5,3,6,2,4,null,7]
key = 3

    5
   / \
  3   6
 / \   \
2   4   7

Given key to delete is 3. So we find the node with value 3 and delete it.

One valid answer is [5,4,6,2,null,null,7], shown in the following BST.

    5
   / \
  4   6
 /     \
2       7

Another valid answer is [5,2,6,null,4,null,7].

    5
   / \
  2   6
   \   \
    4   7

 */


/**
    SOLUTION:
    1. create an extra node to represent the parent of root node, return the child of this node
    

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
    TreeNode* deleteNode(TreeNode *root, int key) {
        TreeNode *rootparent = new TreeNode(0);
        rootparent->left = root;
        delteNodeAux(root, key, rootparent, true);
        return rootparent->left ;
    }
    
    void delteNodeAux(TreeNode *root, int key, TreeNode *parent, bool leftFlg){
        if(root == nullptr){
            return;
        }
        
        if(root->val == key){
            removeNode(root, parent,leftFlg);
        }
        else if(root->val < key){
            delteNodeAux(root->right,key, root, false);
        }
        else{
            delteNodeAux(root->left,key, root, true);
        }  
    }
    
    void removeNode(TreeNode* root, TreeNode *parent, bool leftFlg){
        if(root->left == nullptr && root->right == nullptr){
            root = nullptr;
            
        }
        else if(root->left != nullptr && root->right == nullptr){
            
            root = root->left;
        }
        else if(root->right != nullptr && root->left == nullptr){
        
            root = root->right;
        }
        else{
            auto leftNode = root->left;
            auto rightNode = root->right;
            root = rightNode;
            while(rightNode->left != nullptr){
                rightNode = rightNode->left;
            }
            
            rightNode->left = leftNode;
        }
        
        if(leftFlg){
            parent->left = root;
        }
        else{
            parent->right = root;
        }
        
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

int stringToInteger(string input) {
    return stoi(input);
}

string treeNodeToString(TreeNode* root) {
    if (root == nullptr) {
      return "[]";
    }

    string output = "";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node == nullptr) {
          output += "null, ";
          continue;
        }

        output += to_string(node->val) + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.substr(0, output.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        getline(cin, line);
        int key = stringToInteger(line);
        
        TreeNode* ret = Solution().deleteNode(root, key);

        string out = treeNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}