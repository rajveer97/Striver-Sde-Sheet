// Method 1: Normal array
int uniquePaths(int m, int n) {
    int arr[m][n];
    for(int i=0; i<n; i++)   // 0th row
        arr[0][i] = 1;

    for(int i=0; i<m; i++)   // 0th col
        arr[i][0] = 1;

    for(int i=1; i<m; i++)
    {
        for(int j=1; j<n; j++)
        {
            arr[i][j] = arr[i-1][j] + arr[i][j-1];
        }
    }

    return arr[m-1][n-1];
}

//------------------------------------------------------

// Method 2: DP
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 1));
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}