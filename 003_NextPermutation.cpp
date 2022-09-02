/*
Solution 1 : Using C++ in-built function
C++ provides an in-built function called next_permutation() 
which directly returns the lexicographically next greater 
permutation of the input.
*/

#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    //  Write your code here.
    next_permutation(permutation.begin(), permutation.end());
    
    return permutation;
} 
/*
Time Complexity: O(N*N!)
A permutation is each one of the N! possible arrangements the elements 
can take (where N is the number of elements in the range). 
Different permutations can be ordered according to how they compare 
lexicographically to each other
*/

//-------------------------------------------------------------------

// Solution 2 : 

vector<int> nextPermutation(vector<int> &permutation, int n)
{
    //  Write your code here.
    int k, l; // global variables
    for (k = n - 2; k >= 0; k--) 
    {
        // if found ASC order is found then keep the kth pointer there
        // and break the loop
        if (permutation[k] < permutation[k + 1]) 
        {
            break;
        }
    }
    
    // if the array is DSC then just reverese the array
    // completely and return it
    if (k < 0) 
    {
        reverse(permutation.begin(), permutation.end());
        return permutation;
    } 
    
    // if array is not DSC
    else 
    {
        // again taverse from end and try to find greater element then 
        // kth element 
        for (l = n - 1; l > k; l--) 
        {
            // if we able to find greater element between kth and end
            // then keep the lth pointer there and break the loop
            if (permutation[l] > permutation[k]) 
            {
                break;
            }
        } 
        
        // swap the lth element with the kth element
        swap(permutation[k], permutation[l]);
        
        // and last reverese the array from (k+1)th till the 
        //end of the array
        reverse(permutation.begin() + k + 1, permutation.end());
    }
    return permutation;
} 
/*
Time Complexity: For the first iteration backward, the second 
interaction backward and reversal at the end takes O(N) for each, 
where N is the number of elements in the input array. 
This sums up to 3*O(N) which is approximately O(N).

Space Complexity: Since no extra storage is required. 
Thus, its complexity is O(1).
*/
