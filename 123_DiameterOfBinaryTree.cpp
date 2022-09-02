// Method 1: Naive Solution
// Recursive Solution
int height(TreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    int leftheight=height(root->left);
    int rightheight=height(root->right);
    int mx=max(leftheight,rightheight);
    return mx+1;
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
    // Write Your Code Here.
    if(root==NULL){
        return 0;
    }
    int leftheight = height(root->left);
    int rightheight = height(root->right);
    int leftdiameter = diameterOfBinaryTree(root->left);
    int rightdiameter = diameterOfBinaryTree(root->right);
    int finalans = max(max(leftdiameter, rightdiameter), leftheight + rightheight);
    return finalans;
}
// TC : O(N^2), O(N) to traverse and O(N) to find heights to each nodes 

//--------------------------------------------------------

// Method 2: Optimized Recursion Approach
int height(TreeNode<int> *root, int &diameter)
{
    if(root==NULL)
        return 0;
    
    int lh = height(root->left, diameter);
    int rh = height(root->right, diameter);
    
    diameter = max(diameter, (lh + rh));
    
    return 1 + max(lh, rh);
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
    // Write Your Code Here.
    int diameter = 0;
    height(root, diameter);
    return diameter;
}
// TC : O(N)

/************************************************************

    Following is the TreeNode class structure

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