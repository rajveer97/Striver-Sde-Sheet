#include<bits/stdc++.h>
/*
Optimal Approach :
Use Binary Search
*/
double median(vector<int> a, vector<int> b)
{
    // Write your code here.
    if (a.size() > b.size()) swap(a, b); // make sure a1 is shorter
        
    int n1 = a.size(), n2 = b.size();

    // range of a1 cut location: n1 means no right half for a1
    int lo = 0, hi = n1;
    while (lo <= hi) {
        int cut1 = (lo + hi)/2; // cut location is counted to right half
        int cut2 = (n1 + n2 )/2 - cut1;

        int l1 = cut1 == 0? INT_MIN : a[cut1-1];
        int l2 = cut2 == 0? INT_MIN : b[cut2-1];
        int r1 = cut1 == n1? INT_MAX : a[cut1];
        int r2 = cut2 == n2? INT_MAX : b[cut2];

        if (l1 > r2) hi = cut1-1; // A1's lower half is too big; need to move C1 left (C2 right)
        else if (l2 > r1) lo = cut1+1; // A2's lower half too big; need to move C2 left.
        else return (n1+n2)%2? min(r1,r2) : (max(l1,l2) + min(r1,r2))/2.; // Otherwise, that's the right cut.
    }

    return 0.0;
}
/*
TC : O(logN)
AS : O(1)
*/
