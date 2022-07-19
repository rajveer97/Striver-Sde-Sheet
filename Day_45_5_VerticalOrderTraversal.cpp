#include<map>
#include<queue>
#include<vector>
vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //    Write your code here.
    vector<int> res;
    if(root==NULL) return res;
    map<int, map<int, vector<int>>> nodes; // line level nodes
    queue<pair<TreeNode<int>*, pair<int, int>>> q; // nodes line level
    q.push({root, {0, 0}});
    while(!q.empty())
    {
        auto p = q.front();
        q.pop();
        TreeNode<int>* node = p.first;
        int x = p.second.first;
        int y = p.second.second;
        
        nodes[x][y].push_back(node->data);
        
        if(node->left)
            q.push({node->left, {x-1, y+1}});
        
        if(node->right)
            q.push({node->right, {x+1, y+1}});
    }
    
    vector<vector<int>> ans;
    for(auto p : nodes)
    {
        vector<int> col;
        for(auto q : p.second)
        {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }
    
    for(auto it : ans)
    {
        for(auto p : it)
        {
            res.push_back(p);
        }
    }
       
    return res;
}


/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/
