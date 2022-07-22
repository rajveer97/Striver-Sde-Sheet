// Method 1:
#include<vector>
#include<limits.h>

TreeNode<int>* formBST(vector<int> &pre, int &idx, int bound){
    if(idx == pre.size() || pre[idx] > bound) return NULL;
    TreeNode<int> *root = new TreeNode<int>(pre[idx++]);
    root->left = formBST(pre, idx, root->data);
    root->right = formBST(pre, idx, bound);
    return root;
}

TreeNode<int>* preOrderTree(vector<int> &preOrder){
    int idx = 0;
    return formBST(preOrder, idx, INT_MAX);
}
// TC : O(N)

//-------------------------------------------------------
/*
// Method 2: 
TreeNode<int>* buildBST(TreeNode<int>* &root, int ele)
{
    if(!root)
        return root = new TreeNode<int>(ele);
    
    if(root->data > ele)
        root->left = buildBST(root->left, ele);
    else
        root->right = buildBST(root->right, ele);
    
    return root;
}

TreeNode<int>* preOrderTree(vector<int> &preOrder){
    // Write your code here.
    TreeNode<int>* root = NULL;
    
    for(auto x : preOrder)
        buildBST(root, x);
    
    return root;
}
// TC : O(N^2)


/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
