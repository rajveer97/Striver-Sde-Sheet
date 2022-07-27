// Method 1: DP Tabulation (LeetCode)
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
