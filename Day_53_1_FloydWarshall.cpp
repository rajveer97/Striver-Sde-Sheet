/*
Floyd-Warshall Algorithm is an algorithm for finding the shortest path 
between all the pairs of vertices in a weighted graph. 
This algorithm works for both the directed and undirected weighted graphs.

Unlike Dijkstra's algorithm, Floyd Warshall can be implemented in a 
distributed system, making it suitable for data structures such as 
Graph of Graphs (Used in Maps). 
Lastly Floyd Warshall works for negative edge but no negative cycle, 
whereas Dijkstra's algorithm don't work for negative edges.
*/
int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    //Step 1: Initialize the shortest paths between any 2 vertices with Infinity.
    vector<vector<int>> dist(n+1, vector<int> (n+1, 1e9));
    
    for(auto edge : edges)
    {
        dist[edge[0]][edge[1]] = edge[2];
    }
    
    int i=1;
    // fill diagonal cells with 0, dist(A->A) = 0
    while(i <= n)
    {
        dist[i][i] = 0;
        i++;
    }
    
    for(int k = 1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(dist[i][k]==1e9 || dist[k][j]==1e9)
                    continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    return dist[src][dest];    
}
// TC : O(V^3)
// SC : O(V^2)