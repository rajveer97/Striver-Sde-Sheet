#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
    // This problem is a variation of "Dutch National flag Problem"
    int low = 0, mid = 0, high = n-1;
    // Iterate till the array become sorted array
    while(mid <= high) {
        switch(arr[mid]) {
            // If the element is 0
            case 0:
            {
                int temp = arr[mid];
                arr[mid] = arr[low];
                arr[low] = temp;
                mid++;
                low++;
                break;
            }
            // If the element is 1
            case 1:
            {
                mid++;
                break;
            }
            case 2:
            {
                int temp = arr[mid];
                arr[mid] = arr[high];
                arr[high] = temp;
                high--;
                break;
            }
            
        }
    }
}