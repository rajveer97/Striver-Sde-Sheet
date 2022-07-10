#include<bits/stdc++.h>

/*
Naive Solution
*/
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
    // Write your code here.
    vector<int> ans;
    priority_queue<int> pq;
    
    // store the all combinations from all the possible sum combinations 
    // of the arrays ‘A’ and ‘B’.
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            pq.push(a[i] + b[j]);
        }
    }
    
    // store the max sum from the priority queue in the ans vector
    for(int i=1; i<=k; i++) {
        ans.push_back(pq.top());
        pq.pop();
    }
    
    return ans;
}
/*
Time complexity : O(N^2)
Space complexity : O(N)
*/