#include<stack>
bool helper(TreeNode<int> *root, TreeNode<int> *leaf, stack<TreeNode<int>*> &st)
{
    st.push(root);
    
    if(!root->left && !root->right)
    {
        if(root->data == leaf->data)
            return true;
        else
        {
            st.pop();
            return false;
        }       
    }
    
    if(root->left)
    {
        if(helper(root->left, leaf, st))
            return true;
    }
    
    if(root->right)
    {
        if(helper(root->right, leaf, st))
            return true;
    }
    
    st.pop();
    return false;
}

TreeNode<int> * invertBinaryTree(TreeNode<int> *root, TreeNode<int> *leaf)
{
    // Write your code here.
    if(!root) return NULL;
    
    stack<TreeNode<int>*> st;
    bool flag = helper(root, leaf, st);
    
    TreeNode<int>* new_root = st.top();
    st.pop();
    TreeNode<int> *par = new_root;
    
    while(!st.empty())
    {
        auto curr = st.top();
        st.pop();
        
        if(curr->left == par)
        {
            curr->left = NULL;
            par->left = curr;
        }
        else
        {
            curr->right = curr->left;
            curr->left = NULL;
            par->left = curr;
        }
        
        par = curr;
    }
    return new_root;
}

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
