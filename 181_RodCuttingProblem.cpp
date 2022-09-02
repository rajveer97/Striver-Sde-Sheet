// Method 1: Recursion
int solve(int index, int N, vector<int> &price)
{
    if(index == 0)
        return N * price[0];
    
    int notTake = 0 + solve(index-1, N, price);
    int take = INT_MIN;
    int rodLength = index + 1;
    if(rodLength <= N)
    {
        take = price[index] + solve(index, N - rodLength, price);
    }
    
    return max(take, notTake);
}

int cutRod(vector<int> &price, int n)
{
    // Write your code here.
    return solve(n-1,  n, price);
}


//------------------------------------------------------------

// Method 2: Memozation
int solve(int index, int N, vector<int> &price, vector<vector<int>> &dp)
{
    if(index == 0)
        return N * price[0];
    
    if(dp[index][N] != -1)  return dp[index][N];
    
    int notTake = 0 + solve(index-1, N, price, dp);
    int take = INT_MIN;
    int rodLength = index + 1;
    if(rodLength <= N)
    {
        take = price[index] + solve(index, N - rodLength, price, dp);
    }
    
    return dp[index][N] =  max(take, notTake);
}

int cutRod(vector<int> &price, int n)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int> (n+1, -1));
    return solve(n-1,  n, price, dp);
}

//-------------------------------------------------------------------

// Method 3: Bottom Up(DP)
int cutRod(vector<int> &price, int n)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int> (n+1, 0));
    
    for(int i=0; i<=n; i++)
        dp[0][i] = i * price[0];
    
    for(int index=1; index<n; index++)
    {
        for(int N=0; N<=n; N++)
        {
            int notTake = 0 + dp[index-1][N];
            int take = INT_MIN;
            int rodLength = index + 1;
            if(rodLength <= N)
            {
                take = price[index] + dp[index][N-rodLength];
            }

            dp[index][N] =  max(take, notTake);
        }
    }
    
    return dp[n-1][n];
}
