// Brut-force Approch
#include <bits/stdc++.h> 
#include <vector>

bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
    
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(mat[i][j] == target)
                return true;
        }
    }
    return false;
}

// Optimized Approch
#include <bits/stdc++.h> 
#include <vector>

bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
    // Optimized approch
    int i = 0, j = n-1;
    
    while(i < m && j >= 0) {
        if(mat[i][j] == target) return true;
        else if(mat[i][j] > target) {
            j--;
        }
        else {
            i++;
        }
    }
    return false;
}

