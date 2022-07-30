// Method 1: Recursion code
long solve(int index, int *denominations, int target)
{
    if(index < 0)
    {
        // one way possible
        if(target==0)
            return 1;
        // no way possible
        else 
            return 0;
    }
    
    //Adding 0 to the number of ways won't change the answer
    int take = 0; 
    int notTake = 0;
    
    if(denominations[index] <= target)
        take = solve(index, denominations, target-denominations[index]);
    
    notTake = solve(index-1, denominations, target);
    
    return take + notTake;
}

long countWaysToMakeChange(int *denominations, int n, int target)
{
    //Write your code here
    return solve(n-1, denominations, target);
}
/*
💡 Time complexity: *Exponential; Much more than $O(2^N)$*
- Because at every index, we have either 1 option or 
**more than** 2 options.

💡 Space complexity: $O(target)$
- Recursion stack space. In the worst case, we have to take 
target no. of 1 denomination coins.
*/


//-------------------------------------------------------------

// Method 2: Memoization code
#include<vector>
typedef long long ll;

ll solve(int index,int *denominations,int target,vector<vector<ll>> &dp)
{
    if(index < 0)
    {
        // One way possible
        if(target==0)
            return 1;
        // no way possible
        else
            return 0;
    }
    
    if(dp[index][target] != -1)
        return dp[index][target];
    
    ll take = 0;
    ll notTake = 0;
    
    if(denominations[index] <= target)
        take = solve(index, denominations, target-denominations[index], dp);
    
    notTake = solve(index-1, denominations, target, dp);
    
    return dp[index][target] = take + notTake;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    vector<vector<ll>> dp(n, vector<ll> (value+1, -1));
    return solve(n-1, denominations, value, dp);
}
/*
💡 Time complexity: O(N*target)
- Time needed to fill the N*target memory vector

💡 Space complexity: O(N*target) + O(target)
- Space needed for the N*target memory vector
- O(target) ⇒ recursion stack space
*/


//------------------------------------------------------------
// Method 3: Tabulation (Iterative)
#include<vector>

long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    vector<vector<long>> dp(n, vector<long> (value+1, 0));
    for(int t=0; t<=value; t++)
    {
        dp[0][t] = (t % denominations[0]==0);
    }
    
    for(int ind=1; ind<n; ind++)
    {
        for(int t=0; t<=value; t++)
        {
            long notTake = dp[ind-1][t];
            long take = 0;
            if(denominations[ind] <= t)
                take = dp[ind][t-denominations[ind]];
            
            dp[ind][t] = take + notTake;
        }
    }
    return dp[n-1][value];
}
/*
💡 Time complexity: O(N*target)
- Time needed to fill the $N*target$ memory vector

💡 Space complexity: O(N*target)
- Space needed for the N*target memory vector
*/

//------------------------------------------------------------

// Method 4: Sapce Optimization (DP)
#include<vector>
long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    vector<long> prev(value+1, 0), cur(value+1, 0);
    
    for(int t=0; t<=value; t++)
    {
        prev[t] = (t % denominations[0]==0);
    }
    
    for(int ind=1; ind<n; ind++)
    {
        for(int t=0; t<=value; t++)
        {
            long notTake = prev[t];
            long take = 0;
            if(denominations[ind] <= t)
                take = cur[t-denominations[ind]];
            
            cur[t] = take + notTake;
        }
        
        prev = cur;
    }
    return prev[value];
}
/*
💡 me complexity: $O(N*target)$
- Time needed to fill the $N*target$ memory vector

💡 Space complexity: O(target)
- Space needed for the `previousIndex` and `currentIndex` vectors
*/

