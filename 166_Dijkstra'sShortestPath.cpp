/*
Dijkstra Algorithm is a graph algorithm for finding the shortest path 
from a source node to all other nodes in a graph(single-source shortest path). 
It is a type of greedy algorithm. 
It only works on weighted graphs with positive weights.
*/

// Method 1: Dijkstra's Algorithm
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<pair<int, int>> adj[vertices];
    for(int i=0; i<edges; i++)
    {
        adj[vec[i][0]].push_back({vec[i][1], vec[i][2]});
        adj[vec[i][1]].push_back({vec[i][0], vec[i][2]});
    }
    
    vector<int> distance(vertices, INT_MAX);
    distance[source] = 0;
    pq.push({0, source});  // (dist,source)
    while(!pq.empty())
    {
        int dist = pq.top().first;
        int topnode = pq.top().second;
        pq.pop();
        
        for(auto neighbour : adj[topnode])
        {
            if(dist + neighbour.second < distance[neighbour.first])
            {
                distance[neighbour.first] = dist + neighbour.second;
                pq.push({distance[neighbour.first], neighbour.first});
            }
        }
    }
    
    return distance;
}
// Time Complexity: O((N+E)*logN). 
// Going through N nodes and E edges and log N for priority queue
// Space Complexity: O(N). Distance array and priority queue

