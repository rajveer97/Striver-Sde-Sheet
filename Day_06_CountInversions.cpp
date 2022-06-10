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
    return inversion;
}

long long getInversions(long long *arr, int n){
    long long ans = 0;
    return mergeSort(arr, 0, n-1); 
}