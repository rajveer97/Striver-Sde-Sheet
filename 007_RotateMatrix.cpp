#include <bits/stdc++.h> 
void rotateMatrix(vector<vector<int>> &mat, int rows, int columns)
{
    int rowDiv = rows/2;
    int colDiv = columns/2;
    int topLeft;
    
    for(int x=0, y=0; x<rowDiv && y<colDiv; x++, y++)
    {
        topLeft = mat[x][y];
        
        // bottom to up in left
        for(int row=x; row<rows-x-1; row++)
            mat[row][y] = mat[row+1][y];
        
        //right to left in bottom
        for(int col=y; col<columns-y-1; col++)
            mat[rows-x-1][col] = mat[rows-x-1][col+1]; 
        
        // top to bottom in right
        for(int row=rows-x-1; row>x; row--)
            mat[row][columns-y-1] = mat[row-1][columns-y-1];
        
        // left to right on top
        for(int col=columns-y-1; col>y; col--)
            mat[x][col] = mat[x][col-1];
        
        mat[x][y+1] = topLeft;
    }
}