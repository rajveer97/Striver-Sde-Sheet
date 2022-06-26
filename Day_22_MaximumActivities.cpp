/*
Following are some standard algorithms that are Greedy algorithms. 
1) Kruskal’s Minimum Spanning Tree (MST)
2) Prim’s Minimum Spanning Tree
3) Dijkstra’s Shortest Path
4) Huffman Coding
*/

#include<bits/stdc++.h>

// A job has a start time, finish time and profit.
struct job {
    int start;
    int end;
};

// A utility function that is used for sorting
// activities according to finish time
bool cmp(struct job a, struct job b) {
    return (a.end < b.end);
}

int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    int n = start.size();
    struct job v[n];
    
    for(int i=0; i<n; i++) {
        v[i].start = start[i];
        v[i].end = finish[i];
    }
    // sort the array according to the finish time
    sort(v, v+n, cmp);
    
    // The first activity always gets selected
    int maxActivity = 1;
    int end = v[0].end;
    
    // Consider rest of the activities
    for(int i=1; i<n;i++) {
        // If this activity has start time greater than or
        // equal to the finish time of previously selected
        // activity, then select it
        if(v[i].start >= end) {
            end = v[i].end;
            maxActivity++;
        }
    }
    
    // maximum number of activities a single person can perform.
    return maxActivity; 
}
/*
Time Complexity: It takes O(n log n) time if input activities may not be sorted. It takes O(n) time when it is given that input activities are always sorted.
*/
