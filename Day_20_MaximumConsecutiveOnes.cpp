/*
Note:
Use sliding window technique

TC: O(n)
AS: O(1)
*/
int longestSubSeg(vector<int> &arr , int n, int k){
    int zeroCount = 0, ans = 0;
    
    for(int i=0, j = -1; i<n; i++) {
        // count the number of zeros
        if(arr[i]==0) {
            zeroCount++;
        }
        // as the zero's count becomes greater than k, 
        // move the jth index forward and decrease the zero's count
        // to maintain the window size
        while(zeroCount > k)
        {
            j++;
            if(arr[j]==0) {
                zeroCount--;
            }
        }
        // upadate the ans with the maximum window size
        ans = max(ans, i-j);   
    }
    
    return ans;
}
