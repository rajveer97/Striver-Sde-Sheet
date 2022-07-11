#include<bits/stdc++.h>
/*
// Naive Solution : (TLE)

void findMedian(int *arr, int n)
{
    // Write your code here
    vector<int> ans;
    for(int i=0; i<n; i++) {
        ans.push_back(arr[i]);
        sort(ans.begin(), ans.end());
        int median = -1;
        
         // at present no. of elements in ans array
        int n = ans.size();
        int mid = ans.size()/2;
        
        if(n%2 != 0) median = ans[mid];
        else median = (ans[mid-1] + ans[mid])/2;
        
        cout << median <<" ";
    }
    cout<<endl;
}
/*
TC : O(N)
AS : O(N)
*/

/*
Optimized Solution : Priority Queue(Heap)
*/
class MedianFinder {
public:
    priority_queue<int> maxq ;
    priority_queue<int, vector<int>, greater<int>> minq ;
    
    // add elements in the minq and maxq
    void addNum(int num) 
    {
        maxq.push(num);
        minq.push(maxq.top());
        maxq.pop();
        if(maxq.size()<minq.size())
        {
            maxq.push(minq.top());
            minq.pop();
        }
    }
    
    int findMedian() 
    {
         if(maxq.size()>minq.size())
        {
            return maxq.top();
        }
        else
        {
            return (maxq.top()+minq.top())/2;
        }
    }
};
void findMedian(int *arr, int n)
{
    MedianFinder* obj = new MedianFinder();

    // print the median of elements at each the we add a new elements
    for(int i=0;i<n;i++)
    {
       obj->addNum(arr[i]);
      cout<<obj->findMedian()<<" ";
    }
}
/*
TC : O(log N) since it takes logN time to push a element in the heap
AS : O(N)
*/
