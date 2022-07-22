TreeNode<int>* bst(vector<int> &arr, int l, int r)
{
    if(l > r) return NULL;    
    int mid = l + (r - l)/2;
    
    TreeNode<int>* node = new TreeNode<int>(arr[mid]);
    
    node->left = bst(arr, l, mid-1);
    node->right = bst(arr, mid+1, r);
    
    return node;
}

TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    // Write your code here.
    if(n==0) return NULL;
    
    return bst(arr, 0, n-1);
}

/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;
        
        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/