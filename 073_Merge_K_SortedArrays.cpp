#include<bits/stdc++.h>
/*
Naive Approach: The very naive method is to create an output 
array of size n * k and then copy all the elements into the 
output array followed by sorting. 

Algorithm: 
1. Create a output array of size n * k.
2. Traverse the matrix from start to end and insert 
all the elements in output array.
3. Sort and print the output array.
*/


/*
Efficient solution : Use a heap data structure. 
The time complexity of the heap-based solution is O(N Log k).
1. Create an output array. 
2. Create a min-heap of size k and insert 1st element in 
all the arrays into the heap 
3. Repeat the following steps while the priority queue is not empty. 
…..a) Remove the minimum element from the heap 
(minimum is always at the root) and store it in the output array. 
…..b) Insert the next element from the array from which the element is extracted. 
If the array doesn’t have any more elements, then do nothing.
*/

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here.
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> ans;
    for(int i=0; i<kArrays.size(); i++) {
        for(int j=0; j<kArrays[i].size(); j++) {
            pq.push(kArrays[i][j]);
        }
    }
    
    while(!pq.empty()) {
        ans.push_back(pq.top());
        pq.pop();
    }
    
    return ans;    
}
/*
Time Complexity :O( n * k * log k), 
Insertion and deletion in a Min Heap requires log k time. 
So the Overall time complexity is O( n * k * log k)
Space Complexity :O(k), 
If Output is not stored then the only space required is the Min-Heap of k elements. 
So space Complexity is O(k).
*/
