/**

142. Linked List Cycle II

Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

Note: Do not modify the linked list.

 

Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.

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
SOLUTION:
after finding the point where slow meet the start, using another pointer start from 
the head, increment slow and head simultaneously, when they meet each other, its the
result we want

 */

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        auto slow = head;
        auto fast = slow;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                while(slow != head){
                    slow = slow->next;
                    head = head->next;
                }
                
                return slow;
            }
            
        }
        
        return nullptr;
    }
};