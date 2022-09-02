/*
Backtracking Approach:
1. Create a recursive function that takes the graph, 
current index, number of vertices, and output color array.
2. If the current index is equal to the number of vertices. 
Print the color configuration in output array.
3. Assign a color to a vertex (1 to m).
4. For every assigned color, check if the configuration is safe, 
(i.e. check if the adjacent vertices do not have the same color) 
recursively call the function with next index and number of vertices
5. If any recursive function returns true break the loop and return true.
6. If no recursive function returns true then return false.
*/

// check if the colored
// graph is safe or not
bool isSafe(int node, vector<int>&color, int n, vector<vector<int>>mat, int col)
{
    for(int k=0; k<n; k++)
    {
        if(k != node && mat[node][k] == 1 && color[k] == col) {
            return false;
        }
    }
    return true;
}

bool solve(int node, vector<int>&color, vector<vector<int>>&mat, int n, int m)
{
    /* base case: If all vertices are
       assigned a color then return true */
    if(node == n) 
        return true;
    
    /* Consider this vertex v and
       try different colors */
    for(int i=1; i<=m; i++) {
        
        /* Check if assignment of color
           c to v is fine*/
        if(isSafe(node, color, n, mat, i)) {
            color[node] = i;
            if(solve(node+1, color, mat, n, m)) {
                return true;
            } 
            
            /* If assigning color c doesn't
               lead to a solution then remove it */
            color[node] = 0;   // backtracking
        }
    }
    
    /* If no color can be assigned to
       this vertex then return false */
    return false;
}

// mat -> matrix,    m -> No.of colors
string graphColoring(vector<vector<int>> &mat, int m) {
    // Write your code here
    int n = mat.size();
    
    // Initialize all color values as 0.
    // This initialization is needed
    // correct functioning of isSafe()
    vector<int> color(n, 0);
    
    // Call solve() for vertex 0
    if(solve(0, color, mat, n, m))
        return "YES";
    else 
        return "NO";
}
/*
Time Complexity: O(m^V). 
There are total O(m^V) combination of colors. 
So time complexity is O(m^V). The upperbound time complexity 
remains the same but the average time taken will be less.

Space Complexity: O(V). 
Recursive Stack of graphColoring(…) function will require O(V) space.

*/
