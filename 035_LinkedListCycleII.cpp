#include <bits/stdc++.h> 
Node *firstNode(Node *head)
{
    if(head==NULL) return head;
	Node* slow = head;
    Node* fast = head;
    
    while(fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast) {
            slow = head;
            while(slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }

    return NULL;
}