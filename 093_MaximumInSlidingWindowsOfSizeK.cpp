#include<vector>
#include<deque>
/*
Naive Approach: Use to loops 
TC : O(N*k)
*/

vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    // Write your code here.
    vector<int> ans;
    for(int i=0; i<=(nums.size()-k); i++)
    {
        int maxNum = nums[i];
        for(int j=1; j<k; j++)
        {
            maxNum = max(maxNum, nums[j+i]);
        }
        ans.push_back(maxNum);
    }
    return ans;
}



// Method 2: Use Deque data structue
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    // Write your code here.
    deque<int> dq;
    vector<int> ans;
    
    for(int i=0; i<nums.size(); i++)
    {
        if(!dq.empty() && dq.front()==i-k) // out of bound
            dq.pop_front();
        
        while(!dq.empty() && nums[dq.back()] <= nums[i])
            dq.pop_back();
        
        dq.push_back(i);
        
        if(i >= k-1)
            ans.push_back(nums[dq.front()]);
    }
    
    return ans;
}
/*
Time Complexity: O(n). 
It seems more than O(n) at first look. It can be observed that 
every element of array is added and removed at most once. 
So there are total 2n operations.

Auxiliary Space: O(k). 
Elements stored in the dequeue take O(k) space.
*/