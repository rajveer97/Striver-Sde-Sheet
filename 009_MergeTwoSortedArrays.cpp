#include <bits/stdc++.h> 
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
    // we will take 3 pointers 
    int p1 = m-1, p2 = n-1, i = m+n - 1;
    
    while(p2 >= 0) {
        if(p1 >= 0 && arr1[p1] >= arr2[p2]) {
            arr1[i--] = arr1[p1--];      // We will start fill the 1st arr from the end
        }
        else {
            arr1[i--] = arr2[p2--];
        }
    }
    
    return arr1;
}