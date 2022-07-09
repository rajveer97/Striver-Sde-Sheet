#include<bits/stdc++.h>
/*
Method 1:
Naive solution:
Since we are given two sorted arrays, we can use the merging technique 
to get the final merged array. From this, we simply go to the k’th index.

int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    // Write your code here.
    int sorted[n+m];
    int i=0, j=0, b=0;
    while(i<m && j<n) {
        if(row1[i] < row2[j]) sorted[b++] = row1[i++];
        else sorted[b++] = row2[j++];
    }
    
    while(i < m) sorted[b++] = row1[i++];
    while(j < n) sorted[b++] = row2[j++];
    
    return sorted[k-1];
}
/*
Time Complexity: O(n) 
Auxiliary Space : O(m + n) 
---------------------------------------------------------------------------
*/


/*
Method 2:
Space Optimized Version of above approach: 
We can avoid the use of extra array.

int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    // Write your code here.
    int i=0, j=0, k_curr=0;
    
    // Keep taking smaller of the current
    // elements of two sorted arrays and
    // keep incrementing k_curr
    while(i<m && j<n)
    {
        if(row1[i] < row2[j]) {
            k_curr++;
            if(k==k_curr) 
                return row1[i];
            
            i++;
        }
        else {
            k_curr++;
            if(k==k_curr)
                return row2[j];
            
            j++;   
        }
    }
    
    // If array row2[] is completely traversed
    while(i<m) {
        k_curr++;
        if(k==k_curr) 
            return row1[i];
            
        i++;
    }
    
    // If array row1[] is completely traversed
    while(j < n) {
        k_curr++;
        if(k==k_curr)
            return row2[j];

        j++;  
    }  
}
/*
Time Complexity: O(k) 
Auxiliary Space: O(1)
------------------------------------------------------------
*/

/*
Optimized Approach : Binary Search
*/
int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    // Write your code here.
    if(n > m)
        return ninjaAndLadoos(row2, row1, n, m, k);
    
    int low = max(0, k-n), high = min(k, m);
    while(low <= high) {
        int cut1 = (low + high) >> 1;
        int cut2 = k-cut1;
        
        int l1 = (cut1==0)?INT_MIN : row1[cut1-1];
        int l2 = (cut2==0)?INT_MIN : row2[cut2-1];
        int r1 = (cut1==m)?INT_MAX : row1[cut1];
        int r2 = (cut2==n)?INT_MAX : row2[cut2];
        
        if(l1 <= r2 && l2 <= r1)
            return max(l1, l2);  
        else if(l1 > r2)
            high = cut1-1;
        else if(l2 > r1)
            low = cut1 + 1;
            
    }
    return 1;
}
/*
Time Complexity : log(min(m,n))

Reason: We are applying binary search in the array with minimum 
size among the two. And we know the time complexity of the 
binary search is log(N) where N is the size of the array. 
Thus, the time complexity of this approach is log(min(m,n)), 
where m,n are the sizes of two arrays.

Space Complexity: O(1)

Reason: Since no extra data structure is used, 
making space complexity to O(1).
*/