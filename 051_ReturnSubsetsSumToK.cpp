#include<bits/stdc++.h>
void solve(int index,vector<int>& arr, int target,vector<int> &temp, vector<vector<int>> &ans ){
    if(index==arr.size()) {  
        if(target==0) 
            ans.push_back(temp);           
        return ;
    }
    
    solve(index+1, arr, target,temp,ans);     // element is not taken
    temp.push_back(arr[index]);
    solve(index+1, arr, target-arr[index],temp, ans); // element is taken
    
    temp.pop_back();  //backtracking
    }

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    //Write your code here
    vector<vector<int>> ans;
    vector<int> temp;
    solve(0, arr, k, temp, ans);
    
    return ans;
}