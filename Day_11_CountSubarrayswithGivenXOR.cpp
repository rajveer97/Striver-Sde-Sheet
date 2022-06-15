#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x)
{
    // Brut-force, TC -> O(N^2)
    /*
    int count = 0;
    for(int i=0; i<arr.size(); i++) {
        int sum = 0;
        for(int j=i; j<arr.size(); j++) {
            sum ^= arr[j];
            if(sum == x) count++;
        }
    }
    return count;
    */
    
    // OPtimized, TC -> O(N)
    map<int, int> m;
    int xr=0, count=0;
    for(int i=0; i<arr.size(); i++) {
        xr ^= arr[i];
        if(xr==x) count++;
        
        if(m.find(xr ^ x) != m.end())
            count += m[xr ^ x];
        
        m[xr]++;
    }
    return count;
}