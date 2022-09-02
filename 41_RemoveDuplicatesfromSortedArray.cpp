int removeDuplicates(vector<int> &arr, int n) {
    if(n==0) return 0;
    
    // if all the numbers in array are same 
    // then answer will be 1
    int count = 1;
    
    for(int i=0;i<n-1; i++) {
        if(arr[i] == arr[i+1]) {
            continue;
        }
        else count++;
    }
    return count;
    
}