/*
A minimum spanning tree consists of N nodes and N-1 edges connecting 
all the nodes which have the minimum cost(sum of edge weights)
*/
#include<unordered_map>
#include<list>
#include<limits.h>
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
    // make adjacency list
    unordered_map<int, list<pair<int, int>>> adj;
    for(int i=0; i<g.size(); i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    // 1st index = 1st node
    vector<int> key(n+1);
    vector<bool> mst(n+1);
    vector<int> parent(n+1);
    
    // initilizing the key, mst and parent vector
    for(int i=1; i<=n; i++)
    {
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }
    
    // Now, Start Algo.
    key[1] = 0;
    parent[1] = -1;
    
    for(int i=1; i<n; i++)
    {
        int mini = INT_MAX;
        int u;
        
        // find the node with MIN value
        for(int v=1; v<=n; v++)
        {
            if(mst[v] == false && key[v] < mini)
            {
                u = v;
                mini = key[v];
            }
        }
        
        // mark min node true;
        mst[u] = true;
        // check adjacency nodes
        for(auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;
            if(mst[v]==false && w < key[v])
            {
                parent[v] = u;
                key[v] = w;
            }
        }
    }
    
    vector<pair<pair<int, int>, int>> result;
    for(int i=2; i<=n; i++)
    {
        result.push_back({{parent[i], i}, key[i]});
    }
    
    return result;
}
// Time Complexity: O(N^2). Going through N Node for N-1 times
// Space Complexity: O(N). 3 arrays of size N
