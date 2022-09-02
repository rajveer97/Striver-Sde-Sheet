#include <bits/stdc++.h> 
int findDuplicate(vector<int> &arr, int n){
	vector<int> v(n+1, 0);
    int i = 0;
    while(i < n) {
        if(v[arr[i]] != 0)
            return arr[i];
        else 
            v[arr[i]]++;
        
        i++;
    }
    return -1;
}
