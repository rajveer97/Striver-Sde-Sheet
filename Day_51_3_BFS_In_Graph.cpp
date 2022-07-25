#include<queue>
#include<algorithm>
#include<map>
#include<set>
void bfs(int vertex, map<int, set<int>> &adj_list, 
         vector<int> &visited, vector<int> &res)
{
    queue<int> q;
    q.push(vertex);
    
    while(!q.empty())
    {
        int currNode = q.front();
        q.pop();
        res.push_back(currNode);
        
        for(auto it : adj_list[currNode])
        {
            if(visited[it] == 0)
            {
                visited[it] = 1;
                q.push(it);
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    vector<int> res;
    vector<int> visited(vertex, 0);
    map<int,set<int>> adj_list;
    
    for(int i=0; i<edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adj_list[u].insert(v);
        adj_list[v].insert(u);
    }
    
    // traverse for each vertex
    for(int i=0; i<vertex; i++)
    {
        if(visited[i]==0)
        {
            visited[i] = 1;
            bfs(i, adj_list, visited, res);
        }
    }
    
    return res;
}