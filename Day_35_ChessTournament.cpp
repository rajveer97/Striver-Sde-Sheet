#include<bits/stdc++.h>

/*
Solution 1: Brute Force (TLE)
Intuition: 
1. It’s required that we put all the C cows into our stalls. 
So for a start, let’s say we set the minimum distance = 1 and 
put them consecutively. These cows fit perfectly.

2. This is too close, so let’s increase our minimum distance a bit. 
Let’s increase the distance further to 2. 
We can again check that the cows can be accommodated. 

3. But we want to reduce the possibility of collision/fighting 
as much as possible, so we keep on increasing the minimum distance. 

bool isCompatible(vector<int> positions, int dist, int cows) {
    int n = positions.size();
    int k = positions[0];
    cows--;
    for(int i=1; i<n; i++) {
        if(positions[i] - k >= dist) {
            cows--;
            if(!cows) {
                return true;
            }
            k = positions[i];
        }     
    }
    return false;
}

// Variant of Agressive cow Problem
// n -> number of rooms in the hotel and c -> number of chess players
int chessTournament(vector<int> positions , int n ,  int c){
	sort(positions.begin(), positions.end());
    int maxDist = positions[n-1] - positions[0];
    int ans = INT_MIN;
    
    for(int d=1; d<=maxDist; d++)
    {
        bool possible = isCompatible(positions, d, c);  
        if(possible) {
            ans = max(ans, d);
        }
    }
    return ans;
}
/*
Time complexity: O(n* c)
Space Complexity: O(1)
---------------------------------------------------
*/


/*
Solution 2 : Binary Search            
*/
bool isPossible(vector<int> positions, int n, int cows, int minDist) {
    int cntCows = 1;
    int lastPlaced = positions[0];
    for(int i=1; i<n; i++) {
        
        // we are in the search of max dist b/w two cows to place them
        if(positions[i] - lastPlaced >= minDist)
        {
            cntCows++;
            lastPlaced = positions[i];
        }
    }
    
    // if cntCows is greater than given no. of cows then it means we can easily 
    // place the given cows else return false
    if(cntCows >= cows) 
        return true;
    
    return false;
}

int chessTournament(vector<int> positions , int n ,  int c){
    sort(positions.begin(), positions.end());
    
    int low = 1, high = positions[n-1] - positions[0];
    int ans = INT_MIN;
    
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        
        //with mid as a distance between rooms can be placed? yes then low=mid+1 cuz we want max dist possible
        if(isPossible(positions, n, c, mid)) {
            ans = mid;
            low = mid + 1;
        }
        //else h=mid-1 cant be placed with mid as a distance between them.
        else {
            high = mid - 1;
        }
    }
    
    // store and return the answer.
    return ans;
}
/*
Time Complexity: O(N*log(M)). 
Reason: For binary search in a space of M, O(log(M))  and for each search, we iterate over max N stalls to check. O(N).

Space Complexity: O(1)
*/
