/*
Bellman-Ford algorithm is a single-source shortest path algorithm, 
so when you have negative edge weight then it can detect negative cycles 
in a graph. The only difference between the two is that Bellman-Ford is 
also capable of handling negative weights whereas Dijkstra Algorithm can 
only handle positive
*/
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) 
{
    // Write your code here.
    vector<int> distance(n+1);
    // Step 1: Initialize distances from src to all other
    // vertices as INFINITE
    for(int i=0; i<=n; i++)
    {
        distance[i] = INT_MAX;
    }
    
    distance[src] = 0;
    
    // Step 2: Relax all edges |V| - 1 times. A simple
    // shortest path from src to any other vertex can have
    // at-most |V| - 1 edges
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<m; j++)
        {
            int u = edges[j][0]; // source
            int v = edges[j][1]; // destination
            int w = edges[j][2]; // weight
            if(distance[u] != INT_MAX && distance[u] + w < distance[v])
            {
                distance[v] = distance[u] + w;
            }
        }
    }
    
    if(distance[dest] == INT_MAX)
        return 1000000000;
    
    return distance[dest];    
}
// time complexity of Bellman-Ford is O(VE), which is more than Dijkstra. 