#include<bits/stdc++.h>
/*
Brute force: 
using two loops, and checking the remaining array for each 
element to find smaller. It has complexity of O(N^2) so it will 
fail on large TC. N ~10^5

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    vector<int> ans(n, -1);  
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[i] > arr[j]) 
            {
                ans[i] = arr[j];
                break;
            }               
        }
    }
    return ans;
}

/*
Optimal using stacks: 
for this input size, TC should be better than or equal to O(NlogN). 
There is an optimized ~O(N) approach using stacks. 
Take a stack with -1 as a single element. Traverse the array from 
right to left, then for each number, find the smaller number in 
stack, the way you do it is keep popping until you reach the 
smaller number, (that is why we used -1 as the first element 
of stack) then push this number to the result and push the current 
array element into the stack. At the end reverse the result and 
return it.
*/
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    
    for(int i=n-1; i>=0; i--)
    {
        int curr = arr[i];
        while(s.top() >= curr)
        {
            s.pop();
        }
        
        // ans is stack ka top
        ans[i] = s.top();
        
        s.push(curr);
    }
    
    return ans;
}
