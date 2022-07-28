// Method 1: Naive Solution Using Recursion
int solve(string s, string t, int m, int n)
{
    if(m==0 || n==0)
        return 0;
    
    if(s[m-1] == t[n-1])
        return 1 + solve(s, t, m-1, n-1);   
    else 
        return max(solve(s, t, m-1, n), solve(s, t, m, n-1));
}

int lcs(string s, string t)
{
    //Write your code here
    int ans = solve(s, t, s.size(), t.size());
    return ans;
}

//----------------------------------------------------------

// Method 2: Optimized Solution using DP(Memoization)
#include<vector>
int helper(int i,int j,string &str1,string &str2,vector<vector<int>> &dp){
    
    if(i<0 || j<0){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(str1[i]==str2[j]){
        return dp[i][j]=1+helper(i-1,j-1,str1,str2,dp);
    }
    else
    return dp[i][j]=max(helper(i-1,j,str1,str2,dp), 
                        helper(i,j-1,str1,str2,dp));
}
int lcs(string str1, string str2)
{
    //Write your code here
    int n=str1.size();
    int m=str2.size();
    vector<vector<int>> dp(n,vector<int>(m,-1));

    int ans=helper(n-1,m-1,str1,str2, dp);
    return ans;
}

//--------------------------------------------------------

// Method 3: Using Tabulation (DP) TOP-DOWN
#include<vector>
int lcs(string s, string t)
{
    //Write your code here
    int m = s.size();
    int n = t.size();
    vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
    
    for(int i=0; i<=m; i++)    // 0th row
        dp[i][0] = 0;
    
    for(int i=1; i<=n; i++)    // 0th column
        dp[0][i] = 0;
        
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(s[i-1] == t[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
            {
                dp[i][j] =  max(dp[i-1][j], dp[i][j-1]);
            }               
        }
    }
    
    return dp[m][n];
}

