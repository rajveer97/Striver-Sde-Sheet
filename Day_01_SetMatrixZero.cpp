#include <bits/stdc++.h> 
void setZeros(vector<vector<int>> &matrix)
{
    int R = matrix.size();
    int C = matrix[0].size();
    
	vector<int> rows(R, 1);
    vector<int> cols(C, 1);
    
    for(int i = 0; i<matrix.size(); i++) {
        for(int j=0; j<matrix[0].size(); j++) {
            if(matrix[i][j] == 0) {
                rows[i] = 0;
                cols[j] = 0;
            }
        }
    }
    
    for(int i = 0; i<matrix.size(); i++) {
        for(int j=0; j<matrix[0].size(); j++) {
            if(rows[i]==0 || cols[j]==0) {
                matrix[i][j]=0;
            }
        }
    }
    
    
}