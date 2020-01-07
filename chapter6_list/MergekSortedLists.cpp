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
    // search next node in all the lists, every node cost k, in total cost k*N time
    // time: k * N
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         ListNode dummy(0);
//         ListNode *head = &dummy;
//         int currentList = 0;
//         auto currentNode = findNext(lists, currentList);
//         while(currentNode != nullptr){
//             lists[currentList] = lists[currentList]->next;
//             head->next = currentNode;
//             head = head->next;
//             currentNode = findNext(lists, currentList);
//         }
           
//         return dummy.next;
        
//     }
    
//     ListNode* findNext(vector<ListNode*> &lists, int &currentList){
//         currentList = 0;
//         ListNode* currentNode = nullptr;
//         for(int i = 0; i < lists.size(); ++i){
//             if(lists[i] != nullptr){
//                 if(currentNode == nullptr || 
//                    lists[i]->val < currentNode->val){
//                     currentNode =  lists[i];
//                     currentList = i;
//                 }
//             }
//         }
        
//         return currentNode;
//     }
    
    
    struct GreaterNode{
        bool operator()(ListNode *lhs, ListNode *rhs){
            return rhs->val < lhs->val;
        }
    };
    
    // using pq
    // time Nlogk
    ListNode* mergeKLists(vector<ListNode*>& lists){
        ListNode dummy(0);
        auto currentNode = &dummy;
        priority_queue<ListNode*, vector<ListNode*>,GreaterNode> pq;
        for(auto list : lists){
            if(list != nullptr){
                pq.push(list);
            }
        }
        
        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();
            currentNode->next = node;
            currentNode = currentNode->next;
            if(node->next != nullptr){
                pq.push(node->next);
            }
        }
        
        return dummy.next;
    }
};