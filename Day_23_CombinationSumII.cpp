/*
Approach:
1. Before starting the recursive call make sure to sort the elements because the ans should 
contain the combinations in sorted order and should not be repeated.

2. Initially, We start with the index 0, At index 0 we have n – 1 way to pick the first element 
of our subsequence.

3. Check if the current index value can be added to our ds. 
If yes add it to the ds and move the index by 1. while moving the index skip the 
consecutive repeated elements because they will form duplicate sequences.

4. Reduce the target by arr[i],call the recursive call for f(idx + 1,target – 1,ds,ans) after the call 
make sure to pop the element from the ds.(By seeing the example recursive You will understand).

5. if(arr[i] > target) then terminate the recursive call because there is no use to check as 
the array is sorted in the next recursive call the index will be moving by 1 all the elements 
to its right will be in increasing order.

Base Condition:
Whenever the target value is zero add the ds to the ans return.
*/

#include<bits/stdc++.h>
void solve(int idx, vector<vector<int>> &res, vector<int>&temp, vector<int>&arr, int n, int target)
{
    if(target==0) {
        res.push_back(temp);
        return;
    }
    
    for(int i=idx; i<n; i++) {
        if(i > idx && arr[i] == arr[i-1]) 
            continue;
        if(arr[i] > target) 
            break;
        temp.push_back(arr[i]);
        solve(i+1, res, temp, arr, n, target-arr[i]);
        temp.pop_back();
    }
    
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	// Write your code here.
    sort(arr.begin(), arr.end());
    vector<vector<int>> res;
    vector<int> temp;
    
    solve(0, res, temp, arr, n, target);
    
    return res;
}
/*
Time Complexity:O(2^n*k)
Reason: Assume if all the elements in the array are unique then the no. of subsequence 
you will get will be O(2^n). we also add the ds to our ans when we reach the base case 
that will take “k”//average space for the ds.

Space Complexity:O(k*x)
Reason: if we have x combinations then space will be x*k where k is the average length of 
the combination.
*/
