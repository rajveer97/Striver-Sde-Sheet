#include <bits/stdc++.h> 
int merge(vector<int> &arr, int low, int mid, int high) {
    int count = 0;
    int j = mid + 1;
    for(int i=low; i<=mid; i++) {
        while(j<=high && arr[i] > 2L*arr[j]) {
            j++;
        }
        count += (j-(mid + 1));
    }
    
    // merge 
    vector<int> temp;
    int left = low, right = mid+1;
    while(left <= mid && right <= high) {
        if(arr[left] <= arr[right]) {
            temp.push_back(arr[left++]);
        }
        else {
            temp.push_back(arr[right++]);
        }
    }
    
    while(left <= mid) {
        temp.push_back(arr[left++]);
    }
    
    while(right <= high) {
        temp.push_back(arr[right++]);
    }
    
    for(int i=low; i<=high; i++) {
        arr[i] = temp[i-low];
    }
    return count;
}

int mergeSort(vector<int> &arr, int low, int high) {
    if(low >= high) return 0;
    int mid = (low + high)/2;
    int val = mergeSort(arr, low, mid);
    val += mergeSort(arr, mid+1, high);
    val += merge(arr, low, mid, high);
    
    return val;
}

int reversePairs(vector<int> &arr, int n){
    // Similar to Count Inversion Problem
	return mergeSort(arr, 0, arr.size()-1);
}