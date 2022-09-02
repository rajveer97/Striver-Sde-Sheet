// Method 1: Iterative Solution
#include<vector>
bool isLeaf(TreeNode<int>* root)
{
    if(!root->left and !root->right) return true;
    else return false;
}

void addLeftBoundary(TreeNode<int>* root, vector<int> &res)
{
    TreeNode<int>* curr = root->left;
    while(curr)
    {
        if(!isLeaf(curr)) res.push_back(curr->data);
        if(curr->left) curr = curr->left;
        else curr = curr->right;
    }   
}

void addLeaf(TreeNode<int>* root, vector<int> &res)
{
    if(isLeaf(root))
    {
        res.push_back(root->data);
        return;
    }
    
    if(root->left) addLeaf(root->left, res);
    if(root->right) addLeaf(root->right, res);
}

void addRightBoundary(TreeNode<int>* root, vector<int> &res)
{
    TreeNode<int>* curr = root->right;
    vector<int> temp;
    while(curr)
    {
        if(!isLeaf(curr))  temp.push_back(curr->data);
        if(curr->right) curr = curr->right;
        else
            curr = curr->left;
    }
    
    for(int i = temp.size()-1; i>=0; i--)
    {
        res.push_back(temp[i]);
    }
}

vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    // addLeft -> addleaf -> addRight
    vector<int> res;
    if(root==NULL) return res;
    
    if(!isLeaf(root)) res.push_back(root->data);
    
    addLeftBoundary(root, res);
    addLeaf(root, res);
    addRightBoundary(root, res);
    
    return res;
}


//-----------------------------------------------------

// Method 2: Recursive Approach
void leftWall(TreeNode<int> *root,vector<int> &v){
   if(!root)return;
    
   if(root->left || root->right)
   {
   v.push_back(root->data);        
   }
    
   if(root->left)
   {
       leftWall(root->left,v);
   }
    else
    {
       leftWall(root->right,v);
   }
}

void rightWall(TreeNode<int> *root,vector<int> &v){
   if(!root)return;
      
   if(root->right)
   {
       rightWall(root->right,v);
   }
    else
    {
       rightWall(root->left,v);
   }
   if(root->left || root->right)
   {
       v.push_back(root->data);        
   }
}
void bottomView(TreeNode<int> *root,int value,vector<int> &v){
   if(!root)return;
   
   if(!root->left && !root->right)
   {
       v.push_back(root->data);
   }
   
   if(root->left)
   {
       bottomView(root->left,value - 1,v);
   }
   if(root->right)
   {
       bottomView(root->right,value + 1,v);
   }
}

vector<int> traverseBoundary(TreeNode<int>* root){
   // left wall | right wall | bottom view 
   if(!root)return {};
   vector<int> ans;
   ans.push_back(root->data);
   leftWall(root->left,ans);
   bottomView(root->left,0,ans);
   bottomView(root->right,0,ans);
   rightWall(root->right,ans);
   return ans;
    
}


/************************************************************

    Following is the Binary Tree node structure:
    
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
