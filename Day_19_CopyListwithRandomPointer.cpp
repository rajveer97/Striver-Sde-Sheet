#include <bits/stdc++.h> 
/*
Method 1:
1. Create the copy of node 1 and insert it between node 1 & node 2 in 
the original Linked List, create a copy of 2 and insert it between 2 & 3. 
Continue in this fashion, add the copy of N after the Nth node 
 
2. Now copy the random link in this fashion 
 original->next->random= original->random->next;  //TRAVERSE TWO NODES
 
3. This works because original->next is nothing but a copy of the original 
and Original->random->next is nothing but a copy of the random. 
 
4. Now restore the original and copy linked lists in this fashion in a single loop. 
 
original->next = original->next->next;
     copy->next = copy->next->next;
     
5. Ensure that original->next is NULL and return the cloned list

*/
LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    if(!head) return head;
    
    LinkedListNode<int> *curr = head, *temp;
    
    // insert additional node after
    // every node of original list
    while(curr) {
        temp = curr->next;
        
        // Inserting node
        curr->next = new LinkedListNode<int>(curr->data);
        curr->next->next = temp;
        curr = temp;
    }
    
    curr = head;
    
    // adjust the random pointers of the
    // newly added nodes
    while(curr) {
        if(curr->next)
            curr->next->random = curr->random ? curr->random->next : curr->random;
        
        // move to the next newly added node by
        // skipping an original node
        curr = curr->next ? curr->next->next : curr->next;
    }
    
    LinkedListNode<int>* original = head, *copy = head->next; 
    
    // save the head of copied linked list
    temp = copy;
    
    // now separate the original list and copied list
    while(original && copy) {
        original->next = original->next ? original->next->next : original->next;
        copy->next = copy->next ? copy->next->next : copy->next;
        
        original = original->next;
        copy = copy->next;
    }
    
    return temp;
}
/*
Time Complexity: O(n) As we are moving through the list twice, i.e. 2n ,  but in asymptotic notations we drop the constant terms

Auxiliary Space: O(1) As no extra space is used. The n nodes which are inserted in between the nodes was already required to clone the list, so we can say that we did not use any extra space.
*/
