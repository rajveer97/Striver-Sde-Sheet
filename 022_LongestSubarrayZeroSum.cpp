#include <bits/stdc++.h> 
int LongestSubsetWithZeroSum(vector < int > arr) {
    int n = arr.size();
    int sum = 0, maxi = 0;
    unordered_map<int, int> m;
    
    for(int i=0; i<n; i++) {
        sum += arr[i];
        if(sum == 0) {
            maxi = i+1;
        }
        else {
            if(m.find(sum) != m.end()) {
                maxi = max(maxi, i-m[sum]);
            }
            else
                m[sum]=i;
        }
    }
    return maxi;
}