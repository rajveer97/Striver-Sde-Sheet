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
Node *addTwoNumbers(Node *head1, Node *head2)
{
    Node* sumList = new Node(-1);
    Node* temp = sumList;
    int carry = 0;
    while(head1 != NULL || head2 != NULL || carry)
    {
        int sum = 0;
        if(head1) {
            sum += head1->data;
            head1 = head1->next;
        }
        
        if(head2) {
            sum += head2->data;
            head2 = head2->next;
        }
        
        sum += carry;
        carry = sum/10; 
        Node* curr = new Node(sum%10);
        temp->next = curr;
        temp = temp->next;
    }
    
    return sumList->next;
}