bool isSafe(vector<vector<int>>&helper, int x, int y)
{
    int n = helper.size();
    for(int i=0;i<x;i++)
    {
        if(helper[i][y]==1)
            return false;
    }
    
    for(int i=x-1,j=y-1;i>=0&&j>=0;i--,j--)
    {
        if(helper[i][j]==1)
            return false;
    }
    for(int i=x-1,j=y+1;i>=0 && j<n;i--,j++)
    {
        if(helper[i][j]==1)
            return false;
    }
    return true; 
}

bool solve(vector<vector<int>>&ans, vector<vector<int>>&helper,int n, int index)
{
    if(index >= n) 
    {
        vector<int> temp;
        for(auto i : helper) 
            for(auto j : i)
                temp.push_back(j);
        ans.push_back(temp);
        return false;
    }
    for(int j = 0; j<n; j++) 
    {
        if(isSafe(helper, index, j))
        {
            helper[index][j] = 1;
            if(solve(ans, helper, n, index+1)== false)
                helper[index][j] = 0;
            else 
                return true;         
        }
    }
    
    return false;  
}

vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
    vector<vector<int>> helper(n, vector<int> (n, 0));
    vector<vector<int>> ans;
    solve(ans, helper, n, 0);   //
    
    return ans;
}
/*
Time Complexity: O(N!)

Auxiliary Space: O(N^2)
*/
