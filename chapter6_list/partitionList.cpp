/**
86. Partition List


Given a linked list and a value x, partition it such that all 
nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes 
in each of the two partitions.

Example:

Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5

*/


/**
 WHEN the structure of list change, do not forget to set the next of 
 last node as nullptr, otherwise it will will never ends 

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
    ListNode* partition(ListNode* head, int x) {
        ListNode lessDummy = ListNode(0);
        ListNode greatDummy = ListNode(0);
        auto less = &lessDummy;
        auto great = &greatDummy;
        
        while(head != nullptr){
            // cout << head->val << endl;
            if(head->val < x){
                less->next = head;
                less = less->next;
            }
            else{
                great->next = head;
                great = great->next;
            }
            
            head = head->next;
        }
        
        great->next = nullptr;  // !!!!!! take care the end of list      
        less->next = greatDummy.next;
        return lessDummy.next;
    }
};