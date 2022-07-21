#include<map>
TreeNode<int>* buildTree(vector<int> &preorder, int preStart, int preEnd,
                         vector<int> &inorder, int inStart, int inEnd, 
                         map<int, int>& inMap)
{
    if(preStart > preEnd || inStart > inEnd) return NULL;
    
    // creating new node using preorder vector
    TreeNode<int>* root = new TreeNode<int>(preorder[preStart]);
    
    // finding the index of root
    int inRoot = inMap[root->data];
    int numsLeft = inRoot - inStart;
    
    // adding the left node 
    root->left = buildTree(preorder, preStart+1, preStart+numsLeft,
                           inorder, inStart, inRoot-1, inMap);
    
    // adding the right node
    root->right = buildTree(preorder, preStart+numsLeft+1, preEnd,
                            inorder, inRoot+1, inEnd, inMap);
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    // Write your code here
    map<int, int> inMap;
    
    for(int i=0; i<inorder.size(); i++)
        inMap[inorder[i]] = i;

    // call bulidTree function  
    TreeNode<int>* root = buildTree(preorder, 0, preorder.size()-1, 
                                    inorder, 0, inorder.size()-1, inMap);
     
    return root;
}
// TC : O(N)
// SC : O(N)

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
