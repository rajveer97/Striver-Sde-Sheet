// Method 1: Naive Solution
// Use two separate arrays to store both paths
void findPath(TreeNode<int> *root, int num, vector<int> &path)
{
    if(root==NULL) return ;
    
    path.push_back(root->data);
    
    if(root->data == num) return;
    
    findPath(root->left, num, path);
    findPath(root->right, num, path);
    
    if(path[path.size()-1] != num)
        path.pop_back();
}

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
    //    Write your code here
    vector<int> x_path, y_path;
    
    findPath(root, x, x_path);
    findPath(root, y, y_path);
    
    int n = x_path.size();
    int m = y_path.size();
    
    int lca;
    int i=0, j=0;
    while(i<n && j<m)
    {
        if(x_path[i] == y_path[j]) 
            lca = x_path[i];
        
        i++;
        j++;
    }
    
    return lca;
}
// TC : O(N)
// SC : O(N)

//---------------------------------------------------

// Method 2: Recursive 
int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
    //    Write your code here
    if(root==NULL)
        return -1;
    
    if(root->data==x || root->data==y)
        return root->data;
    
    int left = lowestCommonAncestor(root->left, x, y);
    int right = lowestCommonAncestor(root->right, x, y);
    
    if(left == -1)
        return right;
    
    else if(right == -1)
        return left;
    
    else 
        return root->data;   
}
// TC : O(N)
// AS : O(N)



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
