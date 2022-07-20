// Method 1:
vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    vector<int> ans;
    if(root==NULL) return ans;
    
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    
    bool leftToRight = true;
    while(!q.empty())
    {
        int size = q.size();
        vector<int> row(size);
        
        for(int i=0; i<size; i++)
        {
            BinaryTreeNode<int>* node = q.front();
            q.pop();

            int index = (leftToRight) ? i : (size - 1 - i);

            row[index] = node->data;
            if(node->left) q.push(node->left);               
            if(node->right) q.push(node->right);
        } 
        
        leftToRight = !leftToRight;
        for(int i=0; i<row.size(); i++)
        {
            ans.push_back(row[i]);
        }
        
    }
    
    return ans;
}
// TC : O(N)
// SC : O(N)

//------------------------------------------------------

// Method 2:
#include<algorithm>
vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    vector<int> ans;
    int pos=1;
    if(root==NULL) return ans;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        vector<int> temp;
        for(int i=0;i<size;i++){
            BinaryTreeNode<int>* front=q.front();
            q.pop();
            temp.push_back(front->data);
            if(front->left!=NULL) q.push(front->left);
            if(front->right!=NULL) q.push(front->right);
        }
        if(pos%2==0)
            reverse(temp.begin(),temp.end());
        for(int i=0;i<size;i++)
            ans.push_back(temp[i]);
        pos=!pos;
    }
    
    return ans;    
}


/*************************************************************

    Following is the Binary Tree node structure

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
