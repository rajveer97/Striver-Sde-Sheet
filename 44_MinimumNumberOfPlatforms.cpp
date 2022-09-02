/*
Efficient Approach:
1. Store the arrival time and departure time in array arr and 
sort this array based on arrival time
2. Declare a priority queue(min-heap) and store the departure time 
of the first train and also declare a counter cnt and initialize it with 1.
3. Iterate over arr from 1 to n-1 
4. check if the arrival time of current train is less than or equals to 
the departure time of previous train which is kept on top of the priority queue
5. If true, then push the new departure time and increment the counter cnt
otherwise, we pop() the departure time
6. push new departure time in the priority queue
7. Finally, return the cnt.
*/

int calculateMinPatforms(int arr[], int dep[], int n) {
    // Store the arrival and departure time
    vector<pair<int, int> > arr2(n);
 
    for (int i = 0; i < n; i++) {
        arr2[i] = { arr[i], dep[i] };
    }
 
    // Sort arr2 based on arival time
    sort(arr2.begin(), arr2.end());
 
    priority_queue<int, vector<int>, greater<int> > p;
    int count = 1;
    p.push(arr2[0].second);
 
    for (int i = 1; i < n; i++) {
 
        // Check if arrival time of current train
        // is less than or equals to depature time
        // of previous train
        if (p.top() >= arr2[i].first) {
            count++;
        }
        else {
            p.pop();
        }
        p.push(arr2[i].second);
    }
 
    // Return the number of train required
    return count;
}
/*
Time Complexity: O(N*log(N))
Auxiliary Space: O(N)
*/



/*
Another Efficient Method:
Algorithm:

1. Sort the arrival and departure times of trains.
2. Create two pointers i=0, and j=0, and a variable 
to store ans and current count plat
3. Run a loop while i<n and j<n and compare the ith element of arrival array and 
jth element of departure array.
4. If the arrival time is less than or equal to departure then 
one more platform is needed so increase the count, i.e., plat++ and increment i
5. Else if the arrival time is greater than departure then one less platform is 
needed to decrease the count, i.e., plat– and increment j
6. Update the ans, i.e. ans = max(ans, plat).
*/

int calculateMinPatforms(int at[], int dt[], int n) {
    sort(at, at+n);
    sort(dt, dt+n);
    
    int platform_needed = 1, ans = 1, i=1, j=0;
    
    while(i<n && j<n) {
        if(at[i] <= dt[j]){
            platform_needed++;
            i++;
        }
        
        else {
            platform_needed--;
            j++;
        }
        
        if(platform_needed >= ans) {
            ans = platform_needed;
        }
    }
    return ans;
}
/*
Time Complexity: O(N * log N), One traversal O(n) of both 
the array is needed after sorting O(N * log N).
Auxiliary space: O(1), As no extra space is required.
*/
