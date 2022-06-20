#include <bits/stdc++.h> 
/****************************************************************
    Following is the class structure of the Node class:
        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };
*****************************************************************/
int findIntersection(Node *firstHead, Node *secondHead)
{
    if(firstHead==NULL || secondHead==NULL) return 0;
    Node* a = firstHead;
    Node* b = secondHead;
    while(a != b) {
        a = a==NULL ? secondHead : a->next;
        b = b==NULL ? firstHead : b->next;
    }
    
    return a==NULL ? -1 : a->data;
}