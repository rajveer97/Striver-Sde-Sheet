// Method 1: 
int findCeil(BinaryTreeNode<int> *node, int x){
    // Write your code here.
    auto curr = node;
    int ceil = -1;
    
    if(node==NULL) return -1;
    
    while(curr)
    {
        if(curr->data == x)
            return curr->data;
        else if(curr->data > x)
        {
            ceil = curr->data;
            curr = curr->left;
        }           
        else
        {
            curr = curr->right;
        }
    }
    return ceil;
}

//---------------------------------------------------------

// Method 2:
void inorder(BinaryTreeNode<int> * root, vector<int> &v)
{
    if(root)
    {
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }
}

int findCeil(BinaryTreeNode<int> *root, int X){
    // Write your code here.
    if(root==NULL) return -1;
    vector<int> v;
    inorder(root, v);
    int ans=-1;
    for(int i=0; i<v.size(); i++)
    {
        if(X==v[i])
        {
            ans=v[i];
            break;
        }
        else if(v[i]>X)
        {
            ans=v[i];
            break;
        }
    }
    return ans;
}


/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/
