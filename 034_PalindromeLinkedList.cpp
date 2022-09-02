#include <bits/stdc++.h> 
/****************************************************************
    Following is the class structure of the LinkedListNode class:
    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };
*****************************************************************/
bool isPalindrome(LinkedListNode<int> *head) {
    vector<int> v;
    LinkedListNode<int>* curr = head;
    while(curr) {
        v.push_back(curr->data);
        curr = curr->next;
    }
    int n = v.size();
    int i=0, j = n-1;
    while(i<=j) {
        if(v[i++] != v[j--]) return false;
    }
    return true;
}