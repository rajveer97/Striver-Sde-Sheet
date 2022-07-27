// Method 1 : Naive Approach
int maximumProduct(vector<int> &arr, int n)
{
    int result = arr[0];
  
    for (int i = 0; i < n; i++) 
    {
        int mul = arr[i];
        // traversing in current subarray
        for (int j = i + 1; j < n; j++) 
        {
            // updating result every time
            // to keep an eye over the maximum product
            result = max(result, mul);
            mul *= arr[j];
        }
        // updating the result for (n-1)th index.
        result = max(result, mul);
    }
    return result;
}
// TC : O(N^2)

//--------------------------------------------------------------

// Method 2 : Kadane's Algorithm
int maximumProduct(vector<int> &arr, int n)
{
    // Write your code here
    int ans = arr[0];
    int ma = ans;
    int mi = ans;
    
    for(int i=1; i<n; i++)
    {
        if(arr[i] < 0)
            swap(ma, mi);
        
        ma = max(arr[i], arr[i]*ma);
        mi = min(arr[i], arr[i]*mi);
        
        ans = max(ans, ma);
    }
    return ans;
}
// TC : O(N)
// SC : O(1)
