#include<sstream>
// Encodes a tree to a single string
string serializeTree(TreeNode<int> *root)
{
    //Write your code here for serializing the tree
    if(!root) return "";
    string s = "";
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode<int> *curr = q.front();
        q.pop();
        if(curr == NULL) s.append("#,");
        else 
            s.append(to_string(curr->data) + ',');
        
        if(curr != NULL)
        {
            q.push(curr->left);
            q.push(curr->right);
        }
    }
    return s;
}

// Decodes your Encoded data to tree
TreeNode<int>* deserializeTree(string &serialized)
{
    //Write your code here for deserializing the tree
    if(serialized.size()==0) return NULL;
    stringstream s(serialized);
    string str;
    getline(s, str, ',');
    TreeNode<int>* root = new TreeNode<int> (stoi(str));
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode<int>* curr = q.front();
        q.pop();
        
        getline(s, str, ',');
        if(str == "#")
            curr->left = NULL;
        else
        {
            TreeNode<int>* leftN = new TreeNode<int>(stoi(str));
            curr->left = leftN;
            q.push(leftN);
        }
        
        getline(s, str, ',');
        if(str == "#")
            curr->right = NULL;
        else
        {
            TreeNode<int>* rightN = new TreeNode<int>(stoi(str));
            curr->right = rightN;
            q.push(rightN);
        }       
    }
    return root;
}

//---------------------------------------------------------
// Method 2:
void serialize(TreeNode<int> *root, string &ans){
    if(root==NULL){
        ans = ans + to_string(-1);
        return;
    }
    queue<TreeNode<int>*> q;
    q.push(root);
    
    while(!q.empty()){
        TreeNode<int> *cur = q.front();
        q.pop();
        
        if(cur==NULL){
            ans=ans+to_string(-1)+",";
            continue;
        }
        ans=ans+to_string(cur->data)+",";
        q.push(cur->left);
        q.push(cur->right);
    }
}
string serializeTree(TreeNode<int> *root)
{
 //    Write your code here for serializing the tree
    string ans = "";
    serialize(root,ans);
//     cout<<ans<<endl;
    return ans;
}

TreeNode<int>* deserializeTree(string &serialized)
{
 //    Write your code here for deserializing the tree
    int i=0,n=serialized.size();
    if(serialized=="-1")
        return NULL;
    
    string t="";
    while(serialized[i]!=','){
        t=t+serialized[i];
        i++;
    }
    i++;
    
    TreeNode<int> *root = new TreeNode<int> (stoi(t));
    queue<TreeNode<int>*> q;
    q.push(root);
    
    while(!q.empty() && i<n){
        TreeNode<int>* cur = q.front();
        q.pop();
        
        string t1="";
        while(i<n && serialized[i]!=','){
            t1=t1+serialized[i];
            i++;
        }
        i++;
        if(t1!=""){
            if(t1!="-1"){
                cur->left = new TreeNode<int> (stoi(t1));
                q.push(cur->left);
            }
        }
        
        string t2="";
        while(i<n && serialized[i]!=','){
            t2=t2+serialized[i];
            i++;
        }
        i++;
        if(t2!=""){
            if(t2!="-1"){
                cur->right = new TreeNode<int> (stoi(t2));
                q.push(cur->right);
            }
        }
    }
    
    return root;
}



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