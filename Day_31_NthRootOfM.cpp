/*
Solution:
Nth root of a number M is defined as a number X when raised 
to the power N equals to M.

Approach: In order to find the Nth root of any given 
integer we are gonna use Binary Search.

Step 1: Take low and high. Low will be equal to 1 and high 
will be M. We will take the mid of low and high such that the 
searching space is reduced using low + high / 2.

Step 2: Make a separate function to multiply mid N times.

Step 3: Run the while loop till (high – low > eps). 
Take eps as 1e-9, since we have to find answers to 9 decimal places.

Step 4:  If the mid is less than M, then we will reduce 
search space to low and mid. Else, if it is greater than M then 
search space will be reduced to mid and high.

Step 5: After the loop breaks we will have our answer as low or high.

We have to find the answer to 9 decimals. So, we will have a double 1e-9. 
We will run the while loop till (high – low > eps). 
When we will come out of the loop we will have the answer which will 
be equal to low as well as high.
*/
long double multiply(long double number, int n) {
    long double ans = 1.0;
    for(int i = 1; i <= n; i++)
    {
        ans *= number;
    }
    return ans; 
}

double findNthRootOfM(int n, long long m) {
    long double low = 1.0;
    long double  high = (long double)m;
    long double eps = 1e-9;
    
    while((high - low) > eps) {
        long double mid = low + (high - low) / 2.0;
        if(multiply(mid, n) > (long double)m) {
            high = mid; 
        }
        else {
            low = mid; 
        }
    }
        return low;
}
/*
Time Complexity: N x log(M x 10^d)
Space Complexity: O(1)
*/