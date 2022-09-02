#include <bits/stdc++.h> 
/********************************
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
********************************/
/*
Method 1:
To rotate a linked list by k, 
we can first make the linked list circular and 
then moving (length - k) steps forward from head node, 
making (length - k)th node’s next to null and 
make (length - k + 1)th node as head
*/

Node *rotate(Node *head, int k) {
    if(head == NULL || head->next==NULL) return head;
    
    Node* curr = head;
    
    int len = 1;
    while(curr->next) {
        curr = curr->next;
        len++;
    }
    k = k%len;
    k = len - k;
    
    
    curr->next = head;
    while(k>0) {
        curr = curr->next;
        k--;
    }
    
    head = curr->next;
    curr->next = NULL;
    
    return head;
}
/*
Time Complexity: O(n) where n is the number of nodes in Linked List.
Auxiliary Space : O(1)
*/
