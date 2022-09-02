// Method 1: Recursion
bool isPalindrome(int i, int j, string str)
{
    while(i < j)
    {
        if(str[i] != str[j]) return false;
        i++;
        j--;
    }
    return true;
}

int solve(int i, int n, string str)
{
    if(i==n) return 0;
    int minCost = INT_MAX;
    for(int j=i; j<n; j++)
    {
        if(isPalindrome(i, j, str))
        {
            int cost = 1 + solve(j+1, n, str);
            minCost = min(minCost, cost);
        }
    }
    return minCost;
}

int palindromePartitioning(string str) {
    // Write your code here
    int n = str.size();
    
    return solve(0, n, str)-1;
}

//---------------------------------------------------------------------

// Method 2: Memoization
#include<vector>
bool isPalindrome(int i, int j, string str)
{
    while(i < j)
    {
        if(str[i] != str[j]) return false;
        i++;
        j--;
    }
    return true;
}

int solve(int i, int n, string str, vector<int> &dp)
{
    if(i==n) return 0;
    int minCost = INT_MAX;
    
    if(dp[i] != -1)
        return dp[i];
    
    // i......j
    for(int j=i; j<n; j++)
    {
        if(isPalindrome(i, j, str))
        {
            int cost = 1 + solve(j+1, n, str, dp);
            minCost = min(minCost, cost);
        }
    }
    return dp[i] =  minCost;
}

int palindromePartitioning(string str) {
    // Write your code here
    int n = str.size();
    vector<int> dp(n, -1);
    return solve(0, n, str, dp)-1;
}


//--------------------------------------------------------------

// Method 3: DP (Tabulation)
#include<vector>
bool isPalindrome(int i, int j, string str)
{
    while(i < j)
    {
        if(str[i] != str[j]) return false;
        i++;
        j--;
    }
    return true;
}

int palindromePartitioning(string str) {
    // Write your code here
    int n = str.size();
    vector<int> dp(n+1, 0);
    
    dp[n] = 0;
    
    for(int i=n-1; i>=0; i--)
    {
        int minCost = INT_MAX;   
        // i......j
        for(int j=i; j<n; j++)
        {
            if(isPalindrome(i, j, str))
            {
                int cost = 1 + dp[j+1];
                minCost = min(minCost, cost);
            }
        }
        dp[i] =  minCost;     
    }
      
    return dp[0]-1;
}
