#include<queue>
void connectNodes(BinaryTreeNode< int > *root) {
    // Write your code here.
    if(root==NULL) return ;
       
    queue<BinaryTreeNode<int> *> q;
    q.push(root);

    while(!q.empty())
    {
        int n = q.size();
        BinaryTreeNode<int> *prev = NULL;

        for(int i=0; i<n; i++)
        {
            BinaryTreeNode<int>* currNode = q.front();
            q.pop();

            if(prev != NULL)
            {
                prev->next = currNode;
            }

            prev = currNode;

            if(currNode->left) q.push(currNode->left);
            if(currNode->right) q.push(currNode->right);
        }

        prev = NULL;
    }
}

/*----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/
