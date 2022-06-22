#include <bits/stdc++.h> 
/****************************************************************
    Following is the class structure of the Node class:
class Node {
public:
    int data;
    Node* next;
    Node* child;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->child = NULL;
    }
};
*****************************************************************/
// Mathod:1
/*
Notes:
The idea is to use the Merge() process of merge sort for linked lists. 
We use merge() to merge lists one by one. 
We recursively merge() the current list with the already flattened list. 
The down pointer is used to link nodes of the flattened list.
*/

// An utility function to merge two sorted
// linked lists
Node* mergeList(Node *a, Node* b)
{
    // If first linked list is empty then second
    // is the answer
    if(a==NULL) return b;
    
    // If second linked list is empty then first
    // is the result
    if(b==NULL) return a;
    
    // Compare the data members of the two linked
    // lists and put the smaller one in the result
    Node* result;
    
    if(a->data < b->data)
    {
        result = a;
        result->child = mergeList(a->child, b);
    }
    else {
        result = b;
        result->child = mergeList(a, b->child);
    }
    
    result->next = NULL;
    return result;
}

Node* flattenLinkedList(Node* head) 
{
    // Base case
	if(head==NULL || head->next==NULL) return head;
    
    // recur for list on right
    head->next = flattenLinkedList(head->next);
    
    // Now Merge
    head = mergeList(head, head->next);
    
    // Return the head
    // at return time it will be merged with its left
    return head;
}

/*
Time Complexity: O(N*N*M) – where N is the no of nodes in main linked list (reachable using right pointer) and M is the no of node in a single sub linked list (reachable using down pointer). 

Space Complexity: O(N*M) – because of the recursion. The recursive functions will use recursive stack of size equivalent to total number of elements in the lists, which is N*M.
*/

