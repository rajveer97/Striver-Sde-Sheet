#define lli long long int
lli findMaxPath(TreeNode<int>* node, lli &maxi)
{
    if(node == NULL) return 0;
    
    lli left = findMaxPath(node->left, maxi);
    lli right = findMaxPath(node->right, maxi);
    maxi = max(maxi, left + right + node->val);
    
    return max(left, right) + node->val;
}

long long int findMaxSumPath(TreeNode<int> *root)
{
    // Write your code here.
    if(root==NULL) return -1;
    if(root->left==NULL || root->right==NULL) return -1;
    
    lli maxi = 0;
    findMaxPath(root, maxi);
    return maxi;
}


/************************************************************

    Following is the Tree node structure
    
    template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
