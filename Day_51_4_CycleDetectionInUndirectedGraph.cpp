// Method 1: BFS Traversal
#include<unordered_map>
#include<queue>
#include<list>
bool isCycleBFS(int node, unordered_map<int, bool> &visited, 
                unordered_map<int, list<int>> &adj_list)
{
    unordered_map<int, int> parent;
    parent[node] = -1;
    visited[node] = true;
    
    queue<int> q;
    q.push(node);
    
    while(!q.empty())
    {
        int front = q.front();
        q.pop();
        
        for(auto neighbour : adj_list[front])
        {
            if(visited[neighbour]==true && neighbour != parent[front])
            {
                return true;
            }
            else if(!visited[neighbour])
            {
                q.push(neighbour);
                
                visited[neighbour] = true;
                parent[neighbour] = front;
            }
        }
        
    }
    
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    unordered_map<int, list<int>> adj_list;
    
    // create adjacency list
    for(int i=0; i<m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj_list[v].push_back(u);
        adj_list[u].push_back(v);
    }
    
    unordered_map<int, bool> visited;    
    // to handle the disconnected components
    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            bool ans = isCycleBFS(i, visited, adj_list);
            if(ans == true)
                return "Yes";
        }
    }
    
    return "No";
}

//-------------------------------------------------------------

// Method 2: Using DFS Traversal
#include<unordered_map>
#include<queue>
#include<list>
bool isCycleDFS(int node, int parent, unordered_map<int, list<int>> &adj_list, 
                unordered_map<int, bool> &visited)
{
    visited[node] = true;
    for(auto neighbour : adj_list[node])
    {
        if(!visited[neighbour])
        {
            if(isCycleDFS(neighbour, node, adj_list, visited))
                return true;            
        }
        else if(parent != neighbour)
            return true;
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    unordered_map<int, list<int>> adj_list;
    
    // create adjacency list
    for(int i=0; i<m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj_list[v].push_back(u);
        adj_list[u].push_back(v);
    }
    
    unordered_map<int, bool> visited;    
    // to handle the disconnected components
    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            if(isCycleDFS(i, -1, adj_list, visited))
                return "Yes";
        }
    }
    
    return "No";
}