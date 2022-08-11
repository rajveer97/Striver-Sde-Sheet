// Use Kadane's Algorithm

#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    long long sum = 0;
    if(n==0) return 0;
    if(n==1) return arr[0];
    long long maxSum = 0;
    
    for(int i = 0; i<n; i++) {
        sum += arr[i];
        maxSum = max(sum, maxSum);
        
        if(sum < 0) {
            sum = 0;
        }
    }
    return maxSum; 
}
