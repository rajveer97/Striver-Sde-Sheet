#include<bits/stdc++.h>
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // storing the frequencies of array eleement in the hashmap
    unordered_map<int, int> ump;
    for(int i=0; i<n; i++) 
    {
        ump[arr[i]]++;
    }
    
    // 1. create the priority queue(MAX-HEAP) of pair datatype to 
    // store the elements with their respectives frequencies
    // 2. we are using the MAX-HEAP so that maximum freq. element appear at the top
    priority_queue<pair<int, int>> pq;
    for(auto it : ump)
    {
        pq.push(make_pair(it.second, it.first));
    }
    
    // store K most frequent elements
    vector<int> ans;
    while(k--)
    {
        int temp = pq.top().second;
        pq.pop();
        ans.push_back(temp);
    }
    
    // if frequency of two elements is same for that we are sorting the ans vector 
    sort(ans.begin(), ans.end());
    return ans;
}
/*
TC : O(n log(n-k))
*/
