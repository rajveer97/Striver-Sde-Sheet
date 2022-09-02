// Method 1: Usinging Inorder Traversal
void inorder(BinaryTreeNode<int> *root, vector<int> &v)
{
    if(root==NULL) return ;
    
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    vector<int> v;
    inorder(root, v);
    for(int i=1; i<v.size(); i++)
    {
        if(v[i]<v[i-1])
            return false;
    }
    return true;
}

//----------------------------------------------------------

// Method 2:
bool isValid(BinaryTreeNode<int> *root, int min, int max)
{
    if(!root) return true;
    
    if(root->data < min || root->data > max)
        return false;
    
    bool leftChild = isValid(root->left, min, root->data);
    bool rightChild = isValid(root->right, root->data, max);
    
    return leftChild && rightChild;
}

bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    return isValid(root, INT_MIN, INT_MAX);
}

//-----------------------------------------------------
// Method 3:
void checkvalid(BinaryTreeNode<int> *root, bool &flag){
   if(root == NULL){
       return;
   }
   if(root -> left ){
       if(root -> left -> data > root -> data){
           flag = false;
           return;
       }
   }
   if(root -> right){
       if(root -> right -> data < root -> data){
           flag = false;
           return;
       }
   }
   checkvalid(root -> left, flag);
   checkvalid(root -> right, flag);
   return;
}
bool validateBST(BinaryTreeNode<int> *root) {
   if(root == NULL){
       return true;
   }
   bool flag = true;
   checkvalid(root, flag);
   return flag;
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
