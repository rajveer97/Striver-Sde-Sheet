// Method 1: Using inorder traversal
void inorder(TreeNode<int>* root, vector<int> &v)
{
    if(root==NULL) return ;
    
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int KthLargestNumber(TreeNode<int>* root, int k) 
{
    // Write your code here.
    vector<int> v;
    inorder(root, v);
    
    if(v.size() < k)
        return -1;
    
    return v[v.size() - k];
}


//--------------------------------------------------------
// Method 2: Using stack, Reverse inorder
#include<stack>
int KthLargestNumber(TreeNode<int>* root, int k) 
{
    // Write your code here.
    stack<TreeNode<int>*> st;
    int count = 0;
    
    while(root or !st.empty())
    {
        while(root)
        {
            st.push(root);
            root = root->right;
        }
        //if(s.size()==0 and k>0)return -1;
        root = st.top();
        st.pop();
        k--;
        if(k == 0) 
            break;
        
        root = root->left;
    }
    return root==NULL ? -1 : root->data;
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

