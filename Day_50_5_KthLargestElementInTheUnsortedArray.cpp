#include<algorithm>
// Method 1: Sorting 
int kthLargest(vector<int>& arr, int size, int K)
{
    // Write your code here.
    sort(begin(arr), end(arr), greater<int>());
    return arr[K-1];
}

//-------------------------------------------------------

// Method 2: Using priority queue
#include<queue>
int kthLargest(vector<int>& arr, int size, int k)
{
    // Write your code here.
    priority_queue<int> pq;
    for(int i=0; i<n; i++)
    {
        pq.push(arr[i]);
    }
    for(int i=0; i<k-1; i++)
    {
        pq.pop();
    }
    return pq.top();  
}
