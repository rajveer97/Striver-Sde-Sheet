// Method 1: Kahn's algorithm (Directed Acyclic Graph) (BFS)
#include<queue>
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<int> indegree(v, 0);
    vector<int> adj[v];
    
    // make adjacecy list
    for(auto x : edges)
        adj[x[0]].push_back(x[1]);
    
    // store the indegree of each vertices 
    for(int i=0; i<v; i++)
    {
        for(auto x : adj[i])
            indegree[x]++;
    }
    
    queue<int> q;
    vector<int> topoSort;
    // add all vertices with indegree as zero in queue
    for(int i=0; i<v; i++)
    {
        if(indegree[i] == 0)
            q.push(i);
    }
    
    // BFS Traversal
    while(!q.empty())
    {
        int td = q.front();
        q.pop();
        topoSort.push_back(td);
        
        // for every adjacent node of td
        for(int x : adj[td])
        {
            // reduce the indegree of node by 1
            // if indegree becomes 0 add node to queue
            indegree[x]--;
            if(indegree[x]==0)
                q.push(x);
        }
    }
    
    return topoSort;
}
/*
Time Complexity: O(V+E). 
The outer for loop will be executed V number of times and 
the inner for loop will be executed E number of times.
Auxiliary Space: O(V). 
The queue needs to store all the vertices of the graph. 
So the space required is O(V)

*/
//----------------------------------------------------------

// Method 2: Using DFS
#include<unordered_map>
#include<list>
#include<stack>
void topoSort(int node, vector<bool> &visited, stack<int>&s, 
              unordered_map<int, list<int>> &adj)
{
    // Mark the current node as visited.
    visited[node] = 1;
    
    // Recur for all the vertices
    // adjacent to this vertex 
    for(auto neighbour : adj[node])
    {
        if(!visited[neighbour])
            topoSort(neighbour, visited, s, adj);
    }
    
    // Push current vertex to stack
    // which stores result
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    // Make adj list
    unordered_map<int, list<int>> adj;
    for(int i=0; i<e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }
    
    vector<bool> visited(v); // by default false
    
    // call dfs topological sort until function for all components
    stack<int> s;
    for(int i=0; i<v; i++)
    {
        if(!visited[i])
            topoSort(i, visited, s, adj);
    }
    
    vector<int> ans;
    while(!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    
    return ans;
}
/*
Time Complexity: O(V+E). 
The above algorithm is simply DFS with an extra stack. 
So time complexity is the same as DFS which is.
Auxiliary space: O(V). 
The extra space is needed for the stack.
*/


