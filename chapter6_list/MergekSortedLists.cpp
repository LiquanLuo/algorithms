/**
23. Merge k Sorted Lists
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6


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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(0);
        ListNode *head = &dummy;
        int currentList = 0;
        auto currentNode = findNext(lists, currentList);
        while(currentNode != nullptr){
            lists[currentList] = lists[currentList]->next;
            head->next = currentNode;
            head = head->next;
            currentNode = findNext(lists, currentList);
        }
           
        return dummy.next;
        
    }
    
    ListNode* findNext(vector<ListNode*> &lists, int &currentList){
        currentList = 0;
        ListNode* currentNode = nullptr;
        for(int i = 0; i < lists.size(); ++i){
            if(lists[i] != nullptr){
                if(currentNode == nullptr || 
                   lists[i]->val < currentNode->val){
                    currentNode =  lists[i];
                    currentList = i;
                }
            }
        }
        
        return currentNode;
    }
};