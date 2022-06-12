#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
	vector<vector<int>> v(m, vector<int> (n, 0));
    
    // fill last column with 1
    for(int i=0; i<m; i++) {
        v[i][n-1] = 1;
    }
    
    // fill last row with 1
    for(int i=0; i<n; i++) {
        v[m-1][i] = 1;
    }
    
    // fill the remaining spaces
    for(int i=m-2; i>=0; i--) {
        for(int j=n-2; j>=0; j--) {
            v[i][j] = v[i+1][j] + v[i][j+1];
        }
    }
    
    return v[0][0];
}