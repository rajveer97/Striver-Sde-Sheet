// Method 0: Brute-force (LeetCode)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int lis[nums.size()];
        lis[0] = 1;
        for(int i = 1; i<nums.size(); i++) {
            lis[i] = 1;
            for(int j=0; j<i; j++) {
                if(nums[i] > nums[j] && lis[i] < lis[j] + 1)
                    lis[i] = lis[j] + 1;
            }
        }
        
        return *max_element(lis, lis + nums.size());
    }
};

//-----------------------------------------------------------

// Method 1: Recursion
class Solution {
public:
    int solve(int index, int prev_index, vector<int> &nums)
    {
        if(index == nums.size()) return 0;
        
        // Not Take
        int len = 0 + solve(index+1, prev_index, nums);
            
        // Take    
        if(prev_index == -1 || nums[index] > nums[prev_index]) 
            len = max(len, 1+solve(index+1, index, nums));
            
        
        return len;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        return solve(0, -1, nums);
    }
};

//------------------------------------------------------------------------------

// Method 2: Memoization
class Solution {
public:
    int solve(int index, int prev_index, vector<int> &nums,vector<vector<int>>& dp)
    {
        if(index == nums.size()) return 0;
        
        if(dp[index][prev_index+1] != -1)
            return dp[index][prev_index+1];
        
        // Not Take
        int len = 0 + solve(index+1, prev_index, nums, dp);
            
        // Take    
        if(prev_index == -1 || nums[index] > nums[prev_index]) 
            len = max(len, 1+solve(index+1, index, nums, dp));
            
        
        return dp[index][prev_index+1] = len;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int>> dp(n, vector<int> (n+1, -1)); //n+1,bcz we are shifting 1 prev_index 
        
        return solve(0, -1, nums, dp);
    }
};

//------------------------------------------------------------------------------

// Method 3: Tabulation DP
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        
        for(int index = n-1; index >= 0; index--)
        {
            for(int prev_index = index-1; prev_index >= -1; prev_index--)
            {
                // Not Take
                int len = 0 + dp[index + 1][prev_index + 1];

                // Take    
                if(prev_index == -1 || nums[index] > nums[prev_index]) 
                    len = max(len, 1 + dp[index + 1][index + 1]);


                dp[index][prev_index+1] = len;             
            }
        }
        
        
        return dp[0][-1+1];
    }
};


//-----------------------------------------------------------

// Optimized Solution: Binary Search
#include<vector>
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    vector<int> temp;
    temp.push_back(arr[0]);
    int len = 1;
    
    for(int i=1; i<n; i++)
    {
        if(arr[i] > temp.back())
        {
            temp.push_back(arr[i]);
            len++;
        }
        else 
        {
            int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[ind] = arr[i];
        }
    }
    
    return len;   
}
