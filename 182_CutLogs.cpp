// Egg Dropping Puzzle variant
// Method : DP with Binary Search
#include<cstring>
#include<limits.h>

int dp[101][10001];
int solve(int e, int f)
{
    if(f==1 || f==0)   
        return f;
    
    // if only one eggs is left , 
    // then in worst u have to check every floor
    if(e==1)   
        return f;
    
    if(dp[e][f] != -1) 
        return dp[e][f];
    
    // minimum no of trials needed (till having e eggs, f floors)
    // finding the critical floor
    int ans = INT_MAX;
    
    int lo = 1;
    int hi = f;
    
    while(lo <= hi)
    {
        int mid = (lo + (hi-lo)/2);
        
        // egg break at mid, floor left is mid-1
        int go_below = solve(e-1, mid-1);
        
        // egg not break, no of floor left is f-mid
        int go_above = solve(e, f-mid);
        
        // as we dont know egg will break or not
        // what we will do is we take the max no of trials 
        // from broken or not-broken
        int temp = 1 + max(go_above, go_below);
        
        if(go_above > go_below)
            lo = mid+1;
        else
            hi = mid-1;
        
        ans = min(ans, temp);           
    }
    return dp[e][f] = ans;    
}

int cutLogs(int k, int n)
{
    // Write your code here.
    // k->No. of Axes, n->Infinite amount of logs
    memset(dp, -1, sizeof(dp));
    return solve(k, n); 
}
