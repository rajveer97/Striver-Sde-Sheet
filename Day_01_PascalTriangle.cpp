#include <bits/stdc++.h> 
vector<vector<long long int>> printPascal(int numRows) 
{
  vector<vector<long long int>> ans(numRows);
        
        for(int i = 0; i<numRows; i++) {
            // resizeing the  current row
            ans[i].resize(i+1);
            
            ans[i][0] = ans[i][i] = 1;  // fill  the first and last col with 1
            
            for(int j = 1; j<i; j++) {
                ans[i][j] = ans[i-1][j] + ans[i-1][j-1];
            }
            
        }
        
        return ans;
}
