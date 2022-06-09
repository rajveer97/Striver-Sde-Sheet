#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
     pair<int, int> p;
    // Create a temp arr and initiallise it with 0;
	vector<int> v(n+1, 0);
    int mis, rep;
    
    int i = 0;
    while(i < n) {
        if(v[arr[i]] == 0) {
            v[arr[i]] = 1;
        }
        else if(v[arr[i]] == 1) {
            rep = arr[i];  // if v[arr[i]]==1 that means no. is repeating
        }
        i++;
    }
    
    for(int j = 1; j<=n; j++) {
        if(v[j] == 0) //if v[arr[i]]==0 that means no. is missing
            mis=j;
    }
    
    p.first = mis;
    p.second = rep;
    
    return p; 
}
