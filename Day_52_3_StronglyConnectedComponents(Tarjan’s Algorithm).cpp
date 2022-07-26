
// Method 1: Kosaraju's Algorithm
/*
Strongly Connected Components: A directed graph is called strongly connected if there is a path in 
each direction between each pair of vertices of the graph. That is, a path exists from the first 
vertex in the pair to the second, and another path exists from the second vertex to the first. 


/*There are 3 steps in kosaraju's algorithm
Step 1: Find the topo sort and keep it in the stack.
Step 2: Find the transpose of your graph basically if A->B is an edge we'll create B->A
Step 3: Run DFS now and get your answer of different strongly connected components.
*/
*/
#include<stack>
void dfsSort(int node, vector<int> adj[], vector<int> &vis, stack<int> &st)
{
    for(int adjNode : adj[node])
    {
        if(!vis[adjNode])
        {
            vis[adjNode] = 1;
            dfsSort(adjNode, adj, vis, st);
        }
    }
    
    st.push(node);
}

void revDFS(int node, vector<int> &vis, vector<int> adj[], vector<int> &comp)
{
    vis[node] = 1;
    comp.push_back(node);
    for(int adjNode : adj[node])
    {
        if(!vis[adjNode])
            revDFS(adjNode, vis, adj, comp);
    }
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // Write your code here.
    vector<int> adj[n];
    vector<int> vis(n, 0);
    vector<int> trans[n];
    stack<int> st;
    
    for(auto edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
    }
    
    // sort nodes based on finish time
    for(int i=0; i<n; i++)
    {
        if(!vis[i])
        {
            vis[i] = 1;
            dfsSort(i, adj, vis, st);
        }
    }
    
    // form a transpose graph 
    for(int i=0; i<n; i++)
    {
        vis[i] = 0;
        for(int node : adj[i])
        {
            trans[node].push_back(i);
        }
    }
    
    // reverse dfs
    // based on finish time nodes are sorted and stored in stack, 
    // and based on that sorted order, dfs traversal is called.
    vector<vector<int>> res;
    while(!st.empty())
    {
        int i = st.top();
        st.pop();
        if(!vis[i])
        {
            vector<int> comp;
            revDFS(i, vis, trans, comp);
            res.push_back(comp);
        }
    }
    
    return res;
}
/*
Time Complexity: 
The above algorithm calls DFS, finds reverse of the graph and again calls DFS. 
DFS takes O(V+E) for a graph represented using adjacency list. 
Reversing a graph also takes O(V+E) time. For reversing the graph, 
we simple traverse all adjacency lists. The above algorithm is 
asymptotically best algorithm, but there are other algorithms like 
Tarjan’s algorithm and path-based which have same time complexity 
but find SCCs using single DFS. 
*/


//--------------------------------------------------------------------
// GFG
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution
{
    void DFS(int u, vector<int> &disc, vector<int> &low, 
            stack<int> &mystack, vector<bool> &presentInStack, 
            vector<vector<int>> &ans, vector<int> adj[])
        {
            static int time = 0;
            disc[u] = low[u] = time;
            time += 1;
            mystack.push(u);
            presentInStack[u] = true;
            
            for(int v : adj[u])
            {
                if(disc[v] == -1) // if v is not visited
                {
                    DFS(v, disc, low, mystack, presentInStack, ans, adj);
                    low[u] = min(low[u], low[v]);
                }
                
                // Differentiate back-edge and cross-edge
                else if(presentInStack[v]) // Back-edge case
                {
                    low[u] = min(low[u], disc[v]);
                }
                
            }
            
            if(low[u] == disc[u]) // If u is head node of SCC
            {
                vector<int> v;
                while(mystack.top() != u)
                {
                    v.push_back(mystack.top());
                    presentInStack[mystack.top()] = false;
                    mystack.pop();
                }
                
                v.push_back(mystack.top());
                presentInStack[mystack.top()] = false;
                mystack.pop();
                sort(v.begin(), v.end());
                ans.push_back(v);
            }
        }
    
    
    public:
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
        //code here
        vector<int> disc(V, -1), low(V, -1);
        vector<bool> presentInStack(V, false); // Avoids cross-edgw
        stack<int> mystack;
        vector<vector<int>> ans;
        
        for(int i=0; i<V; ++i)
        {
            if(disc[i] == -1)
            {
                DFS(i, disc, low, mystack, presentInStack, ans, adj);
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};

// TC : O(V + E)

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for(int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends

