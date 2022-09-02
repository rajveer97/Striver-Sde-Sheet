/*
As we can see in the question ,flatten linked list is nothing 
but preorder traversal of tree.

Approach 1)
we can do preorder traversal of tree and store in an array and 
then form a linked list from the  array. 

This Solution takes O(N) Time Complexity and O(N) space Complexity.

Approach 2)
we create a head and tail of linked list. 
initially , head = tail = NULL

When we perform preorder traversal. 
they will have two case

1st) if head is NULL
             head=tail=new Node(TreeNode→val);

2nd) else
             tail→next=  new Node(TreeNode→val);
             tail=tail→next;

This Solution requires O(N) time complexity and in worst case O(N) 
auxilary space when tree is flatten.

Approach 3)
To perform preorder traversal in constant space (Morris Algorithm is used)
This solution requires O(N) time complexity and O(1) space complexity.
*/

//--------------------------------------------------

// Method 1:
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    // Write your code here.
    // Right Left Root
    if(root==NULL) return false;    
    TreeNode<int>* originalRight = root->right;
    root->right = flattenBinaryTree(root->left);
    TreeNode<int>* temp = root;
    while(temp->right != NULL)
    {
    temp=temp->right;
    }
    
    temp->right = flattenBinaryTree(originalRight);
    root->left = NULL;
    
    return root;
}

//--------------------------------------------------

// Method 2:
#include<stack>
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    // Write your code here.
    // Right Left Root
    if(root==NULL) return root;
    
    stack<TreeNode<int>*> st;
    st.push(root);
    
    TreeNode<int>* r = root;
    
    while(!st.empty())
    {
        TreeNode<int>* curr = st.top();
        st.pop();
        
        if(curr->right) st.push(curr->right);
        if(curr->left)  st.push(curr->left);
        if(!st.empty()) curr->right = st.top();
        curr->left = NULL;
    }
    
    return r;
}

/************************************************************

    Following is the TreeNode class structure.

    template <typename T>
    class TreeNode {
        public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
