/**
143. Reorder List

Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example 1:

Given 1->2->3->4, reorder it to 1->4->2->3.
Example 2:

Given 1->2->3->4->5, reorder it to 1->5->2->4->3.

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
    void reorderList(ListNode* head) {
        if(head == nullptr){
            return;
        }
        
        int size = 0;
        auto temp = head;
        while(temp != nullptr){
            temp = temp->next;
            ++size;
        }
        
        if(size == 1){
            return;
        }
        
        auto rightHead = partition(head, size);
        rightHead = reverse(rightHead);
        merge(head, rightHead);
    }
    
    void merge(ListNode *left, ListNode *right){
        while(left->next != nullptr){
            auto leftNext = left->next;
            auto rightNext = right->next;
            left->next = right;
            right->next = leftNext;
            left = leftNext;
            right = rightNext;
        }
        
        left->next = right;
    }
    
    
    ListNode *reverse(ListNode *head){
        ListNode dummy(0);
        dummy.next = head;
        auto preHead = &dummy;
        auto pre = preHead;
        auto cur = head;
        while(cur != nullptr){
            auto temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        
        preHead->next = pre;
        head->next = nullptr;
        return dummy.next;
    }
    
    
    ListNode *partition(ListNode *head, int size){
        auto temp = head;
        for(int i = 0; i < (size+1)/2-1; ++i){
            temp = temp->next;
        }
        
        auto rightHead = temp->next;
        temp->next = nullptr;
        
        // print(head);
        // print(rightHead);
        
        return rightHead;
    }
    
    void print(ListNode *head){
        while(head != nullptr){
            cout << head->val << " -> " ;
            head = head->next;
        }
        cout << endl;
    }
    
    
    
};