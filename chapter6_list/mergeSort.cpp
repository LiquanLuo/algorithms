/**
148. Sort List
Sort a linked list in O(n log n) time using constant space complexity.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5

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
    ListNode* sortList(ListNode *head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        
        auto right = partition(head);
        head = sortList(head);
        right = sortList(right);
        head = merge(head, right);
        return head;
    }
    
    ListNode *merge(ListNode *left, ListNode *right){
        if(left == nullptr){
            return right;
        }
        
        if(right == nullptr){
            return left;
        }
        
        ListNode dummy(0);
        auto tail = &dummy;
        while(left != nullptr && right != nullptr){
            if(left->val < right->val){
                tail->next = left;
                tail = tail->next;
                left = left->next;
            }else{
                tail->next = right;
                tail = tail->next;
                right = right->next;
            }
        }
        
        if(left == nullptr){
            tail->next = right;
        }
        
        if(right == nullptr){
            tail->next = left;
        }

        return dummy.next;
    }
    
    
    ListNode *partition(ListNode *head){
        auto mid = findMid(head);
        auto right = mid->next;
        mid->next = nullptr;
        return right;
    }
    
    ListNode *findMid(ListNode *head){
        auto slow = head;
        auto fast = head->next;
        while(fast != nullptr && fast->next != nullptr ){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    void print(ListNode *head, ListNode *end = nullptr){
        while(head != end){
            cout << head->val << "->";
            head = head->next;
        }
        
        cout << endl;
    }
    
};