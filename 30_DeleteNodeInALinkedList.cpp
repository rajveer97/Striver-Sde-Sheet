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
void deleteNode(LinkedListNode<int> * node) {
    LinkedListNode<int>* temp = node->next;
    // Store the data of the temp as node->data
    // and make node->next = temp->next;
    node->data = temp->data;
    node->next = temp->next;
    
    // delete temp from memory
    temp->next = NULL;
    delete temp;
}