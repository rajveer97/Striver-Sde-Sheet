#include <bits/stdc++.h> 
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Brut-force
    int count = 1, lcs = 0;
    sort(arr.begin(), arr.end());
    
    for(int i=1; i<n; i++) {
        if(arr[i] == arr[i-1]+1)  count++;
        else if(arr[i] == arr[i-1]) continue;
        else {
            lcs = max(lcs, count);
            count = 1;
        }
    }
    
    return lcs > count ? lcs : count;
}