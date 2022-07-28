// Method 1: Recursive Approach 
int solve(vector<int> &values, vector<int> &weights, int n, int w)
{
    if(n==0 || w==0)
        return 0;
    
    if(weights[n-1] <= w)
        return max(values[n-1] + solve(values, weights,n-1, w-weights[n-1]), 
                   solve(values, weights,n-1, w));  
    else 
        return solve(values, weights,n-1, w);      
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    // Write your code here
    return solve(values, weights, n, w);   
}

//---------------------------------------------------------------------------

// Method 2: DP(Memoization)
#include<cstring>
int t[1002][1002];
int solve(vector<int> &values, vector<int> &weights, int n, int w)
{
    if(n==0 || w==0)
        return 0;
    
    if(t[n][w] != -1)
        return t[n][w];
    
    if(weights[n-1] <= w)
        return t[n][w] = max(values[n-1] + solve(values, weights,n-1, w-weights[n-1]), 
                                           solve(values, weights,n-1, w));    
    else 
        return t[n][w] = solve(values, weights,n-1, w);      
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    // Write your code here
    memset(t, -1, sizeof(t));
    
    return solve(values, weights, n, w);   
}

//------------------------------------------------------------------------

// Method 3:

