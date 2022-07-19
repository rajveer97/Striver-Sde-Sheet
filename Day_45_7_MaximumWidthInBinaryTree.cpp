// Method 1: Iterative Solution
#include<queue>
int getMaxWidth(TreeNode<int> *root)
{
    // Write your code here.
    if(!root)
        return 0;
    
    int ans = 0;
    queue<TreeNode<int>*> q;    // node, index
    q.push(root);
    while(!q.empty())
    {
        int size = q.size();  
        ans = max(ans, size);
        
        while(size--)
        {
            TreeNode<int>* curr = q.front();
            q.pop();
            
            if(curr->left)
                q.push(curr->left);
            
            if(curr->right)
                q.push(curr->right);         
        }
    }
    
    return ans;
}
// TC : O(N)
// SC : O(N)

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
