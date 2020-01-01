
/**
19. Remove Nth Node From End of List

Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?

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
// two passes
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         ListNode dummy = ListNode(0);
//         dummy.next = head;
//         int size = 0;
//         auto currentNode = head;
//         while(currentNode != nullptr){
//             currentNode = currentNode->next;
//             ++size;
//         }
        
//         int deletePos = size - n;
//         auto deleteNode = head;
//         ListNode *prev = &dummy;
//         while(deletePos > 0){
//             --deletePos;
//             deleteNode = deleteNode->next;
//             prev = prev->next;
//         }
        
//         prev->next = deleteNode->next;
        
//         return dummy.next;
//     }
    
    // one pass
    // use two pointers, keep n gaps between them
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy = ListNode(0);
        dummy.next = head;
        auto nthNode = head;
        auto removePre = &dummy;
        for(int i = 0; i < n; ++i){
            nthNode = nthNode->next;
        }
        
        while(nthNode != nullptr){
            nthNode = nthNode->next;
            removePre = removePre->next;
        }
        
        auto removeNode = removePre->next;
        removePre->next = removeNode->next;
        
        return dummy.next;
    }
};