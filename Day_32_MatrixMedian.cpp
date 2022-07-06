#include<bits/stdc++.h>
// Brut-force
int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
     vector<int> v;
    int row = matrix.size();
    int col = matrix[0].size(); 
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            v.push_back(matrix[i][j]);
        }
    }
    
    sort(v.begin(), v.end());
    int ans = 0;
    if(v.size() % 2 != 0)       // [1, 3, 3, 6, 7, 8, 9]
        ans = v[v.size()/2];
    else ans = v[v.size()/2 + 1];
    
    return ans;
}
/*
TC : O(N^2)
AS : O(N*M)
*/
