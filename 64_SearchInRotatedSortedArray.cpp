/*
Naive Approach:

int search(int* arr, int n, int key) {
    int ans = -1;
    for(int i=0; i<n; i++) {
        if(arr[i]==key) {
            ans = i;
            break;
        }
    }
    
    return ans;
}
/*
TC : O(N^2)
AS : O(1)

-------------------------------------------------------------------------------
*/


/*
Optimal Approach : Binary Search

Find middle point mid = (l + h)/2
If key is present at middle point, return mid.
Else If arr[l..mid] is sorted
a) If key to be searched lies in range from arr[l]
to arr[mid], recur for arr[l..mid].
b) Else recur for arr[mid+1..h]
Else (arr[mid+1..h] must be sorted)
a) If key to be searched lies in range from arr[mid+1]
to arr[h], recur for arr[mid+1..h].
b) Else recur for arr[l..mid]
*/
int search(int* arr, int n, int key) {
    int lo = 0, hi = n-1;
    
    if(lo > hi) return -1;
    
    while(lo < hi) {
        int mid = (hi + lo) / 2;
        
        if(arr[mid]==key)  return mid; 
        
        if(arr[lo] <= arr[mid]) {
            if(arr[mid] > key && key >= arr[lo]) {
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }
        else {
            if (arr[mid] < key && key <= arr[hi]) {
                lo = mid+1;
            }
            else 
                hi = mid - 1;
        }
        
    }
    
    return arr[lo]==key ? lo : -1;
}
/*
Time Complexity: O(log n). 
Binary Search requires log n comparisons to find the element. So time complexity is O(log n).
Space Complexity: O(1). 
As no extra space is required.
*/
