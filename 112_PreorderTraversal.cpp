// Method 1: Iterative solution using stack --- 
// O(n) time and O(n) space;
vector<int> getPreOrderTraversal(TreeNode *root)
{
    // Write your code here.
    // NLR ( Node , Left Side, Right Side)
    vector<int> nodes;
    if(root==NULL) return nodes;
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty())
    {
        root = st.top();
        st.pop();
        
        nodes.push_back(root->data);
        if(root->right != NULL) st.push(root->right);
        if(root->left != NULL) st.push(root->left);      
    }
    return nodes;
}

//--------------------------------------------------

// Method 2: Recursive solution --- 
// O(n) time and O(n) space (function call stack)
void preOrder(TreeNode* root, vector<int> &nodes)
{
    // base case
    if(root==NULL)
        return ;
    
    nodes.push_back(root->data);
    preOrder(root->left, nodes);
    preOrder(root->right, nodes);
}

vector<int> getPreOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> nodes;
    preOrder(root, nodes);
    return nodes;
}


//--------------------------------------------

// Method 3: Morris traversal --- O(n) time and O(1) space.
vector<int> getPreOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> nodes;
        while (root) 
        {
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
                    nodes.push_back(root -> data);
                    root = root -> left;
                } 
                else 
                {
                    pre -> right = NULL;
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