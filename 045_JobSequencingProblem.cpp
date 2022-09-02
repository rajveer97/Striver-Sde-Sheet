/*
Approach:  The strategy to maximize profit should be to pick up jobs that offer higher profits. Hence we should sort the jobs in descending order of profit. Now say if a job has a deadline of 4 we can perform it anytime between day 1-4, but it is preferable to perform the job on its last day. This leaves enough empty slots on the previous days to perform other jobs.

Basic Outline of the approach:-

1. Sort the jobs in descending order of profit. 
2. If the maximum deadline is x, make an array of size x .
Each array index is set to -1 initially as no jobs have been performed yet.
3. For every job check if it can be performed on its last day.
4. If possible mark that index with the job id and add the profit to our answer. 
5. If not possible, loop through the previous indexes until an empty slot is found.
*/

#include<iostream>
#include<algorithm>
static bool cmp(vector<int> a, vector<int> b) {
    if(a[1] > b[1])
        return true;
    else
        return false;
}

int jobScheduling(vector<vector<int>> &jobs)
{
    //Sort the jobs in descending order of profit.
    sort(jobs.begin(), jobs.end(), cmp);
    int n = jobs.size();
    
    //count the maximum deadline
    int maxi = jobs[0][0];
    for(int i=0; i<n; i++) {
        maxi = max(maxi, jobs[i][0]);
    }
    
    int slot[maxi+1];
    //Each array index is set to -1 initially as no jobs 
    //have been performed yet.
    for(int i=0; i<=maxi; i++) {
        slot[i] = -1;
    }
    
    int profit = 0;
    
    //For every job check if it can be performed on its last day.
    //If possible mark that index with the job id and add the profit 
    //to our answer. 
    //If not possible, loop through the previous indexes until 
    //an empty slot is found.
    for(int i=0; i<n; i++)
    {
        for(int j=jobs[i][0]; j>0; j--)
        {
            if(slot[j]==-1)
            {
                profit = profit + jobs[i][1];
                slot[j]=i;
                break;
            }
        }
    }
    
    return profit;
}
/*
Time Complexity: O(N log N) + O(N*M).

O(N log N ) for sorting the jobs in decreasing order of profit. O(N*M) since we are iterating through all N jobs and for every job we are checking from the last deadline, say M deadlines in the worst case.

Space Complexity: O(M) for an array that keeps track on which day which job is performed if M is the maximum deadline available.
*/

