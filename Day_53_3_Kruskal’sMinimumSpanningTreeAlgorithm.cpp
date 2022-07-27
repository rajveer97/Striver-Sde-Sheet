// Method 1: Kruskal Algorithm - 
// Disjoint Set: Union & Find Brute(Without rank concept)
/*
A minimum spanning tree consists of N nodes and N-1 edges 
connecting all the nodes which have the minimum cost(sum of edge weights).
*/

#include<algorithm>
bool comp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}

int findPar(int u, vector<int> &par)
{
    //if reqd node present in set
    if(u == par[u])
        return u;  // parent found, return parent
    
    // recur for parent to find the absolute parent
    return par[u] = findPar(par[u], par);
}

int union_(int u, int v, vector<int> &par)
{
    // if both are part of same set
    if(findPar(u, par) == findPar(v, par)) 
        return 0; // union not possible
    
    // if anyone is out of bounds 
    else if(!(u>=0 && v>=0 && u<par.size() && v<par.size()))
        return 0; // union not possible
    
    par[u] = v; //save the better (more accurate) parent
}

int kruskalMST(int n, int m, vector<vector<int>> &edges) {
    // Write your code here.
    sort(edges.begin(), edges.end(), comp); // will iterate greedy
    
    vector<int> parent(n+1);
    for(int i=0; i<parent.size(); i++)
    {
        parent[i] = i;
    }
    
    int cost = 0;
    for(auto it : edges)
    {
        //if nodes are from diff sets
        if(findPar(it[0], parent) != findPar(it[1], parent))
        {
            // add the cost of the connection
            cost += it[2]; 
            // join them
            union_(findPar(it[0], parent), findPar(it[1], parent), parent);
        }        
    }
    
    return cost;
}
// Time Complexity: O(ElogE)+O(E*4*alpha), 
// ElogE for sorting and E*4*alpha for findParent operation ‘E’ times
// Space Complexity: O(N). Parent array+Rank Array
