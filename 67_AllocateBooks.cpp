// Utility function to check if current minimum value
// is feasible or not.
bool isPossible(int n, int m, vector<int> days, long long int curr_min)
{
    int reqDays = 1;
    long long int curr_sum = 0;
    
    // iterate over all chapters
    for(int i=0; i<m; i++) {
        // check if current number of days are greater
        // than curr_min that means we will get the result
        // after mid no. of days
        if (days[i] > curr_min)
            return false;
        
        // count how many chapters are required
        // to distribute curr_min days
        if (curr_sum + days[i] > curr_min) {
            // increment student count
            reqDays++;
 
            // update curr_sum
            curr_sum = days[i];
 
            // if days required becomes greater
            // than given no. of chapters,return false
            if (reqDays > n)
                return false;
        }
 
        // else update curr_sum
        else
            curr_sum += days[i];
    }
    
    return true;
}

// n -> no. of days    m ->no. of chapters
// function to find minimum days
long long ayushGivesNinjatest(int n, int m, vector<int> days) 
{
    long long totalDays = 0;
    
    // return -1 if no. of chapters is less than
    // no. of days
    if(m < n) 
        return -1;
    
    // Count total number of days
    for(int i=0; i<days.size(); i++) {
        totalDays += days[i];
    }
    
    // initialize start as 0 time and end as
    // totalTimes
    long long start = 0;
    long long end = totalDays;
    long long ans = INT_MAX;
    
    // traverse until start <= end
    while(start <= end) {     
        // check if it is possible to distribute
        // chapters by using mid as current minimum
        long long mid = start + (end - start)/2;
        if(isPossible(n, m, days, mid)) {
            // update result to current distribution
            // as it's the best we have found till now.
            ans = mid;
            
            // as we are finding minimum and days
            // are sorted so reduce end = mid -1
            // that means
            end = mid-1;
        }
        else {
            // if not possible means pages should be
            // increased so update start = mid + 1
            start = mid + 1;
        }
    }
    
    // at-last return minimum no. of  days
    return ans;
}
/*
Time Complexity: O(N*log (M – max)), where N is the number of different books , max denotes the maximum number of pages from all the books and M denotes the sum of number of pages of all different books
Auxiliary Space: O(1)
*/
