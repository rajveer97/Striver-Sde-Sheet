// Method 1: Recursive
void leftView(TreeNode<int>* root, vector<int> &ds, int level)
{
    if(root==NULL)
        return ;
    
    if((ds.size()==level) && root)
        ds.push_back(root->data);
    
    leftView(root->left, ds, level+1);
    leftView(root->right, ds, level+1);
}

vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    vector<int> ds;
    leftView(root, ds, 0);
    return ds;
}
// TC: O(N)
// SC: O(h)


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