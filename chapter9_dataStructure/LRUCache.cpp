/**
146. LRU Cache

Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 // capacity );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4


*/

/**
 solution
 1. double linked list and map


 */

class LRUCache {
    
struct ListNode{
    int key;
    int val;
    ListNode *next = nullptr;
    ListNode *pre = nullptr;
    ListNode(int k, int v):key(k),val(v){};
};
    
    
private:
    int _size = 0;
    int _capacity = 0;
    ListNode *_head = nullptr;
    ListNode *_cur = nullptr;
    unordered_map<int, ListNode*> nodeMap;
    
public:
    LRUCache(int capacity) {
        _size = 0;
        _capacity = capacity;
        _head = new ListNode(0,0);
        _cur = _head;
    }
    
    int get(int key) {
        // cout << "-----  get  ---" << endl;
        // print(_head);
        // cout << "look for " << key << endl;
        
        if(nodeMap.find(key) != nodeMap.end()){
            auto node = nodeMap[key];
            moveToEnd(node);
            // print(_head);
            return node->val;
        }
        
        // print(_head);
        return -1;
    }
    
    void put(int key, int value) {
        // cout << "-----  put  ---" << endl;
        // print(_head);
        // cout << "put key: " << key << " val " << value << " size" << _size << endl;
        if(nodeMap.find(key) != nodeMap.end()){  // find it
            auto node = nodeMap[key];
            node->val = value;
            moveToEnd(node);
        }
        else{                       // not found
            if(_size >= _capacity){
                remove(_head->next);
            }
            
            ListNode *newNode = new ListNode(key,value);
            add(newNode);
        }
        // print(_head);
        
    }
    
    void add(ListNode *node){
        _cur->next = node;
        node->pre = _cur;
        node->next = nullptr;
        _cur = node;
        ++_size;
        nodeMap[node->key] = node;
    }
    
    void remove(ListNode *node){
        auto preNode = node->pre;
        auto after = node->next;
        preNode->next = after;
        if(after != nullptr){
            after->pre = preNode;
        }
        
        if(_cur == node){
            _cur = preNode;
        }
        
        nodeMap.erase(node->key);
        --_size;
    }
    
    void moveToEnd(ListNode *node){
        // if(_cur == node){   // !!!!!!!!
        //     return;
        // }
        remove(node);
        add(node);
    }
    
    void print(ListNode *node){
        while(node != nullptr){
            cout << "(key:" << node->key << " val:" << node->val << ")-->" ;
            node = node->next;
        }
        cout << endl;
    }
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 ["LRUCache","put","put","get","put","get","put","get","get","get"]
[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]
 */