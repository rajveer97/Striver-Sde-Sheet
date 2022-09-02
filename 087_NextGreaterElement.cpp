#include<bits/stdc++.h>
// Method 1 : Use two loops
vector<int> nextGreater(vector<int> &arr, int n) {
    // Write your code here
    vector<int> ans(n, -1);
    ans[n-1] = -1;
    
    for(int i=0; i<n-1; i++)
    {
        for(int j = i+1; j<n;j++)
        {
            if(arr[i] < arr[j]) 
            {
                ans[i] = arr[j];
                break;
            }
        }
    }
    
    return ans;
}
// TC : O(N^2)


// Method 2 : Optimized approach
// Use stack
vector<int> nextGreater(vector<int> &arr, int n) {
    // Write your code here
    vector<int> nge(n, -1);
    stack<int> st;
    for(int i=n-1; i>=0; i--)
    {
        // untill the stack is not empty also top element is 
        // less then the current just pop the stack
        while(!st.empty() && st.top() <= arr[i])
        {
            st.pop();
        }
        
        // if the the above condn is end and stack is not empty
        if(!st.empty())
        {
            nge[i] = st.top();
        }
        
        // push element in stack
        st.push(arr[i]);
    }
    
    return nge;
}
// Time Complexity: O(N) 
// Auxiliary Space: O(N)