// Method 1: Recursive Soution
#include<vector>
void inOrderT(BinaryTreeNode<int> *root, vector<int> &inOrder)
{
    if(root==NULL)
        return ;
    
    inOrderT(root->left, inOrder);
    inOrder.push_back(root->data);
    inOrderT(root->right, inOrder);
}

void preOrderT(BinaryTreeNode<int> *root, vector<int> &preOrder)
{
    if(root==NULL)
        return ;
    
    preOrder.push_back(root->data);
    preOrderT(root->left, preOrder);    
    preOrderT(root->right, preOrder);
}

void postOrderT(BinaryTreeNode<int> *root, vector<int> &postOrder)
{
    if(root==NULL)
        return ;
    
    postOrderT(root->left, postOrder);    
    postOrderT(root->right, postOrder);
    postOrder.push_back(root->data);
}


vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    vector<int> inOrder;
    vector<int> preOrder;
    vector<int> postOrder;
    
    inOrderT(root, inOrder);
    preOrderT(root, preOrder);
    postOrderT(root, postOrder);  
    
    return {inOrder, preOrder, postOrder};
}


/************************************************************

    Following is the Binary Tree node structure:

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


************************************************************/
