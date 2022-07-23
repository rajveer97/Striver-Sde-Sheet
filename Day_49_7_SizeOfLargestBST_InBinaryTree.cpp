// Method 1:
#include<vector>
#include<algorithm>
void solveinorder(TreeNode<int>* root,vector<int>&inorder,int &count)
{
    if(root==NULL)
        return;
    else
      count++;

    solveinorder(root->left,inorder,count);
    inorder.push_back(root->data);
    solveinorder(root->right,inorder,count);
}

bool isBST(TreeNode<int>* root,int &count)
{

    vector<int>inorder;
    solveinorder(root,inorder,count);
    vector<int>check=inorder;
    sort(check.begin(),check.end());

    if(check==inorder)
        return true;

    return false;
}

void solve(TreeNode<int>* root,vector<int>&possible)
{
    if(root==NULL)
        return;
    
    int count=0;
    if(isBST(root,count))
    {
        possible.push_back(count);
    }

    solve(root->left,possible);
    solve(root->right,possible);
}

int largestBST(TreeNode<int>* root)  
{
    // Write your code here.
    vector<int>possible;
    solve(root,possible);

    int max=INT_MIN;

    for(int i=0;i<possible.size();i++)
    {
         if(possible[i]>max)
             max=possible[i];       
    }

    return max;
}

//------------------------------------------------------

// Method 2: Optimized Solution
class NodeValue
{
    public: 
        int maxSize, maxValue, minValue;
    
    public:
    NodeValue(int minValue, int maxValue, int maxSize)
    {
        this->minValue = minValue;
        this->maxValue = maxValue;
        this->maxSize = maxSize;
    }    
};

NodeValue largestBSTHelper(TreeNode<int>* root)
{
    // An empty tree is a BST of size 0.
    // maxValue to be the extream small
    // minValue to be the extream larger
    // To make it comparable
    if(!root)
        return NodeValue(INT_MAX, INT_MIN, 0);
    
    // Get values from left and right subtree of current tree.
    auto left = largestBSTHelper(root->left);
    auto right = largestBSTHelper(root->right);
    
    //Current node is greater than max value in left AND smaller than 
    //min value in right, it is a BST.
    if(left.maxValue < root->data && root->data < right.minValue)
    {
        return NodeValue(min(root->data, left.minValue), 
                         max(root->data, right.maxValue), 
                         left.maxSize + right.maxSize + 1);
    }
    
    // Otherwise, return [-inf, inf] so that parent can't be valid BST
    return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
}

int largestBST(TreeNode<int>* root) 
{
    // Write your code here.
    return largestBSTHelper(root).maxSize;
}

/************************************************************

    Following is the Binary Tree node structure
    
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

