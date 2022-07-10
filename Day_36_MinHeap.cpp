// for referece se Love Babbar lecture : https://www.youtube.com/watch?v=NKJnHewiGdc
class Heap {
    int arr[10000];
    int size;
    public:  
    // constructor
    Heap() {
        arr[0] = -1; // considered one base indexing
        size = 0;
    }
    
    public:
    void push(int val) {
        size++;  // increase the array size by one
        int index = size; // index will be same as the index number (last index)
        arr[index] = val; // store the element at the (last index)
        
        // put the element at the right position since it is a minHeap
        while(index > 1) {
            int parent = index/2;
            
            if(arr[parent] > arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else 
                return ;
        }
    }
    
    public:
    
    int pop() {
        if(size==0) return -1;
        
        //put store the element which we have to delete
        int deleteElement = arr[1];
        
        // put the last index element to the first index
        arr[1] = arr[size];
        
        // remove the last index
        size--;
        
        // take root at its correct position
        int i = 1;
        while(i<=size) {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;
            int parent = i;
            
            if(leftIndex <= size && arr[leftIndex] < arr[parent]) 
                parent  = leftIndex;
            
            if(rightIndex <= size && arr[parent] > arr[rightIndex])
                parent = rightIndex;
            
            if(i == parent) break;
            
            swap(arr[i], arr[parent]);
            i = parent;
        }
        return deleteElement;
    }
};

vector<int> minHeap(int n, vector<vector<int>>& q) {
    // Write your code here.
    vector<int> ans;
    Heap minHeap; // create minHeap
    
    for(auto it : q) {
        if(it[0]==0)
            minHeap.push(it[1]);
        
        else 
            ans.push_back(minHeap.pop()); // function returns element value
    }
    
    return ans;
}
/*
TC : 
push - O(logN), since it is store in the tree format and during 
                putting the element the right position, we compare 
                the curr index with its parent
pop - O(logN)
*/

