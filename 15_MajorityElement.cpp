#include <bits/stdc++.h> 
int findMajorityElement(int arr[], int n) {
	unordered_map<int, int> m;
    for(int i=0; i<n; i++) {
        m[arr[i]]++;
    }
    int  halfNumber = n/2;
    int ans = -1;
    
    for(int i = 0; i<n; i++) {
       if(m[arr[i]] > halfNumber) {
           return arr[i];
       } 
    }
    return -1;
}