
// Method 1: Iterative solution using stack: 
// Complexity : O(n) time and O(n) space;
vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> nodes;
    stack<TreeNode*> st;
    
    while(root || !st.empty())
    {
        while(root)
        {
            st.push(root);
            root = root->left; 
        }
        
        root = st.top();
        st.pop();
        nodes.push_back(root->data);
        root = root->right;        
    }
    return nodes;
}


//-------------------------------------------------------

// Method 2: Recursive Approach
void inOrder(TreeNode *root, vector<int> &ans)
{
    // Base case
    if(root==NULL) return;
    
    // first recur on left subtree
    inOrder(root->left, ans);
    
    // now deal with the node
    ans.push_back(root->data);
    
    // then recur on right subtree
    inOrder(root->right,ans);
}

vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> ans;
    if(root==NULL) return ans;
    
    inOrder(root, ans);
        
    return ans;
}
/*
Time Complexity: O(n) 
Auxiliary Space: If we don’t consider the size of the stack 
for function calls then O(1) otherwise O(h) where h is the 
height of the tree. 
*/

//------------------------------------------------------

// Method 3: Morris traversal: O(n) time and O(1) space.
vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> nodes;
    while (root) {
        if (root -> left) 
        {
            TreeNode* pre = root -> left;
            while (pre -> right && pre -> right != root) 
            {
                pre = pre -> right;
            }
            if (!pre -> right) 
            {
                pre -> right = root;
                root = root -> left;
            } 
            else 
            {
                pre -> right = NULL;
                nodes.push_back(root -> data);
                root = root -> right;
            }
        } 
        else 
        {
            nodes.push_back(root -> data);
            root = root -> right;
        }
    }
    return nodes;
}


/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/