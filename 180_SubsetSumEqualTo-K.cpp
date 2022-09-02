// Method 1: Recursion solution
bool solve(int index, int target, vector<int> &arr)
{
    if(target==0) return true;
    if(index == 0) 
        return target == arr[0];
    
    bool notTake = solve(index-1, target, arr);
    bool take = false;
    
    if(arr[index] <= target)
        take = solve(index-1, target-arr[index], arr);
    
    return take | notTake;    // | -> not
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    return solve(n-1, k, arr);
}

//---------------------------------------------------------------------

// Method 2: Memoization
bool solve(int index, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if(target==0) return true;
    if(index == 0) 
        return target == arr[0];
    
    if(dp[index][target] != -1)
        return dp[index][target];
    
    bool notTake = solve(index-1, target, arr, dp);
    bool take = false;
    
    if(arr[index] <= target)
        take = solve(index-1, target-arr[index], arr, dp);
    
    return dp[index][target] = take | notTake;    // | -> not
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>> dp(n, vector<int> (k+1, -1));
    return solve(n-1, k, arr, dp);
}

//-------------------------------------------------------------------------

// Method 3: Tabulation
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<bool>> dp(n, vector<bool> (k+1, 0));
    
    for(int i=0; i<n; i++)    dp[i][0] = true;
    
    dp[0][arr[0]] = true;
    
    for(int i=1; i<n; i++)
    {
        for(int target = 1; target<=k; target++)
        {
            bool notTake = dp[i-1][target];
            bool take = false;
            if(arr[i] <= target)
                take = dp[i-1][target-arr[i]];

            dp[i][target] = take | notTake;    // | -> not
        }
    }
    return dp[n-1][k];
}                                     
