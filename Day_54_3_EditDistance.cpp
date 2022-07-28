// Method 1: Brute Force using Recursion
int solve(int i, int j, string str1, string str2)
{
    if(i<0) return j+1;
    if(j<0) return i+1;
    
    if(str1[i]==str2[j])
        return solve(i-1, j-1, str1, str2);
    else
        return 1 + min(solve(i-1, j-1, str1, str2), 
                min(solve(i-1, j, str1, str2), solve(i, j-1, str1, str2))) ;    
}

int editDistance(string str1, string str2)
{
    //write you code here
    int n = str1.size();
    int m = str2.size();
    
    return solve(n, m, str1, str2);
}

//------------------------------------------------------------------


// Method 2: DP(Memoization)
int solve(int i, int j, string &str1, string &str2, vector<vector<int>> &dp)
{
    if(i<0) return j+1;
    if(j<0) return i+1;
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    if(str1[i]==str2[j])
        return dp[i][j] = solve(i-1, j-1, str1, str2, dp);
    else
        return dp[i][j] = 1 + min(solve(i-1, j-1, str1, str2, dp), 
                          min(solve(i-1, j, str1, str2, dp), 
                              solve(i, j-1, str1, str2, dp)));  
}

int editDistance(string str1, string str2)
{
    //write you code here
    int n = str1.size();
    int m = str2.size();
    
    vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
    
    return solve(n, m, str1, str2, dp);
}


//-----------------------------------------------------------
// Method 3: DP(Top-down)


