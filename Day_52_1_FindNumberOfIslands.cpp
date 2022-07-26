// Method 1: UsingNormal Grid Traversal
void isIsland(int** arr, int x, int y, int n, int m)
{
    // Boundary conditions
    if(x<0 || y<0 || x>=n || y>=m || arr[x][y] != 1)
        return ;
    
    // mark current island as visited
    arr[x][y] = 2;
    
    isIsland(arr, x-1, y, n, m);    // up
    isIsland(arr, x+1, y, n, m);    // down
    isIsland(arr, x, y-1, n, m);    // left
    isIsland(arr, x, y+1, n, m);    // right
    isIsland(arr, x-1, y-1, n, m);  // up-left
    isIsland(arr, x-1, y+1, n, m);  // up-right
    isIsland(arr, x+1, y-1, n, m);  // down-left
    isIsland(arr, x+1, y+1, n, m);  // down-right
}

int getTotalIslands(int** arr, int n, int m)
{
    // Write your code here.
    int count = 0;
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(arr[i][j]==1)
            {   
                count++;             
                isIsland(arr, i, j, n, m);                
            }
        }
    }
    
    return count;
}

//--------------------------------------------------------

// Method 2: Using graph traversal technique (BFS)
#include<queue>
int dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, 
                 {0, -1}, {0, 1}, 
                 {1, -1}, {1, 0}, {1, 1}};

void bfs(int** arr, queue<pair<int, int>> &q, int n, int m)
{
    while(!q.empty())
    {
        auto curr = q.front();
        q.pop();
        
        for(int k = 0; k<8; k++)
        {
            int x = curr.first + dir[k][0];
            int y = curr.second + dir[k][1];
            
            if(x>=0 && y>=0 && x<n && y<m && arr[x][y]==1)
            {
                q.push({x, y});
                arr[x][y] = 0;
            }
        }
    }
}

int getTotalIslands(int** arr, int n, int m)
{
    // Write your code here.
    int count = 0;
    queue<pair<int, int>> q;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(arr[i][j] == 1)
            {
                count++;
                q.push({i, j});
                bfs(arr, q, n, m);
            }
        }
    }
    return count;
}