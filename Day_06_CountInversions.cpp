// Approach 1 => Brute Force (TLE) 
#include <bits/stdc++.h> 
long long getInversions(long long *arr, int n){
    // Write your code here.
     int ans = 0;
    
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[i] > arr[j])
                ans++;
        }
    }
    
    return ans;
}
// o(n*2) & o(1)

//-----------------------------------------------------------------------

// Approach 2 => Using Merge Sort 
#include <bits/stdc++.h> 
long long res =  0;
void merge(long long *arr, long long l, long long m, long long r)
{
    long long n1 = m - l + 1, n2 = r - m;
    long long left[n1], right[n2];
    
    // Copying left elements in left array
    for(long long i=0; i<n1; i++)
        left[i] = arr[l+i];   
    
     // Copying Right elements in right array
    for(long long i=0; i<n2; i++)
        right[i] = arr[m+i+1];
    
    int i=0, j=0, k=l;
    
     // Merge 2 arrays
    while(i<n1 && j<n2)
    {
        if(left[i] <= right[j])
            arr[k++] = left[i++];
        else 
        {
            arr[k++] = right[j++];
            res += (n1-i);
        }
    }
    
    while(i < n1)
        arr[k++] = left[i++];
    
    while(j<n2)
        arr[k++] = right[j++];   
}

void mergeSort(long long *arr, long long l, long long r)
{
    // Base case
    if(l >= r)
        return ;
    
    long long m = (l + r)/2;
    mergeSort(arr, l, m);     // Sorting Left Part
    mergeSort(arr, m+1, r);   // Sorting Right Part
    merge(arr, l, m, r);      // Merge arrays
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    mergeSort(arr, 0, n-1);
    return res;
}

// TC: O(n*logn)
// SC: O(n)

//---------------------------------------------------------------------------

// Striver solution
long long merge(long long *arr, int left, int mid, int right) {
    int i, j, k;
    long long inv = 0;
    i = left;
    j =  mid;
    k = 0;
    int temp[(right - left + 1)];
    
    while((i <mid) || (j <= right)) {
        if(i<mid && j <= right) {
            if(arr[i] > arr[j]) {
                temp[k++] = arr[j++];
            	inv += (mid - i);
            }
        	else {
            	temp[k++] = arr[i++];
        	}
        }   
        else if(i < mid) {
            temp[k++] = arr[i++];
        }
        
       	else {
            temp[k++] = arr[j++];
       	}
  	}
		
    j=0;
    for(int i = left; i <=right; i++)
        arr[i] = temp[j++];

    return inv;
}

long long mergeSort(long long *arr, int low, int high) {
    long long inversion = 0; 
    if(low < high) {
    	int mid = low + (high - low)/2;
    	inversion += mergeSort(arr, low, mid);
    	inversion += mergeSort(arr, mid + 1, high);
    	inversion += merge(arr, low, mid + 1, high);
    }
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    long long ans = 0;
    return mergeSort(arr, 0, n-1); 
}