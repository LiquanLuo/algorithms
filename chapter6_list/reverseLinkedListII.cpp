/**

92. Reverse Linked List II

Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode *nNext = head;
        for(int i = n; i > 0; --i){
            nNext = nNext->next;
        }
        // cout << "nNext: " << nNext->val << endl;
    
        auto pre = &dummy;
        auto cur = head;
        for(int i = m; i > 1; --i){
            cur = cur->next;
            pre = pre->next;
        }
        
        auto mPre = pre;
        
        // cout << "mPre: " << mPre->val << endl;
        while(cur != nNext){
            // cout << "current" << cur->val << endl;
            auto temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        
        mPre->next->next = nNext;
        mPre->next = pre;
        
        return dummy.next;
        
    }
};