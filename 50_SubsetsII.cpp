/*
Optimal:
1. Sort the input array.Make a recursive function that takes the input array ,
the current subset,the current index and  a list of list/ vector of vectors to 
contain the answer.
2. Try to make a subset of size n during the nth recursion call and consider elements 
from every index while generating the combinations. Only pick up elements that are appearing 
for the first time during a recursion call to avoid duplicates.
3. Once an element is picked up, move to the next index.
The recursion will terminate when the end of array is reached.
While returning backtrack by removing the last element that was inserted.

*/

#include<bits/stdc++.h>
void solve(int index, vector<int> ds, vector<vector<int>> &res, vector<int> &arr) {
    res.push_back(ds);
    
    for(int i=index; i<arr.size(); i++) {
        if(i != index && arr[i] == arr[i-1]) //if prev and curr elements are equal then skip 
            continue; 
        
            ds.push_back(arr[i]);      
            solve(i+1, ds, res, arr);
            ds.pop_back();              // backtracking
    }
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    vector<vector<int>> res;  // storing the result 
    vector<int> ds;           // helper vector
    
    // sort the array so the same numbers come together
    sort(arr.begin(), arr.end());
    solve(0, ds, res, arr);
    return res;
}
/*
Time Complexity: O(2^n) for generating every subset and O(k)  to insert every 
subset in another data structure if the average length of every subset is k. Overall O(k * 2^n).

Space Complexity: O(2^n * k) to store every subset of average length k. 
Auxiliary space is O(n)  if n is the depth of the recursion tree.
*/
