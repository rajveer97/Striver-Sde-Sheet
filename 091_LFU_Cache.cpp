#include<bits/stdc++.h>
struct Node
{
    int key, value, cnt;
    Node* next;
    Node* prev;
    Node(int _key, int _value)
    {
        key = _key;
        value = _value;
        cnt = 1;
    }
};

struct List
{
    int size;
    Node *head;
    Node *tail;
    List()
    {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    
    void addFront(Node *node)
    {
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++;
    }
    
    void removeNode(Node* delnode)
    {
        Node* delprev = delnode->prev;
        Node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
        size--;
    }
};

class LFUCache
{
    map<int, Node*> keyNode;
    map<int, List*> freqListMap;
    int maxSizeCache;
    int minFreq;
    int curSize;
    
public:
    LFUCache(int capacity)
    {
        // Write your code here.
        maxSizeCache = capacity;
        minFreq = 0;
        curSize = 0;
    }
    
    void updateFreqListMap(Node *node)
    {
        keyNode.erase(node->key);
        freqListMap[node->cnt]->removeNode(node);
        if(node->cnt == minFreq && freqListMap[node->cnt]->size == 0)
        {
            minFreq++;
        }
        
        List* nextHigherFreqList = new List();
        if(freqListMap.find(node->cnt + 1) != freqListMap.end())
        {
            nextHigherFreqList = freqListMap[node->cnt + 1];
        }
        node->cnt += 1;
        nextHigherFreqList->addFront(node);
        freqListMap[node->cnt] = nextHigherFreqList;
        keyNode[node->key] = node;
    }

    int get(int key)
    {
        // Write your code here.
        if(keyNode.find(key) != keyNode.end())
        {
            Node* node = keyNode[key];
            int val = node->value;
            updateFreqListMap(node);
            return val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        // Write your code here.
        if(maxSizeCache == 0)
        {
            return;
        }
        
        if(keyNode.find(key) != keyNode.end())
        {
            Node* node = keyNode[key];
            node->value = value;
            updateFreqListMap(node);
        }
        else 
        {
            if(curSize == maxSizeCache)
            {
                List* list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqListMap[minFreq]->removeNode(list->tail->prev);
                curSize--;
            }    
            curSize++;
            // new value has to be added who is not there previously
            minFreq = 1;
            List* listFreq = new List();
            if(freqListMap.find(minFreq) != freqListMap.end())
            {
                listFreq = freqListMap[minFreq];
            }
            Node* node = new Node(key, value);
            listFreq->addFront(node);
            keyNode[key] = node;
            freqListMap[minFreq] = listFreq;
        }
    }
};
/*
TC : O(1)
*/

//------------------------------------------------------------------------------------------------------
// Leetcode
//First , go through LRU Cache to understand why Double Linked List is best suited for this Qn
class LFUCache {
private:
    int cap;
    int size;
    unordered_map<int, list<vector<int>>::iterator> mp; //key -> address of list of vector{key, value, freq}
    map<int, list<vector<int>>> freq; //freq -> list of vector{key, value, freq}
    
public:
    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
    }
    
    void makeMostFrequentlyUsed(int key) {
        auto &vec = *(mp[key]);
        
        int value = vec[1];
        
        int f     = vec[2];
        
        freq[f].erase(mp[key]);
        
        if(freq[f].empty())
            freq.erase(f);
        
        f++;
        
        freq[f].push_front(vector<int>({key, value, f}));
        
        mp[key] = freq[f].begin();
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;
        
        auto &vec = (*(mp[key]));
        
        int value = vec[1];
        
        makeMostFrequentlyUsed(key);
        
        return value;
    }
    
    void put(int key, int value) {
        if(cap == 0)
            return;
        
        if(mp.find(key) != mp.end()) {
            auto &vec = (*(mp[key]));
            vec[1] = value;
            makeMostFrequentlyUsed(key);
        }
        else if(size < cap) {
            size++;
            freq[1].push_front(vector<int>({key, value, 1}));
            mp[key] = freq[1].begin();
        }
        else { //Time to remove LFU or LRU if tie
            
            auto &kaun_sa_list = freq.begin()->second;
            
            int key_delete = (kaun_sa_list.back())[0]; //ordered_map ensures that the begin() will be th eleast frequency
            
            kaun_sa_list.pop_back();
            
            if(kaun_sa_list.empty())
                freq.erase(freq.begin()->first);
            
            freq[1].push_front(vector<int>({key, value, 1}));
            
            mp.erase(key_delete);
            mp[key] = freq[1].begin();
        }
    }
};
