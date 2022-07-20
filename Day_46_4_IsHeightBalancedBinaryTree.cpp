// Method 1:
int height(BinaryTreeNode<int>* root)
{
    if(root==NULL) return 0;
    
    return max(height(root->left), height(root->right)) + 1;
}

bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.
    if(root==NULL) return true;
    
    int lh = height(root->left);
    int rh = height(root->right);
    
    if(abs(lh-rh)<=1 && 
       isBalancedBT(root->left) && isBalancedBT(root->right)) 
        return true;
     
    return false;
}

//--------------------------------------------------

// Method 2:
//simple O(n) soln.
int checkBalanced(BinaryTreeNode<int>* root){
    if(root == NULL)
        return 0;
    
    int left,right;
    left = checkBalanced(root->left);
    right = checkBalanced(root->right);
    if(left == -1|| right == -1)
        return -1;
    if(abs(left - right) > 1)
        return -1;
    return max(left,right)+1;
}

bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.
    return (checkBalanced(root) != -1);
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
