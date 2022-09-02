// Method 1: Inorder Traversal
void inorder(BinaryTreeNode<int>* root, vector<int> &v)
{
    if(root==NULL)
        return ;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right,v);
}

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    // Write your code here
    vector<int> v;      
    inorder(root, v);
    int i=0, j= v.size()-1;

    while(i<j)
    {
        if(v[i] + v[j] == k)
            return true;
        else 
        {
            if(v[i] + v[j] > k)
                j--;
            else
                i++;
        }
    }

    return false;
}

//-----------------------------------------------------------

// Method 2: using set
#include<unordered_set>
bool solve(BinaryTreeNode<int> *root, int k, unordered_set<int> &s)
{
    if(!root) return false;
    
    if(s.find(k - root->data) != s.end())
        return true;
    s.insert(root->data);
    return solve(root->left, k, s) or solve(root->right, k, s);
}

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    // Write your code here
    unordered_set<int> s;
    return solve(root, k, s);
}

/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
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
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
