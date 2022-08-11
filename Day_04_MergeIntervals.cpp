/*
    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval
*/

#include <bits/stdc++.h> 
vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    vector<vector<int>> ans; // store the ans intervals
    
    // sort the intervals, it will easier for us to 
    //find overlapping intervals
    sort(intervals.begin(), intervals.end());
    
    // store the the first interval in a temp. vector 
    //to compare with the next interval while traversing
    vector<int> temp = intervals[0];
    
    // traverse the remaining intervals
    for(int i=1; i<intervals.size(); i++) {
        if(temp[1] >= intervals[i][0]) {
            temp[1] = max(intervals[i][1], temp[1]);
        }
        else {
            ans.push_back(temp);
            temp = intervals[i];
        }
    }
    ans.push_back(temp);  // store the last interaval
    return ans;
}
/*
TC : O(N * log N) 
*/

