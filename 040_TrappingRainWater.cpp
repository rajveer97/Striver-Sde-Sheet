/*
Method 1:
1. Create 2 arrays - left and right.
2. Left[i] contains the max height before the index i.
3. Right[i] contains the max height after the index i.
4. After doing so , Traverse the array (given array) 
from index 1 to index n-2 (because the first and last elements 
won't be trapping any water).
5. In the traversal , calculate the minimum of left[i] and right[i] . 

6. Subtracting the current block's height (arr[i]) with 
this min value will give the water stored at that particular index (i). Add all these values to get the total water trapped.

 
Time Complexity of the Algorithm: O(N) + O(N) + O(N) = O(N)
Space Complexity: O(N) + O(N) = O(N)
*/

#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    long left[n];
    long right[n];
    left[0] = arr[0];
    right[n-1] = arr[n-1];
    
    for(int i=1; i<n; i++) {
        if(left[i-1] > arr[i])
            left[i] = left[i-1];
        else 
            left[i] = arr[i];
    }
    
    for(int i=n-2; i>=0; i--) {
        if(right[i+1] > arr[i])
            right[i] = right[i+1];
        else 
            right[i] = arr[i];
    }
    
    long water_trapped = 0;
    for(int i=1; i<n-1; i++) {
        long minHeight = min(left[i], right[i]);
        water_trapped += minHeight - arr[i];
    }
    return water_trapped;
}