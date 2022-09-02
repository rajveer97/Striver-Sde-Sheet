// Method 1: Brute Force
void inorder(BinaryTreeNode<int>* root, vector<int> &v)
{
    if(root==NULL)
        return ;
    
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    // Write your code here
    vector<int> v;
    inorder(root, v);
    
    BinaryTreeNode<int>* dummy = new BinaryTreeNode<int>(-1);
    BinaryTreeNode<int>* head = dummy;
    
    for(int i=0; i<v.size(); i++)
    {
        BinaryTreeNode<int>* curr = new BinaryTreeNode<int>(v[i]);
        curr->left = head;
        head->right = curr;
        head = curr;       
    }
    
    head->right = NULL;
    
    return dummy->right;
}

//--------------------------------------------------------------

// Method 2:
void helper(BinaryTreeNode<int>* root, BinaryTreeNode<int>* &head, BinaryTreeNode<int>* &prev)
{
    if(root==NULL)
        return ;
    
    helper(root->left, head, prev);
    if(prev==NULL)
        head = root;
    else
    {
        root->left = prev;
        prev->right = root;
    }   
    prev = root;
    
    helper(root->right, head, prev);    
}

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    // Write your code here
    BinaryTreeNode<int> *head = NULL, *prev = NULL;
    helper(root, head, prev);
    return head;
}

/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
