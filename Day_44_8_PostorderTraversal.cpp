// Method 1: Iterative solution using stack 
// --- O(n) time and O(n) space;
vector<int> getPostOrderTraversal(TreeNode *root)
{
    // Write your code here.
    // LRN ( Left Side, Right Side, Node)
    if(root == NULL)
    {
        return {};
    }
    vector<int> ans;
    stack<TreeNode*> s;
    s.push(root);
    while(!s.empty())
    {
        TreeNode* curr = s.top();
        if(curr->left)
        {
            s.push(curr->left);
            curr->left = NULL;
        }
        else
        {
            if(curr->right)
            {
                s.push(curr->right);
                curr->right = NULL;
            }
            else
            {
                ans.push_back(curr->data);
                s.pop();
            }
        }
    }
    return ans;
}

// -------------------------------------------------


// Method 2: Recursive solution 
//--- O(n) time and O(n) space (function call stack);
void postOrder(TreeNode *root, vector<int> &nodes)
{
    if(root == NULL)
        return ;
    
    postOrder(root->left, nodes);
    postOrder(root->right, nodes);     
    nodes.push_back(root->data);
}

vector<int> getPostOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> nodes;
    postOrder(root, nodes);
    return nodes;
}

//---------------------------------------------------

// Method 3: Morris traversal 
// --- O(n) time and O(1) space.
void reverseNodes(TreeNode* start, TreeNode* end) 
{
    if (start == end) 
    {
        return;
    }
    TreeNode* x = start;
    TreeNode* y = start -> right;
    TreeNode* z;
    while (x != end) 
    {
        z = y -> right;
        y -> right = x;
        x = y;
        y = z;
    }
}
    
void reverseAddNodes(TreeNode* start, TreeNode* end, vector<int>& nodes) 
{
    reverseNodes(start, end);
    TreeNode* node = end;
    while (true) 
    {
        nodes.push_back(node -> data);
        if (node == start) 
        {
            break;
        }
        node = node -> right;
    }
    reverseNodes(end, start);
}

vector<int> getPostOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> nodes;
    TreeNode* dummy = new TreeNode(0);
    dummy -> left = root;
    TreeNode* cur = dummy;
    while (cur) 
    {
        if (cur -> left) 
        {
            TreeNode* pre = cur -> left;
            while (pre -> right && (pre -> right != cur)) 
            {
                pre = pre -> right;
            }
            if (!(pre -> right)) 
            {
                pre -> right = cur;
                cur = cur -> left;
            } 
            else 
            {
                reverseAddNodes(cur -> left, pre, nodes);
                pre -> right = NULL;
                cur = cur -> right;
            }
        } 
        else 
        {
            cur = cur -> right;
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
