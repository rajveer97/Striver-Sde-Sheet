#include<map>
TreeNode<int>* buildTree(vector<int>& inOrder, int inStart, int inEnd, 
                         vector<int>& postOrder, int postStart, int postEnd,
                        map<int, int> &inMap)
{
    if(inStart > inEnd || postStart > postEnd) return NULL;
    
    TreeNode<int>* root = new TreeNode<int>(postOrder[postEnd]);
    
    int inRoot = inMap[postOrder[postEnd]];
    int numLeft = inRoot - inStart;
    
    root->left = buildTree(inOrder, inStart, inRoot-1,
                           postOrder, postStart, postStart+numLeft-1, inMap);
    
    root->right = buildTree(inOrder, inRoot+1, inEnd,
                            postOrder, postStart+numLeft, postEnd-1, inMap);    
    
    return root;
}

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
    // Write your code here.
    if(postOrder.size() != inOrder.size())
        return NULL;
    
    map<int, int> inMap;
    
    for(int i=0; i<inOrder.size(); i++)
        inMap[inOrder[i]] = i;
    
    TreeNode<int>* root = buildTree(inOrder, 0, inOrder.size()-1, 
                                    postOrder, 0, postOrder.size()-1, inMap);
        
    return root;
}
// TC : O(N)
// SC : O(N)


/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
          { 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
