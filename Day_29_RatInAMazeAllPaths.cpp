/*
Approach: Form a recursive function, which will follow a path 
and check if the path reaches the destination or not. 
If the path does not reach the destination then backtrack and try other paths. 

Algorithm:  

1. Create a solution matrix, initially filled with 0’s.
2. Create a recursive function, which takes initial matrix, 
output matrix and position of rat (i, j).
3. if the position is out of the matrix or the position is 
not valid then return.
4. Mark the position output[i][j] as 1 and check if the 
current position is destination or not. If destination is 
reached print the output matrix and return.
5. Recursively call for position (i-1,j), (I,j-1), 
(i+1, j) and (i, j+1).
6. Unmark position (i, j), i.e output[i][j] = 0.
*/
void completeMaze(vector<vector<int>> &res, vector<int> &visited, 
                  vector<vector<int>> &maze, int row, int col, int n) 
{
    if(row==n-1 && col==n-1) 
    {
        visited[row*n+col] = 1;
        res.push_back(visited);
        return;
    }
    
    if(row >= n || row < 0 || col >= n || col < 0 || 
       maze[row][col]==0 || visited[row*n+col]==1)
        return;
    
    visited[row*n+col] = 1;
    
    // Down
    completeMaze(res, visited, maze, row+1, col, n);
    
    //Up
    completeMaze(res, visited, maze, row-1, col, n);
    
    //Right
    completeMaze(res, visited, maze, row, col+1, n);
    
    //Left
    completeMaze(res, visited, maze, row, col-1, n);
    
    visited[row*n + col] = 0;  // Backtracking
    
}

vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  // Write your code here.
    vector<vector<int>> res;
    vector<int> visited(n*n, 0);
    
    completeMaze(res, visited, maze, 0, 0, n); 
    return res;
}
/*
Time Complexity: O(2^(n^2)). 
The recursion can run upper-bound 2^(n^2) times.
Space Complexity: O(n^2). 
Output matrix is required so an extra space of size n*n is needed.
*/

