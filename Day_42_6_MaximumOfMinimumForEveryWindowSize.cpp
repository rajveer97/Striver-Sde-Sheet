#include<stack>
#include<vector>
vector<int> maxMinWindow(vector<int> a, int n) {
    // Write your code here.
    vector<int> prevSmaller(n), nextSmaller(n);
    stack<int> st;
    vector<int> res(n+1, INT_MIN);
    
    for(int i=0; i<n; i++)
    {
        while(!st.empty() && a[st.top()] >= a[i])
            st.pop();
        
        if(st.empty())
            prevSmaller[i] = -1;
        else
            prevSmaller[i] = st.top();
        
        st.push(i);
    }
    
    while(!st.empty()) st.pop();
    for(int i=n-1; i>=0; i--)
    {
        while(!st.empty() && a[st.top()] >= a[i])
            st.pop();
        
        if(st.empty())
            nextSmaller[i] = n;
        else
            nextSmaller[i] = st.top();
        
        st.push(i);
    }    
    
    for(int i=0; i<n; i++)
    {
        int windowsSize = nextSmaller[i] - prevSmaller[i] - 1;
        res[windowsSize] = max(res[windowsSize], a[i]);
    }
    
    for(int i=n-1; i>=1; i--)
    {
        res[i] = max(res[i], res[i+1]);
    }
    
    vector<int> temp;
    copy(res.begin() + 1, res.end(), back_inserter(temp));
    
    return temp;
}
// TC - O(N)
