/*
Approach: 
Idea is to solve the problem using the greedy approach which is the same as Activity Selection Problem.

1. Sort all pairs(Meetings) in increasing order of 
second number(Finish time) of each pair.
2. Select first meeting of sorted pair as the first Meeting 
in the room and push it into result vector and set a variable 
time_limit(say) with the second value(Finishing time) of the 
first selected meeting.
3. Iterate from the second pair to last pair of the array and 
if the value of the first element(Starting time of meeting) of 
the current pair is greater then previously selected pair 
finish time (time_limit) then select the current pair and update 
the result vector (push selected meeting number into vector) and 
variable time_limit.
4. Print the Order of meeting from vector.
*/

#include<bits/stdc++.h>
using namespace std;

// Function for finding maximum meeting in one room
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    int n = end.size();
    pair<int, int> pairArr[n + 1];
    int i;
    for (i = 0; i < n; i++) {
        pairArr[i].first = end[i];
        pairArr[i].second = i;
    }
    // Sorting of meeting according to their finish time.
    sort(pairArr, pairArr + n);
 
    // Time_limit to check whether new
    // meeting can be conducted or not.
    int time_limit = pairArr[0].first;
 
    // Vector for storing selected meeting.
    vector<int> result;
 
    // Initially select first meeting.
    result.push_back(pairArr[0].second + 1);
 
    // Check for all meeting whether it
    // can be selected or not.
    for (i = 1; i < n; i++) {
        if (start[pairArr[i].second] > time_limit) {
            // Push selected meeting to vector
            result.push_back(pairArr[i].second + 1);
 
            // update time limit
            time_limit = pairArr[i].first;
        }
    }
    
    return result;
    
}