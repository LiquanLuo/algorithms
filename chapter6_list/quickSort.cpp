/**
148. Sort List(quickSort)

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
    ListNode *sortList(ListNode* head) {
        if(head == nullptr){
            return head;
        }
        
        head = quickSort(head, nullptr);
        return head;
    }
    
    ListNode *quickSort(ListNode *head, ListNode *end){
        // print(head,end);
        if(head == end || head->next == end){
            return head;
        }
        
        ListNode dummy(0);
        dummy.next = head;
        auto preHead = &dummy;
        auto cur = head;
        auto preCur = head;
        auto leftHead = preHead;
        int pivot = head->val;
        cur = cur->next;
        while(cur != end){
            if(cur->val < pivot){
                auto curNext = cur->next;
                leftHead->next = cur;
                cur->next = head;
                leftHead = cur;
                cur = curNext; 
                preCur->next = cur;
            }
            else{
                cur = cur->next;
                preCur = preCur->next;
            }   
        }
        
        head->next = quickSort(head->next, end);
        return quickSort(dummy.next, head);
    }
    
    void print(ListNode *head, ListNode *end){
        while(head != end){
            cout << head->val << "->";
            head = head->next;
        }
        
        cout << endl;
    }
    
};