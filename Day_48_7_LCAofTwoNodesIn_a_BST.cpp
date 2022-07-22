// Method 1: 
TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
    // Write your code here
    if(root==NULL) return NULL;
    
    if(root->data > P->data && root->data > Q->data)
        return LCAinaBST(root->left, P, Q);
    
    if(root->data < P->data && root->data < Q->data)
        return LCAinaBST(root->right, P, Q);
    
    // you are at the LCA if upper conditions are false
    return root;
}
// TC : O(Height)

//---------------------------------------------------------
// Method 2: Iterative 
TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
    // Write your code here
    if(root==NULL) return NULL;
    
    while(root)
    {
        if(root->data > P->data && root->data > Q->data)
            root = root->left;
        else if(root->data < P->data && root->data < Q->data)
            root = root->right;
        else
            return root;
    }
}


/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
