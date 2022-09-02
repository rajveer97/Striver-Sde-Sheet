// Method 1: Iterative Solution - Using Inorder travsersal
int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
    auto curr = root;
    int ans = -1;
    
    while(curr)
    {
        if(curr->val > X)
            curr = curr->left;
        else
        {
            ans = curr->val;
            curr = curr->right;
        }
    }
    return ans;
}

//-------------------------------------------------------

// Method 2:
void inOrderTraversal(TreeNode<int>* root, vector<int> &v)
{
    if(root==NULL) return ;
    
    inOrderTraversal(root->left, v);
    v.push_back(root->val);
    inOrderTraversal(root->right, v);    
}

int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
    vector<int> v;
    inOrderTraversal(root, v);
    
    int ans;
    
    if(root==NULL) return -1;
    
    for(int i=0; i<v.size(); i++)
    {
        if(v[i] <= X)
            ans = v[i];
    }
    
    return ans;
}

//------------------------------------------------------

// Method 1: Recursive Approach
int findFloor(TreeNode<int>* root, int &X, int &ans)
{
    if(root==NULL) return ans;
    
    if(root->val <= X)
    {
        ans = root->val;
        findFloor(root->right, X, ans);
    }
    else
        findFloor(root->left, X, ans);
    
    return ans;
}

int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
    int ans = root->val;
    if(root==NULL) return ans;
    
    findFloor(root, X, ans);
    
    return ans;
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
