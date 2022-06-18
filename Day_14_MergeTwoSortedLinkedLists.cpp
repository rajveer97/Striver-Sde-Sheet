#include <bits/stdc++.h> 
/************************************************************
    Following is the linked list node structure.
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };
************************************************************/
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    Node<int>* dummy = new Node<int>(-1);
    Node<int>* temp = dummy;
    
    while(first != NULL && second != NULL)
    {
        if(first->data <= second->data)
        {
            temp->next = first;
            first = first->next;
        }
        else {
            temp->next = second;
            second = second->next;
        }
        temp = temp->next;
    }
    
    if(first == NULL)
    {
        temp->next = second;
    }
    
    if(second == NULL) 
    {
        temp->next = first;
    }
    
    return dummy->next;
}
