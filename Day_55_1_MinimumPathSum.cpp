// Method 1: Memoization
#include<cstring>
#include<limits.h>
int t[101][101];
int solve(int i, int j, vector<vector<int>> &arr)
{
    if(i < 0 || j < 0 || i >= arr.size() || j >= arr[0].size())
        return INT_MAX;
    
    if(i == arr.size() - 1 && j == arr[0].size() - 1)
        return arr[i][j];
    
    if(t[i][j] != -1)
        return t[i][j];
    
    return t[i][j] = arr[i][j] + min(solve(i + 1, j, arr), 
                          solve(i, j + 1, arr));
}
int minSumPath(vector<vector<int>> &arr) {
    // Write your code here.
    int row = arr.size();
    int col = arr[0].size();
    
    memset(t, -1, sizeof(t));
    return solve(0, 0, arr);
}

//------------------------------------------------------------

// Method 2: DP ( Tabulation)
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n = grid.size();

    if(n==0)
        return 0;

    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int> (m, 0));

    dp[0][0] = grid[0][0];
    for(int i=1; i<n; i++)
        dp[i][0] = dp[i-1][0] + grid[i][0];

    for(int i=1; i<m; i++)
        dp[0][i] = dp[0][i-1] + grid[0][i];

    for(int i=1; i<n; i++)
    {
        for(int j=1; j<m; j++)
        {
            dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n-1][m-1];
}
