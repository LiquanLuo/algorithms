
/**

109. Convert Sorted List to Binary Search Tree

Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted linked list: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5


 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    TreeNode* sortedListToBST(ListNode* head) {
        TreeNode dummy = TreeNode(0);
        if(head == nullptr){
            return nullptr;
        }
        
        auto end = head;
        while(end->next != nullptr){
            end = end->next;
        }
        
        sortedListToBSTAux(head, end, dummy.left);
        
        return dummy.left;
    }
    
    // put elements in [head, end] into pos
    void sortedListToBSTAux(ListNode *head, ListNode *end, TreeNode *&pos){
        if(head == nullptr){
            return;
        }
        
        int size = 1;
        auto cur = head;
        while(cur != end){
            cur = cur->next;
            ++size;
        }
        
        if(size == 1){
            pos = new TreeNode(head->val);
            return;
        }
        
        auto pre = head;
        cur = pre->next;
        int median = size/2;
        while(median > 1){
            pre = pre->next;
            cur = cur->next;
            --median;
        }
        // cout << "head: " << head->val << " pre: " << pre->val <<
        //     "cur:" << cur->val << " end: " << end->val << endl;
        
        pos = new TreeNode(cur->val);
        pre->next = nullptr;    // break the list
        end->next = nullptr;    // break the list
        sortedListToBSTAux(head, pre, pos->left);
        sortedListToBSTAux(cur->next, end, pos->right);
    }
    
};