// Method 1: 
void inorder(TreeNode<int> *root, vector<int> &v)
{
    if(root==NULL) return ;
    
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int kthSmallest(TreeNode<int> *root, int k)
{
    // Write the code here.
    vector<int> v;    
    inorder(root, v);   
    if(k > v.size()) return -1;    
    
    return v[k-1];    
}


//----------------------------------------------------------
// Method 2: using stack
#include<stack>
int kthSmallest(TreeNode<int> *root, int k)
{
    // Write the code here.
    stack<TreeNode<int>*> st;
    while(root or !st.empty())
    {
        while(root)
        {
            st.push(root);
            root = root->left;
        }
        
        root = st.top();
        st.pop();
        k--;
        if(k==0) break;
        
        root = root->right;
    }
    
    return root->data;
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
