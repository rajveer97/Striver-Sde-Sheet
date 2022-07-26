Notes :
Bipartite graph: Graph that can be colored using 2 colors 
such that no two adj have same color.

Logically, if there is cycle in graph and cycle have odd numbers of 
nodes then its not a Biparite Graph.
And if there is even number of nodes in cycle then its Bipartite.
Also if there is no Cycle  then its a Bipartite graph
*/


// Method 1: Using BFS 
#include<queue>
bool bfs(int node, vector<int> adj[], vector<int> &color)
{
    queue<int> q;
    q.push(node);
    while(!q.empty())
    {
        int currNode = q.front();
        q.pop();
        
        for(auto it : adj[currNode])
        {
            if(color[it] == -1)
            {
                color[it] = 1 - color[currNode];
                q.push(it);
            }
            // adj nodes have same color
            else if(color[it] == color[currNode]) 
                return false;
        }
    }
    return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges) 
{
    // Write your code here.
    int n = edges.size();
    vector<int> adj[n]; // array of vector data type
    
    //create adj list
    for(int i=0; i<n; i++)
    {      
        for(int j=0; j<n; j++)
        {
            if(edges[i][j]==1)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    
    vector<int> color(n, -1);  
    // traverse all the components
    for(int i=0; i<n; i++)
    {
        if(color[i] == -1)
        {
            color[i] = 1;
            if(!bfs(i, adj, color))
                return false;
        }       
    }
    
    return true;
}

//-------------------------------------------------

// Method 2: Using DFS 
#include<vector>
bool dfs(int node, vector<int> adj[], vector<int> &color)
{
    for(auto it : adj[node])
    {
        if(color[it] == -1)
        {
            color[it] = 1 - color[node];
            if(!dfs(it, adj, color))
                return false;
        }
        else if(color[it]==color[node])
            return false;
    }
    
    return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges) 
{
    // Write your code here.
    int n = edges.size();
    vector<int> adj[n]; // array of vector data type
    
    //create adj list
    for(int i=0; i<n; i++)
    {      
        for(int j=0; j<n; j++)
        {
            if(edges[i][j]==1)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    
    vector<int> color(n, -1);  
    // traverse all the components
    for(int i=0; i<n; i++)
    {
        if(color[i] == -1)
        {
            color[i] = 1;
            if(!dfs(i, adj, color))
                return false;
        }       
    }
    
    return true;   
}