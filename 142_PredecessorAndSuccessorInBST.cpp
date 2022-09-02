// Method 1: Inorder Traversal
#include<vector>
void inorderTraversal(BinaryTreeNode<int>* root, vector<int>& inorder)
{
    if(root==NULL) 
        return ;
    
    inorderTraversal(root->left, inorder);
    inorder.push_back(root->data);
    inorderTraversal(root->right, inorder);
    
    return ;
}

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.
    vector<int> inorder;
    inorderTraversal(root, inorder);
    pair<int, int> ans = make_pair(-1, -1);
    
    for(int i=0; i<inorder.size(); i++)
    {
        if(inorder[i]==key)
        {
            if(i>=1)
                ans.first = inorder[i-1];
            if(i < inorder.size()-1)
                ans.second = inorder[i+1];
            
            return ans;
        }
    } 
}

//-----------------------------------------------------------------

// Method 2:
void inorder_predecessor(BinaryTreeNode<int>* root, int &pred, int key)
{
    while(root != NULL)
    {
        if(root->data < key)
        {
            pred = root->data;
            root = root->right;
        }
        else if(root->data >= key)
        {
            root = root->left;
        }
    }
}

void inorder_successor(BinaryTreeNode<int>* root, int &succ, int key)
{
    while(root != NULL)
    {
        if(root->data > key)
        {
            succ = root->data;
            root = root->left;
        }
        else if(root->data <= key)
        {
            root = root->right;
        }
    }
}

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.
    int pred = -1;
    int succ = -1;
    
    inorder_predecessor(root, pred, key);
    inorder_successor(root, succ, key);
    
    pair<int, int> ans = {pred, succ};
    
    return ans;
}

//-----------------------------------------------------------

// Method 3: 
void inorder_predecessor(BinaryTreeNode<int>* root,int &pred, int key)
{
    while(root!=NULL)
    {
        if(root->data<key)
        {
            pred=root->data;
            root=root->right;
        }
        else if(root->data>=key)
        {
            root=root->left;
        }
    }
}
void inorder_successor(BinaryTreeNode<int>* root,int &succ, int key)
{
    while(root!=NULL)
    {
        if(root->data>key)
        {
            succ=root->data;
            root=root->left;
        }
        else if(root->data<=key)
        {
            root=root->right;
        }
    }
}
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.

    int pred=-1;
    int succ=-1;
    
    inorder_predecessor(root,pred,key);
    inorder_successor(root,succ,key);
    
    pair<int,int>ans= {pred,succ};
    return ans;
}






/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/
