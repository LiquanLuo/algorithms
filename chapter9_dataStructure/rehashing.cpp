/**
129. Rehashing
The size of the hash table is not determinate at the very beginning. If the total size of keys is too large (e.g. size >= capacity / 10), we should double the size of the hash table and rehash every keys. Say you have a hash table looks like below:

size=3, capacity=4

[null, 21, 14, null]
       ↓    ↓
       9   null
       ↓
      null
The hash function is:

int hashcode(int key, int capacity) {
    return key % capacity;
}
here we have three numbers, 9, 14 and 21, where 21 and 9 share the same position as they all have the same hashcode 1 (21 % 4 = 9 % 4 = 1). We store them in the hash table by linked list.

rehashing this hash table, double the capacity, you will get:

size=3, capacity=8

index:   0    1    2    3     4    5    6   7
hash : [null, 9, null, null, null, 21, 14, null]
Given the original hash table, return the new hash table after rehashing .

Example
Example 1

Input : [null, 21->9->null, 14->null, null]
Output : [null, 9->null, null, null, null, 21->null, 14->null, null]
Notice
For negative integer in hash table, the position can be calculated as follow:

C++/Java: if you directly calculate -4 % 3 you will get -1. You can use function: a % b = (a % b + b) % b to make it is a non negative integer.
Python: you can directly use -1 % 3, you will get 2 automatically.



*/


/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param hashTable: A list of The first node of linked list
     * @return: A list of The first node of linked list which have twice size
     */    
    vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
        vector<ListNode*> result;
        int newSize = hashTable.size() * 2;
        int tmp = newSize;
        while(tmp > 0){
            ListNode* node = nullptr;
            result.push_back(node);
            --tmp;
        }
        
        for(auto node : hashTable){
            while(node != nullptr){
                node = add(node, result, newSize);
            }
        }
        
        return result;
    }
    
    ListNode* add(ListNode* node, vector<ListNode*> &result, int newSize){
        int hashVal = node->val % newSize;
        while(hashVal < 0){
            hashVal = (hashVal + newSize) % newSize;
        }
        
        auto newHashNode = result[hashVal];
        
        if(newHashNode != nullptr){
            while(newHashNode->next != nullptr){
                newHashNode = newHashNode->next;
            }
            
            newHashNode->next = node;
        }
        else{
            result[hashVal] = node;
        }
        
        auto tmp = node->next;
        node->next = nullptr;
        node = tmp;
    }
                
};
