#include<bits/stdc++.h>
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
    // Write your code here.
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    vector<int> ans;
    
    // Kth smallest element of array
    for(int i=0; i<n; i++) {
        minHeap.push(arr[i]);
    }
    for(int i=1; i<=k-1; i++) {
        minHeap.pop();
    }
    ans.push_back(minHeap.top());
    
    // Kth largest element of array
    for(int i=0; i<n; i++) {
        maxHeap.push(arr[i]);
    }
    for(int i=1; i<=k-1; i++) {
        maxHeap.pop();
    }
    ans.push_back(maxHeap.top());
    
    return ans;
}
/*
Time complexity : push -> O(log N)
                  pop  -> O(log N)
*/
