/*
Naive Method:
1. Sort both, arrival as well as departure time
2. If departure time of previous train is greater than or equal to 
arrival time of new train then we need to increase the platform no. otherwise we need to decrease the platform no.
3. Also upldate the result each time
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
TC: O(N)
AC: O(1)
*/
