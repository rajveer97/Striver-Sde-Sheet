#include <bits/stdc++.h> 
vector<int> majorityElementII(vector<int> &arr)
{
    vector<int> ans;
    unordered_map<int, int> m;
    
    for(int i=0; i<arr.size(); i++) {
        m[arr[i]]++;
    }
    
    int nByThree = arr.size()/3;
    for(auto it : m) {
        if(it.second > nByThree) 
            ans.push_back(it.first);
    }
    
    return ans;
}