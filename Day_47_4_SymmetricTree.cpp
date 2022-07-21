bool isSymmetricHelp(BinaryTreeNode<int>* leftNode, BinaryTreeNode<int>* rightNode)
{
    if(leftNode==NULL || rightNode==NULL)
        return leftNode==rightNode;
    
    if(leftNode->data != rightNode->data) return false;
    
    return isSymmetricHelp(leftNode->left, rightNode->right) &&
           isSymmetricHelp(leftNode->right, rightNode->left);
}

bool isSymmetric(BinaryTreeNode<int>* root)
{
    // Write your code here. 
    if(root==NULL) return true;
    return isSymmetricHelp(root->left, root->right);    
}

/*****************************************************

    Following is the Binary Tree node structure:
    
    class BinaryTreeNode {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/
