#include<unordered_map>

class Node 
{
    public:
    int k;
    int val;
    Node *next, *prev;
    
    Node(int key, int value)
    {
        k = key;
        val = value;
        prev = NULL;
        next = NULL;
    }
};


class LRUCache
{
public:
    LRUCache(int capacity)
    {
        // Write your code here
        cap = capacity;
        
        left = new Node(0, 0);
        right = new Node(0, 0);
        
        left->next = right;
        right->prev = left;
    }

    int get(int key)
    {
        // Write your code here
        if(cache.find(key) != cache.end())
        {
            remove(cache[key]);
            insert(cache[key]);
            return cache[key]->val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        // Write your code here
        if(cache.find(key) != cache.end())
        {
            remove(cache[key]);
        }
        
        cache[key] = new Node(key, value);
        insert(cache[key]);
        
        if(cache.size() > cap)
        {
            // remove from list & delete LRU from map
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->k);
        }        
    }

private:
    int cap;
    unordered_map<int, Node*> cache; // {key -> node}
    Node* left;
    Node* right;
    
    // remove node from list
    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        
        prev->next = next;
        next->prev = prev;
    }
    
    // insert node at right
    void insert(Node* node) {
        Node* prev = right->prev;
        Node* next = right;
        
        prev->next = node;
        next->prev = node;
        
        node->prev = prev;
        node->next = next;
    }
};

//--------------------------------------------------------------------------------------
// Leetcode

class LRUCache {
private:
    int capacity;
    list<int> recent;
    unordered_map<int, int> cache;
    unordered_map<int, list<int>::iterator> pos;
    void use(int key)
    {
        if(pos.find(key) != pos.end()) {
            recent.erase(pos[key]);
        }
        else if(recent.size() >= capacity)
        {
            int old = recent.back();
            recent.pop_back();
            cache.erase(old);
            pos.erase(old);
        }
        
        recent.push_front(key);
        pos[key] = recent.begin();
    }
    
public:
    
    LRUCache(int capacity): capacity(capacity) {}
    
    int get(int key) {
        if(cache.find(key) != cache.end())
        {
            use(key);
            return cache[key];
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        use(key);
        cache[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
