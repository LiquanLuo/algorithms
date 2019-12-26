
/**

QUESTION:
297. Serialize and Deserialize Binary Tree

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Example: 

You may serialize the following tree:

    1
   / \
  2   3
     / \
    4   5

as "[1,2,3,null,null,4,5]"
Clarification: The above format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.


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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result("");
        if(root == nullptr){
            return result;    
        }
        
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        
        while(!nodeQueue.empty()){
            auto newNode = nodeQueue.front();
            nodeQueue.pop();
            if(newNode == nullptr){
                result += "#,";
                continue;
            }
            
            result += to_string(newNode->val);
            result += ",";
            
            nodeQueue.push(newNode->left);
            nodeQueue.push(newNode->right);
                     
        }
        
        // cout << result << endl;
        
        return result;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode *root = nullptr;
        if(data == ""){
            return root;
        }
        
        stringstream ss(data);
        string nodeStr;
        char del = ',';
        getline(ss, nodeStr, del);
        root = new TreeNode(stoi(nodeStr));
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root); 
        while(!nodeQueue.empty()){
            auto Node = nodeQueue.front();
            nodeQueue.pop();
            
            getline(ss, nodeStr, del);
            if(nodeStr != "#"){
                TreeNode *newNode = new TreeNode(stoi(nodeStr));
                Node->left = newNode;
                nodeQueue.push(newNode);
            }
            
            getline(ss, nodeStr, del);
            if(nodeStr != "#"){
                TreeNode *newNode = new TreeNode(stoi(nodeStr));
                Node->right = newNode;
                nodeQueue.push(newNode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

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
        
        string ret = Solution().Codec(root);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}