// Method 1: Iterative solution
#include<queue>
#include<map>
vector<int> bottomView(BinaryTreeNode<int> * root){

    // Write your code here.
    vector<int> ans;
    if(root==NULL) return ans;
    map<int, int> mpp; // line, node->data
    queue<pair<BinaryTreeNode<int>*, int>> q;
    q.push({root, 0});
    
    while(!q.empty())
    {
        auto it = q.front();
        q.pop();
        BinaryTreeNode<int>* node = it.first;
        int line = it.second;
        mpp[line] = node->data;
        
        if(node->left != NULL)
            q.push({node->left, line - 1});
        
        if(node->right != NULL)
            q.push({node->right, line + 1});
    }
    
    for(auto it : mpp)
    {
        ans.push_back(it.second);
    }
    
    return ans;
}
// TC : O(N)
// SC : O(N)

// Method 2: Recursive soltion needs special conditions to handle
// so its complicated


/*************************************************************
 
    Following is the Binary Tree node structure.

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
