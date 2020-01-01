/**
82. Remove Duplicates from Sorted List II

Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5
Example 2:

Input: 1->1->1->2->3
Output: 2->3
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy = ListNode(0);
        auto pre = &dummy;
        while(head != nullptr){
            if(head->next != nullptr && (head->next)->val == head->val){
                while(head->next != nullptr && (head->next)->val == head->val){
                    head = head->next;
                }
                
                head = head->next;
            }
            else{
                pre->next = head;
                pre = pre->next;
                head = head->next;
            }
        }
        
        pre->next = nullptr;
        return dummy.next;
        
    }
};