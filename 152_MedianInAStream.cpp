// Method 1: 
#include<vector>
#include<algorithm>
vector<int> findMedian(vector<int> &arr, int n){
    // Write your code here 
    vector<int> ans;
    for(int i=0; i<n; i++)
    {
        int index = i+1;
        sort(arr.begin(), arr.begin()+i+1);
        if(index%2 != 0)
            ans.push_back(arr[index/2]);
        else
        {
            int mid = (arr[index/2 - 1] + arr[index/2])/2;
            ans.push_back(mid);
        }
    }
    
    return ans;
}
// TC : O(N logN)
// SC : O(N)

//--------------------------------------------------------

// Method 2: Using Priority Queue
#include<queue>
void balanceHeaps(priority_queue<int> &max_heap, 
                  priority_queue<int, vector<int>, greater<int>> &min_heap)
{
    // if no of element is odd,
    // then max_heap can have one extra element then min_heap.
    // max_heap <= 1+min_heap

    // So, if difference between the size of max_heap and 
    // min_heap gets more than one 
    // then balancing is required
    if(max_heap.size() - min_heap.size()==2)
    {
        min_heap.push((max_heap.top()));
        max_heap.pop();
    }
    // if no of element is even,
    // then min_heap can have less or equal element then max_heap.
    // min_heap <= max_heap

    // So, if size of min_heap gets more than max_heap size
    // then balancing is required
    else if(min_heap.size() - max_heap.size()==1)
    {
        max_heap.push(min_heap.top());
        min_heap.pop();
    }
}

void addNum(int num, priority_queue<int> &max_heap, 
            priority_queue<int, vector<int>, greater<int>> &min_heap)
{
    if(max_heap.empty() || num <= max_heap.top())
        max_heap.push(num);
    else
        min_heap.push(num);
    
    balanceHeaps(max_heap, min_heap);
}

vector<int> findMedian(vector<int> &arr, int n){
    // Write your code here 
    priority_queue<int> max_heap; // stores the smaller half
    priority_queue<int, vector<int>, greater<int>> min_heap; //stores the larger half
    vector<int> res;
    
    for(int i=0; i<n; i++)
    {
        addNum(arr[i], max_heap, min_heap);
        
        // if both heaps have equal elements the of of elements is even
        // so median is the average of top of min and max heap.
        if(max_heap.size()==min_heap.size())
            res.push_back((max_heap.top() + min_heap.top())/2);
        else //odd no of element
            res.push_back(max_heap.top());
    }
    
    return res;
}